// SPDX-License-Identifier: GPL-3.0-or-later
/*

player_profile_message_type   = 0x92,
 void __userpurge survarium::network_client::process_player_profile
match_wait_time_changed       = 0x9B

*/

struct __cppobj vostok::network_core::udp_match_connection : boost::noncopyable_::noncopyable
{
    vostok::network_core::udp_match_stats                                  m_stats;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
    >                                                                      m_packets_to_send;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
    >                                                                      m_outgoing_packets;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
    >                                                                      m_unacknowledged_packets;

    boost::array<
        vostok::network_core::udp_match_connection::channel,
        1
    >                                                                      m_channels;

    u32                                                                    m_pending_operations_count;
    vostok::network_core::udp_match_connection::state                      m_state;

    u16                                                                    m_remote_acknowledgement_bits;
    u16                                                                    m_received_local_acknowledgement_bits;
    sequence_number<u16>                                                   m_local_sequence_id;
    sequence_number<u16>                                                   m_remote_sequence_id;
    sequence_number<u16>                                                   m_received_local_sequence_id;
    sequence_number<u16>                                                   m_disconnection_local_sequence_id;
};


                            struct __cppobj vostok::network_core::udp_match_stats
                            {
                                uint32                                       max_local_sequence_difference;
                                int                                          unacknowledged_packets;
                            };

                            enum vostok::network_core::udp_match_connection::state : __int32
                            {
                                connected                = 0x0,
                                initiating_disconnection = 0x1,
                                confirming_disconnection = 0x2,
                                disconnected             = 0x3,
                            };


struct vostok::network_core::udp_match_connection::channel
{
    boost::intrusive::set<
        vostok::network_core::udp_match_packet,
    >                                                   packets;

    vostok::network_core::sequence_number<u16>          received_order_id; // init = FFFFF
 
    // Incremented for all packages which have `is_ordered` bit set.
    // This is currently all packets.
    vostok::network_core::sequence_number<u16>          sent_order_id;     // init = 0
};

// Initialization
{
udp_match_connection:
    this->m_remote_acknowledgement_bits     = 0x0000;
    this->m_received_local_acknowledgm_bits = 0x0000;
    this->m_local_sequence_id               = 0xFFFF;
    this->m_remote_sequence_id              = 0xFFFF;
    this->m_received_local_sequence_id      = 0xFFFF;

channel:
    this->received_order_id = 0xFFFF; 
    this->sent_order_id     = 0x0000; 
}

// After the first packet is sent
{
udp_match_connection:
    this->m_unacknowledged_packets          + packet;

    this->m_remote_acknowledgement_bits     = 0x0000;
    this->m_received_local_acknowledgm_bits = 0x0000;
    this->m_local_sequence_id               = 0x0000; // !
    this->m_remote_sequence_id              = 0xFFFF;
    this->m_received_local_sequence_id      = 0xFFFF;

channel:
    this->received_order_id = 0xFFFF; 
    this->sent_order_id     = 0x0001;  // !
}

// After the first packet is received
{
udp_match_connection:
    this->m_unacknowledged_packets          - packet;

    this->m_remote_acknowledgement_bits     = 0b1000_0000_0000_0000; // !
    this->m_received_local_acknowledgm_bits = 0b1000_0000_0000_0000; // !
    this->m_local_sequence_id               = 0x0000;
    this->m_remote_sequence_id              = 0x0000; // !
    this->m_received_local_sequence_id      = 0x0000; // !

channel:
    this->received_order_id = 0x0000;  // !
    this->sent_order_id     = 0x0001; 
}

// After the second packet is sent
{
udp_match_connection:
    this->m_unacknowledged_packets          + packet;

    this->m_remote_acknowledgement_bits     = 0b1000_0000_0000_0000;
    this->m_received_local_acknowledgm_bits = 0b1000_0000_0000_0000;
    this->m_local_sequence_id               = 0x0001; // !
    this->m_remote_sequence_id              = 0x0000;
    this->m_received_local_sequence_id      = 0x0000;

channel:
    this->received_order_id = 0x0000; 
    this->sent_order_id     = 0x0002;  // !
}

// After the second packet is received
{
udp_match_connection:
    this->m_unacknowledged_packets          - 0; // ???

    this->m_remote_acknowledgement_bits     = 0b1100_0000_0000_0000; // !
    this->m_received_local_acknowledgm_bits = 0b1000_0000_0000_0000; // ??? // !!!
    this->m_local_sequence_id               = 0x0001;
    this->m_remote_sequence_id              = 0x0001; // !
    this->m_received_local_sequence_id      = 0x0000; // ???

channel:
    this->received_order_id = 0x0001;  // !
    this->sent_order_id     = 0x0002; 
}


// 1. What XOR does
// 2. What is even the point of acknowledgment bits?

 void __thiscall vostok::network_core::udp_match_connection::update_acknowledgements(
    vostok::network_core::udp_match_connection *this,
    sequence_number<unsigned short> remote_sequence_id,
    sequence_number<unsigned short> local_sequence_id,
    unsigned __int16 local_acknowledgement_bits,
) {

 }


