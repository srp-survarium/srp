void __cdecl enqueue_impl(
        vostok::network::match_client_impl **const client,
        vostok::network_core::udp_match_packet *packet)
{
  vostok::network_core::udp_match_packet *v2; // [esp+0h] [ebp-8h]

  v2 = vostok::network::match_client_impl::clone_packet(*client, packet);
  vostok::network_core::udp_match_client::enqueue(
    (vostok::network_core::udp_match_client *)((char *)*client + (_DWORD)&loc_258034 + 4),
    v2);
}
