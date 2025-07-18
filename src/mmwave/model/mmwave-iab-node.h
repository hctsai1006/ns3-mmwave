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

#ifndef MMWAVE_IAB_NODE_H
#define MMWAVE_IAB_NODE_H

#include "ns3/node.h"

namespace ns3
{

/**
 * \ingroup mmwave
 *
 * \brief A node that can act as an IAB-node.
 */
class MmWaveIabNode : public Node
{
  public:
    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId(void);

    /**
     * Constructor
     */
    MmWaveIabNode();

    /**
     * Destructor
     */
    ~MmWaveIabNode() override;

  private:
    /**
     * \brief Initialize the node.
     */
    void DoInitialize(void) override;

    /**
     * \brief Dispose of the node.
     */
    void DoDispose(void) override;
};

} // namespace ns3

#endif /* MMWAVE_IAB_NODE_H */
