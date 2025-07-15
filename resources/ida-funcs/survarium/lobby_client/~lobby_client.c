void __usercall survarium::lobby_client::~lobby_client(survarium::lobby_client *this@<ecx>, int a2@<eax>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::network::tcp_packet_client *v9; // ecx
  const char *v10; // [esp+0h] [ebp-Ch]
  const char *v11; // [esp+4h] [ebp-8h]
  unsigned int v12; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(a2 + 13184);
  if ( v3 )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)(v3 - 8),
      v10,
      v11,
      v12);
  *(_DWORD *)(a2 + 13188) = 0;
  survarium::lobby_client::clear_profile_info(this, a2);
  v4 = *(_DWORD *)(a2 + 13152);
  if ( v4 )
    (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 13160) + 24))(
      *(_DWORD *)(a2 + 13160),
      v4,
      "vostok::detail::std_allocator<struct survarium::quest_instance>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
  *(_DWORD *)(a2 + 12888) = *(_DWORD *)(a2 + 12884);
  v5 = *(_DWORD *)(a2 + 12712);
  if ( v5 )
    (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int))(**(_DWORD **)(a2 + 12720) + 24))(
      *(_DWORD *)(a2 + 12720),
      v5,
      "vostok::detail::std_allocator<struct survarium::inventory_item_descr>::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102);
  `vector destructor iterator'(
    (char *)(a2 + 616),
    0x5E8u,
    8,
    (void (__thiscall *)(void *))survarium::lobby_player_profile::~lobby_player_profile);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)(a2 + 400));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v7,
    (int *)(a2 + 368));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)(a2 + 336));
  vostok::network::tcp_packet_client::~tcp_packet_client(v9, a2 + 200);
}
