Survarium client 1: { w w w } -> server
Survarium server  : <everything except for renderer> <identical to client logic>
Survarium client 2: server -> { w w w }

Survarium client 3: server -> { w w w }

0.20e : no such message | March 21, 2014
15.12.2014

game <info> [14:55:19.980] create network client
render_pc_dx11 <ERROR> [14:55:49.312] cook(before erasing)
render_pc_dx11 <info> [14:55:49.434] atmosphere recalculated ( scene_changed:true, parameters_changed:false, window_resized:true )
render_pc_dx11 <info> [14:55:50.725] atmosphere recalculated ( scene_changed:false, parameters_changed:true, window_resized:false )
    network_core <Warning> [14:56:16.342] QOS_CONTROLLER ENABLED
    network_core <Warning> [14:56:16.342] QOS_CONTROLLER ENABLED
game <info> [14:56:28.096] PlayBtn disabled reason is: state=4 place=0 maintenance=0
animation <Warning> [14:56:28.108] big time lag (38.783) => skipping animation events
game <info> [14:56:28.512] LOBBY: try reconnect
network_core <info> [14:56:28.513] connecting from 0.0.0.0:63049 to 188.93.23.27:65001
network_core <info> [14:56:28.513] --udp_match_connection::connect (70.111s)
render_pc_dx11 <info> [14:56:28.531] atmosphere recalculated ( scene_changed:true, parameters_changed:false, window_resized:true )
game <info> [14:56:30.694] eating time: 2.181, but max frame delta is 2.000
render_pc_dx11 <info> [14:56:30.699] atmosphere recalculated ( scene_changed:false, parameters_changed:true, window_resized:false )
game <ERROR> [14:56:31.241] Unknown Client status received. type = 155


// NOTES:
// * UDP: 25100 port is open for something
// * happens after error log
//      game <ERROR>	[20:17:47:613]	[R] connect_to_game_server: 127.0.0.1: 1236 game time is 230496


file.exe => file.o

file.cpp => file.o =>
file.h

<profile1><profile2><profile3>

on_lobby_packet_received(
                                    | 256
[0e, 00, ff, ff, 01, 00, 0b00000001, 02]
|  id  |   ?   | t | ? |   ^^|     | ? |

[0f, 00, ff, ff, 00, 00, 40, 00, 00, 00, dd, 00, 00]
|  id  |   ?   | t | ? | ? |   session_id  |  ?    |

```cpp
00000000 struct __cppobj __declspec(align(2)) vostok::network_core::udp_match_packet : vostok::network_core::packet<vostok::network_core::udp_match_packet> // sizeof=0x12C
00000000 {                                       // XREF: udp_match_packet/r
00000008     boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> set_member_hook;
00000018     vostok::network_core::udp_match_client_session *client_session;
0000001C     vostok::network_core::udp_match_packet *next;
00000020     unsigned int last_send_time_in_ms;
00000024     vostok::network_core::sequence_number<unsigned short> sequence_id;
00000026     vostok::network_core::sequence_number<unsigned short> order_id;
00000028     unsigned __int8 message_type;
00000029     unsigned __int8 send_count;
0000002A.0   unsigned __int8 channel_id : 6;
0000002A.6   unsigned __int8 is_reliable : 1;
0000002A.7   unsigned __int8 is_ordered : 1;
0000002B     boost::array<unsigned char,256> m_buffer;
0000012B     // padding byte
0000012C };
```


match_client::connect -> match_client::on_connected
                            -> creates functor_response
                            -> initializes it to vtable thios->on_response
                            -> pushes it to the network_world::add_response

on_lobby_packet_received -> switch_to_level_loadingG


void __thiscall vostok::network_core::udp_match_client::handle_receive(


packet 1 2 3 4 5

server 1 2 _ 4 5 .... 10 <-
client 1 2 3 4 5



void __usercall survarium::match_client::enqueue
    -> vostok::network::match_client::enqueue
    -> void __cdecl enqueue_impl
    -> vostok::network_core::udp_match_client::enqueue
    -> vostok::network_core::udp_match_connection::enqueue
    -> void __thiscall vostok::network_core::udp_match_connection::enqueue_impl





struct __cppobj __declspec(align(2)) vostok::network_core::udp_match_packet : vostok::network_core::packet<vostok::network_core::udp_match_packet>
{
  boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none> set_member_hook;
  vostok::network_core::udp_match_client_session *client_session;
  vostok::network_core::udp_match_packet *next;
  unsigned int last_send_time_in_ms;
  vostok::network_core::sequence_number<unsigned short> sequence_id; // ???
  vostok::network_core::sequence_number<unsigned short> order_id;    // ???
  unsigned __int8 message_type;
  unsigned __int8 send_count;
  unsigned __int8 channel_id : 6;
  unsigned __int8 is_reliable : 1;
  unsigned __int8 is_ordered : 1;
  boost::array<unsigned char,256> m_buffer;
};


construct_packet | all packets are is_reliable and is_ordered, all packets are appended??


/*
 *
 *
 */
survarium::match_client
    -> vostok::network::match_client
    -> vostok::network::match_client_impl
    -> vostok::network_core::udp_match_client
    -> vostok::network_core::udp_match_connection

```cpp
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
```






survarium::match_client::send_queued_packets
match_client::send_queued_packets
    -> match_client_impl::send_queued_packets
    -> udp_match_client::send_queued_packets
    -> udp_match_connection::send_queued_packets
    -> udp_match_connection::send_packets_list
    -> udp_match_connection::send

