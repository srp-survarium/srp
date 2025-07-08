/*
 * Different notes on how match client is implemented.
 */


/*
survarium::match_client
    -> vostok::network::match_client                + survarium::match_options  + survarium::game_mode_type
    -> vostok::network::match_client_impl           + m_on_connected            + m_on_packet_received
    -> vostok::network_core::udp_match_client       + m_on_connected            + m_on_packet_received          + vostok::network::match_client_impl::state
    -> vostok::network_core::udp_match_connection   + m_packets_to_send         + m_outgoing_packets            + vostok::network_core::udp_match_connection::state
    -* vostok::network_core::udp_match_packet


survarium::match_client::enqueue
    -> vostok::network::match_client::enqueue
    -> enqueue_impl
    -> vostok::network_core::udp_match_client::enqueue
    -> vostok::network_core::udp_match_connection::enqueue
+   -> vostok::network_core::udp_match_connection::enqueue_impl


survarium::match_client::send_queued_packets
    -> match_client::send_queued_packets
    -> match_client_impl::send_queued_packets
    -> udp_match_client::send_queued_packets
    -> udp_match_connection::send_queued_packets
    -> udp_match_connection::send_packets_list
    -> udp_match_connection::send


survarium::match_client::connect
    -> vostok::network::match_client::connect                   + vostok::network::match_client::on_connected
    -> vostok::network::match_client_impl::connect                                                              | called at network_world::process_orders
    -> vostok::network_core::udp_match_client::connect          + vostok::network_core::udp_match_connection::send_queued_packets
    -> vostok::network_core::udp_match_connection::connect
    -> vostok::network_core::udp_match_connection::enqueue_impl

survarium::match_client::disconnect
    -> vostok::network::match_client::disconnect
    -> vostok::network::match_client_impl::disconnect
    -> vostok::network_core::udp_match_client::disconnect
    -> vostok::network_core::udp_match_connection::disconnect


void __thiscall vostok::network_core::udp_match_connection::send_queued_packets(
    // THERE IS SOME LOGIC WHEN PACKET BEING SENT HAS ID SMALLER THEN PACKET ALREADY RECEIVED
    -> if ( vostok::network_core::sequence_number<unsigned short>::operator<=(&test, &thisa->m_received_local_sequence_id) )
    -> v16 = vostok::network_core::udp_match_packet::header_size(packets_list);
    -> vostok::network_core::udp_match_connection::send_packets_list(thisa, packets_list, v73);

send_packets_list:
    -> vostok::network_core::udp_match_connection::fill_packet_header(thisa, packets_list);
    -> vostok::network_core::udp_match_connection::send(thisa, packets_list);


// The first callback set for UDP socket in boost
void __thiscall vostok::network_core::udp_match_client::handle_receive

*/

/*
 *
 *
 */
survarium::match_client
{
    vostok::network::match_client                       m_client;

    survarium::network_packets_orderer<
        enum vostok::match_client_message_types_enum,
        enum vostok::match_server_message_types_enum,
    >                                                   m_packets_orderer;

    survarium::match_options                            m_match_options;
    uint32                                              m_last_send_queed_packets_time_in_ms;
    bool                                                m_are_there_any_packets_to_send;
}


                            struct survarium::match_options
                            {
                                survarium::player_profile player_profiles[20];
                                uint32                    match_id;
                                uint8                     map_id;
                                survarium::game_mode_type match_mode_;
                                uint8                     players_count;
                                uint8                     respawn_time;
                                uint16                    match_time;
                                float                     wait_player_percent;
                                uint8                     wait1_time;
                                uint8                     wait2_time;
                                uint8                     countdown_time;
                                uint8                     victory_items_count;
                                uint8                     received_players_count;
                                char                      map_name[32];
                            }

                                                    enum survarium::game_mode_type : __int32 {
                                                        capture_enemy_base   = 0x0,
                                                        capture_neutral_base = 0x1,
                                                        gather_victory_items = 0x2,
                                                        invalid_game_mode    = 0xFF,
                                                    };


/*
 *
 *
 */
struct vostok::network::match_client : vostok::core::noncopyable
{
    vostok::intrusive_ptr<
        vostok::network_core::udp_match_packets_allocator,
        vostok::network_core::udp_match_packets_allocator,
        vostok::threading::multi_threading_policy,
    >                                                       m_order_packets_allocator;

