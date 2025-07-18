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

#ifndef MMWAVE_IAB_HELPER_H
#define MMWAVE_IAB_HELPER_H

#include "ns3/node-container.h"
#include "ns3/object-factory.h"

namespace ns3
{

class MmWaveIabHelper
{
  public:
    /**
     * Constructor
     */
    MmWaveIabHelper();

    /**
     * Destructor
     */
    ~MmWaveIabHelper();

    /**
     * \brief Create a number of IAB nodes.
     *
     * \param n the number of nodes to create
     * \return a container with the created nodes
     */
    NodeContainer Create(uint32_t n) const;

    /**
     * \brief Set the factory to use to create the nodes.
     *
     * \param factory the factory to use
     */
    void SetNodeFactory(ObjectFactory factory);

  private:
    ObjectFactory m_nodeFactory;
};

} // namespace ns3

#endif /* MMWAVE_IAB_HELPER_H */
