



Survarium client 1: { w w w } -> server
Survarium server  : <everything except for renderer> <identical to client logic>
Survarium client 2: server -> { w w w }

Survarium client 3: server -> { w w w }


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
