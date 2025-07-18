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

#include "mmwave-iab-node.h"

#include "ns3/log.h"

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveIabNode");

NS_OBJECT_ENSURE_REGISTERED(MmWaveIabNode);

TypeId
MmWaveIabNode::GetTypeId(void)
{
    static TypeId tid = TypeId("ns3::MmWaveIabNode").SetParent<Node>().SetGroupName("MmWave");
    return tid;
}

MmWaveIabNode::MmWaveIabNode()
{
    NS_LOG_FUNCTION(this);
}

MmWaveIabNode::~MmWaveIabNode()
{
    NS_LOG_FUNCTION(this);
}

void
MmWaveIabNode::DoInitialize(void)
{
    NS_LOG_FUNCTION(this);
    Node::DoInitialize();
}

void
MmWaveIabNode::DoDispose(void)
{
    NS_LOG_FUNCTION(this);
    Node::DoDispose();
}

} // namespace ns3
