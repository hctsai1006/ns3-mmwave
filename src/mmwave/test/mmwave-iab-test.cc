/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2023 INESC TEC.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"
#include "ns3/mmwave-helper.h"
#include "ns3/mmwave-iab-helper.h"
#include "ns3/mobility-helper.h"
#include "ns3/point-to-point-helper.h"
#include "ns3/ipv4-address-helper.h"
#include "ns3/internet-stack-helper.h"
#include "ns3/applications-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("MmWaveIabTest");

class MmWaveIabTestCase : public TestCase
{
  public:
    MmWaveIabTestCase();
    virtual ~MmWaveIabTestCase();

  private:
    void DoRun(void) override;
};

MmWaveIabTestCase::MmWaveIabTestCase()
    : TestCase("MmWave IAB test case")
{
}

MmWaveIabTestCase::~MmWaveIabTestCase()
{
}

void
MmWaveIabTestCase::DoRun(void)
{
    // Create a new MmWaveHelper
    Ptr<MmWaveHelper> helper = CreateObject<MmWaveHelper>();

    // Create a new MmWaveIabHelper
    MmWaveIabHelper iabHelper;

    // Create a new NodeContainer for the gNB
    NodeContainer gnbContainer;
    gnbContainer.Create(1);

    // Create a new NodeContainer for the IAB nodes
    NodeContainer iabContainer = iabHelper.Create(1);

    // Create a new NodeContainer for the UEs
    NodeContainer ueContainer;
    ueContainer.Create(1);

    // Install the mobility model
    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(gnbContainer);
    mobility.Install(iabContainer);
    mobility.Install(ueContainer);

    // Install the internet stack
    InternetStackHelper internet;
    internet.Install(gnbContainer);
    internet.Install(iabContainer);
    internet.Install(ueContainer);

    // Install the mmWave devices
    NetDeviceContainer gnbDevs = helper->InstallEnbDevice(gnbContainer);
    NetDeviceContainer iabDevs = helper->InstallIabDevice(iabContainer);
    NetDeviceContainer ueDevs = helper->InstallUeDevice(ueContainer);

    // Attach the IAB node to the gNB
    helper->AttachToEnb(iabDevs.Get(0), gnbDevs.Get(0));

    // Attach the UE to the IAB node
    helper->AttachToEnb(ueDevs.Get(0), iabDevs.Get(0));

    // Assign IP addresses
    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer gnbInterfaces = address.Assign(gnbDevs);
    Ipv4InterfaceContainer iabInterfaces = address.Assign(iabDevs);
    Ipv4InterfaceContainer ueInterfaces = address.Assign(ueDevs);

    // Create a new UDP echo server application
    UdpEchoServerHelper echoServer(9);

    // Install the server on the gNB
    ApplicationContainer serverApps = echoServer.Install(gnbContainer.Get(0));
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    // Create a new UDP echo client application
    UdpEchoClientHelper echoClient(gnbInterfaces.GetAddress(0), 9);
    echoClient.SetAttribute("MaxPackets", UintegerValue(1));
    echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
    echoClient.SetAttribute("PacketSize", UintegerValue(1024));

    // Install the client on the UE
    ApplicationContainer clientApps = echoClient.Install(ueContainer.Get(0));
    clientApps.Start(Seconds(2.0));
    clientApps.Stop(Seconds(10.0));

    // Run the simulation
    Simulator::Run();

    // Destroy the simulation
    Simulator::Destroy();
}

static class MmWaveIabTestSuite : public TestSuite
{
  public:
    MmWaveIabTestSuite()
        : TestSuite("mmwave-iab", UNIT)
    {
        AddTestCase(new MmWaveIabTestCase, TestCase::QUICK);
    }
} g_mmwaveIabTestSuite;