    vostok::intrusive_ptr<
        vostok::network_core::udp_match_packets_allocator,
        vostok::network_core::udp_match_packets_allocator,
        vostok::threading::multi_threading_policy,
    >                                                       m_response_packets_allocator;

    vostok::network_core::udp_match_stats                   m_stats;

    boost::function<
        void __cdecl(
            enum vostok::connection_error_types_enum,
            enum vostok::handshaking_error_types_enum,
            enum vostok::socket_error_types_enum,
            enum vostok::lobby_server_message_types_enum,
        )
    >                                                       m_on_connected;

    boost::function<
        void __cdecl(
            unsigned char,
            vostok::network_core::packet_reader &
        )
    >                                                       m_on_packet_received;

    boost::function<
        void __cdecl(
            enum vostok::network_core::disconnect_event_types_enum
        )
    >                                                       m_on_disconnected;

    vostok::network_core::udp_match_packets_orderer         *m_packets_orderer;
    vostok::network::network_world                          *m_world;
    vostok::network::match_client_impl                      **m_client;
};

/*
 *
 *
 */
struct vostok::network::match_client_impl
{
    boost::array<char [300],8192>                           m_packets_storage;
    vostok::memory::single_size_buffer_allocator<
        300,
        vostok::threading::single_threading_policy
    >                                                       m_packets_allocator;

    boost::function<
        void __cdecl(
            enum vostok::network_core::disconnect_event_types_enum
        )
    >                                                       m_on_disconnect;
    vostok::network_core::udp_network_flow_emulator         *m_network_flow_emulator;
    vostok::network_core::udp_match_client                  m_client;
    boost::function<
        void __cdecl(
            enum vostok::connection_error_types_enum,
            enum vostok::handshaking_error_types_enum,
            enum vostok::socket_error_types_enum,
            enum vostok::lobby_server_message_types_enum,
        )
    >                                                       m_on_connected;
    boost::function<
        void __cdecl(
            unsigned char,
            vostok::network_core::packet_reader &,
        )
    >                                                       m_on_packet_received;
    vostok::network::match_client_impl::state               m_state;
};

                            enum vostok::network::match_client_impl::state : __int32
                            {
                                waiting_for_permission = 0x0,
                                handshaked             = 0x1,
                            };

/*
 *
 *
 */
struct __cppobj vostok::network_core::udp_match_client : boost::noncopyable_::noncopyable
{
    vostok::network_core::udp_match_connection              m_connection;

    boost::function<
        void __cdecl(
            unsigned char,
            vostok::network_core::packet_reader &,
        )
    >                                                       m_on_packet_received;

    boost::function<
        void __cdecl(
            enum vostok::network_core::disconnect_event_types_enum,
        )
    >                                                       m_on_disconnect;

    vostok::timing::timer                                   m_timer;
    boost::asio::basic_datagram_socket<
        boost::asio::ip::udp,
        boost::asio::datagram_socket_service<boost::asio::ip::udp>,
    >                                                       m_socket;

    boost::asio::ip::basic_endpoint<boost::asio::ip::udp>   m_server_endpoint;

    boost::asio::ip::basic_endpoint<boost::asio::ip::udp>   m_remote_endpoint;

    boost::asio::io_service                                 *m_io_service;

    vostok::memory::single_size_buffer_allocator<
        300,
        vostok::threading::single_threading_policy,
    >                                                       *m_packets_allocator;

    vostok::network_core::udp_network_flow_emulator         *const m_network_flow_emulator;
    unsigned int                                            m_time_in_ms;
    bool                                                    m_is_receiving;
    boost::array<unsigned char,256>                         m_receive_buffer;
    vostok::network_core::handler_allocator                 m_handler_allocator;
};


/*
 *
 *
 */
struct __cppobj vostok::network_core::udp_match_connection : boost::noncopyable_::noncopyable
{
    vostok::network_core::udp_match_stats                                  m_stats;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
        vostok::network_core::udp_match_packet *,
        28,
        vostok::threading::single_threading_policy,
        vostok::size_policy,
        vostok::no_debug_policy
    >                                                                      m_packets_to_send;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
        vostok::network_core::udp_match_packet *,
        28,
        vostok::threading::single_threading_policy,
        vostok::size_policy,
        vostok::no_debug_policy
    >                                                                      m_outgoing_packets;

