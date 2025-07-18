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

#include "mmwave-iab-helper.h"

#include "ns3/log.h"
#include "ns3/mmwave-iab-node.h"

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("MmWaveIabHelper");

MmWaveIabHelper::MmWaveIabHelper()
{
    NS_LOG_FUNCTION(this);
    m_nodeFactory.SetTypeId("ns3::MmWaveIabNode");
}

MmWaveIabHelper::~MmWaveIabHelper()
{
    NS_LOG_FUNCTION(this);
}

NodeContainer
MmWaveIabHelper::Create(uint32_t n) const
{
    NS_LOG_FUNCTION(this << n);
    NodeContainer nodes;
    nodes.Create(n, m_nodeFactory);
    return nodes;
}

void
MmWaveIabHelper::SetNodeFactory(ObjectFactory factory)
{
    NS_LOG_FUNCTION(this << factory);
    m_nodeFactory = factory;
}

} // namespace ns3
