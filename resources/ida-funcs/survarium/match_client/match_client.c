void __userpurge survarium::match_client::match_client(
        survarium::match_client *this@<ecx>,
        int a2@<edi>,
        vostok::network_core::udp_match_packets_orderer *world)
{
  vostok::network::match_client *v3; // ecx

  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = &survarium::base_match_client::`vftable';
  *(_BYTE *)(a2 + 8) = 0;
  survarium::match_options::match_options((survarium::match_options *)this, a2 + 16);
  *(_DWORD *)a2 = &survarium::match_client::`vftable';
  vostok::network::match_client::match_client(
    v3,
    (vostok::network::match_client *)(a2 + 29904),
    (vostok::network::world_vtbl *)world,
    (vostok::network::world_vtbl *)(a2 + 30152),
    0);
  *(_DWORD *)(a2 + 30152) = &survarium::network_packets_orderer<enum vostok::match::client::messages_enum,enum vostok::match::server::messages_enum>::`vftable';
}