    vostok::intrusive_list<
        vostok::network_core::udp_match_packet,
        vostok::network_core::udp_match_packet *,
        28,
        vostok::threading::single_threading_policy,
        vostok::size_policy,
        vostok::no_debug_policy
    >                                                                      m_unacknowledged_packets;

    boost::array<
        vostok::network_core::udp_match_connection::channel,
        1
    >                                                                      m_channels;

    boost::function<
        void __cdecl(
            enum vostok::network_core::disconnect_event_types_enum
        )
    >                                                                      m_on_disconnect;

    boost::asio::basic_datagram_socket<
        boost::asio::ip::udp,
        boost::asio::datagram_socket_service<boost::asio::ip::udp>
    >*                                                                     m_socket;

    const boost::asio::ip::basic_endpoint<
        boost::asio::ip::udp
    >*                                                                     m_remote_endpoint;

    vostok::memory::single_size_buffer_allocator<
        300,
        vostok::threading::single_threading_policy
    >*                                                                     m_packets_allocator;

    vostok::network_core::udp_match_packets_orderer*                       m_packets_orderer;
    const char*                                                            m_logging_id;

    volatile int                                                           m_last_receive_time_in_ms;
    const unsigned int                                                     m_disconnection_timeout_in_ms;
    unsigned int                                                           m_last_send_time_in_ms;
    volatile int                                                           m_last_send_attempt_time_in_ms;
    unsigned int                                                           m_max_packet_wait_time_in_ms;
    const unsigned int                                                     m_max_idle_time_in_ms;
    unsigned int                                                           m_disconnection_receive_time_in_ms;
    unsigned int                                                           m_pending_operations_count;
};

                            struct __cppobj vostok::network_core::udp_match_stats
                            {
                                vostok::network_core::udp_match_stream_stats sent;
                                vostok::network_core::udp_match_stream_stats sent_low_level;
                                vostok::network_core::udp_match_stream_stats resent;
                                vostok::network_core::udp_match_stream_stats received;
                                vostok::network_core::udp_match_stream_stats received_low_level;
                                vostok::network_core::udp_match_stream_stats received_duplicated;
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


/*
 *
 *
 */
struct __cppobj __declspec(align(2)) vostok::network_core::udp_match_packet
    : vostok::network_core::packet<vostok::network_core::udp_match_packet>
{
    boost::intrusive::set_member_hook<
        boost::intrusive::none,
        boost::intrusive::none,
        boost::intrusive::none,
        boost::intrusive::none
    >                                                   set_member_hook;

    vostok::network_core::udp_match_client_session      *client_session;
    vostok::network_core::udp_match_packet              *next;
    unsigned int                                        last_send_time_in_ms;

    vostok::network_core::sequence_number<
        unsigned short
    >                                                   sequence_id;

    vostok::network_core::sequence_number<
        unsigned short
    >                                                   order_id;

    unsigned __int8                                     message_type;
    unsigned __int8                                     send_count;

    unsigned __int8                                     channel_id   : 6;
    unsigned __int8                                     is_reliable  : 1;
    unsigned __int8                                     is_ordered   : 1;

    boost::array<unsigned char,256>                     m_buffer;
};



//
// Functions
//


/*
 * Enqueues a UDP match packet for sending.
 * - If the packet is ordered, assigns and writes its order ID.
 * - If the packet is reliable, increments the unacknowledged counter.
 * - Pushes the packet to the send queue (does not track if it's the first).
 */

void __thiscall vostok::network_core::udp_match_connection::enqueue_impl(
    vostok::network_core::udp_match_connection *this,
    vostok::network_core::udp_match_packet *packet)
{
    if (packet->is_ordered) {
        auto &sent_order_id = this->m_channels.elems[packet->channel_id].sent_order_id;
        packet->order_id = sent_order_id;

        *reinterpret_cast<vostok::network_core::sequence_number<unsigned short> *>(
            packet->m_buffer.data() + 1) = sent_order_id;

        ++sent_order_id.m_number;
    }

    if (packet->is_reliable)
        ++this->m_stats.unacknowledged_packets;

    this->m_packets_to_send.push_back(packet, nullptr);
}
