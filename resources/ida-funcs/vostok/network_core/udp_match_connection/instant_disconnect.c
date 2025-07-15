void __userpurge vostok::network_core::udp_match_connection::instant_disconnect(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<edi>,
        const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *type)
{
  bool has_passed_filters; // al
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1> > *v5; // ecx
  _DWORD *i; // ebx
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // esi
  int v12; // ecx
  vostok::network_core::udp_match_connection *v13; // [esp-4h] [ebp-50h]
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1> > *v14; // [esp-4h] [ebp-50h]
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1> > *v15; // [esp-4h] [ebp-50h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v16; // [esp+8h] [ebp-44h] BYREF
  remove_all_predicate v17; // [esp+28h] [ebp-24h] BYREF
  remove_all_predicate predicate; // [esp+34h] [ebp-18h] BYREF
  const vostok::network_core::udp_match_packet *v19; // [esp+40h] [ebp-Ch] BYREF
  int v20; // [esp+44h] [ebp-8h] BYREF

  v20 = 0;
  *(_DWORD *)(a2 + 2820) = 3;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"network_core",
                               (const char *)2),
        this = v13,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v16);
    v20 = 1;
    vostok::logging::append(
      &v16,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\udp_match_connection.cpp",
      0x3A6u,
      "void __thiscall vostok::network_core::udp_match_connection::instant_disconnect(enum vostok::network_core::disconne"
      "ct_event_types_enum)",
      "network_core",
      error,
      "--instant_disconnect");
  }
  if ( (v20 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v16);
  *(_DWORD *)(a2 + 2800) = 0;
  *(_DWORD *)(a2 + 2804) = 0;
  *(_DWORD *)(a2 + 2792) = 0;
  *(_DWORD *)(a2 + 2812) = 0;
  *(_DWORD *)(a2 + 2824) = 0;
  *(_DWORD *)(a2 + 2828) = 0;
  *(_DWORD *)(a2 + 2832) = 0;
  *(_DWORD *)(a2 + 2836) = 0;
  *(_WORD *)(a2 + 2840) = -1;
  *(_WORD *)(a2 + 2842) = -1;
  *(_WORD *)(a2 + 2844) = -1;
  *(_WORD *)(a2 + 2846) = -1;
  predicate.m_packets_allocator = *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784);
  predicate.m_stats = (vostok::network_core::udp_match_stats *)(a2 + 2500);
  predicate.m_logging_id = uri;
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
    (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)0xFFFF,
    (_DWORD *)(a2 + 2660),
    &predicate);
  v17.m_packets_allocator = *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784);
  v17.m_stats = (vostok::network_core::udp_match_stats *)(a2 + 2500);
  v17.m_logging_id = uri;
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
    v4,
    (_DWORD *)(a2 + 2628),
    &v17);
  for ( i = (_DWORD *)(a2 + 2680); *i; v5 = v14 )
  {
    v20 = *(_DWORD *)(a2 + 2684) - 20;
    boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1>>::erase(
      v5,
      a2 + 2676,
      (const vostok::network_core::udp_match_packet *)v20);
    vostok::network_core::delete_udp_match_packet(
      *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784),
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&v20);
  }
  for ( ; *(_DWORD *)(a2 + 2700); v5 = v15 )
  {
    v19 = (const vostok::network_core::udp_match_packet *)(*(_DWORD *)(a2 + 2704) - 20);
    boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1>>::erase(
      v5,
      a2 + 2696,
      v19);
    vostok::network_core::delete_udp_match_packet(
      *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784),
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&v19);
  }
  v7 = (_DWORD *)*i;
  if ( *i )
  {
    do
    {
      v8 = (_DWORD *)v7[1];
      if ( v8 )
      {
        v7[1] = v8[2];
        v8[2] = v7;
      }
      else
      {
        v8 = (_DWORD *)v7[2];
        *v7 = 0;
        v7[1] = 0;
        v7[2] = 0;
      }
      v7 = v8;
    }
    while ( v8 );
    *i = 0;
    *(_DWORD *)(a2 + 2684) = a2 + 2680;
    *(_DWORD *)(a2 + 2688) = a2 + 2680;
  }
  *i = 0;
  *(_DWORD *)(a2 + 2684) = a2 + 2680;
  *(_DWORD *)(a2 + 2688) = a2 + 2680;
  *(_DWORD *)(a2 + 2692) = 0;
  *(_DWORD *)(a2 + 2676) = 0;
  v9 = (_DWORD *)(a2 + 2700);
  v10 = *(_DWORD **)(a2 + 2700);
  if ( v10 )
  {
    do
    {
      v11 = (_DWORD *)v10[1];
      if ( v11 )
      {
        v10[1] = v11[2];
        v11[2] = v10;
      }
      else
      {
        v11 = (_DWORD *)v10[2];
        *v10 = 0;
        v10[1] = 0;
        v10[2] = 0;
      }
      v10 = v11;
    }
    while ( v11 );
    *v9 = 0;
    *(_DWORD *)(a2 + 2704) = a2 + 2700;
    *(_DWORD *)(a2 + 2708) = a2 + 2700;
  }
  *v9 = 0;
  *(_DWORD *)(a2 + 2704) = a2 + 2700;
  *(_DWORD *)(a2 + 2708) = a2 + 2700;
  *(_DWORD *)(a2 + 2712) = 0;
  *(_DWORD *)(a2 + 2696) = 0;
  *(_WORD *)(a2 + 2716) = -1;
  *(_WORD *)(a2 + 2718) = 0;
  v12 = -(*(_DWORD *)(a2 + 2720) != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v12) != 0 )
    boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *)v12,
      (_DWORD *)(a2 + 2720),
      type);
}
