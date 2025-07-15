void __usercall vostok::network_core::udp_match_connection::disconnect(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<eax>)
{
  bool has_passed_filters; // al
  vostok::network_core::udp_match_connection *v4; // ecx
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1> > *v6; // ecx
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v7; // eax
  vostok::network_core::udp_match_connection *v8; // [esp-4h] [ebp-44h]
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1> > *v9; // [esp-4h] [ebp-44h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v10; // [esp+10h] [ebp-30h] BYREF
  remove_all_predicate predicate; // [esp+30h] [ebp-10h] BYREF
  int v12; // [esp+3Ch] [ebp-4h] BYREF

  v12 = 0;
  *(_DWORD *)(a2 + 2820) = 1;
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)"network_core",
                               (const char *)2),
        this = v8,
        has_passed_filters) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
      &v10);
    v12 = 1;
    vostok::logging::append(
      &v10,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\udp_match_connection.cpp",
      0x3D1u,
      "void __thiscall vostok::network_core::udp_match_connection::disconnect(void)",
      "network_core",
      error,
      "--initiating_disconnection");
  }
  if ( (v12 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&v10);
  LOWORD(v12) = *(_WORD *)(a2 + 2840) + 1;
  if ( (unsigned __int8)vostok::network_core::sequence_number<unsigned short>::operator<=(
                          (vostok::network_core::sequence_number<unsigned short> *)(a2 + 2844),
                          (unsigned __int16 *)&v12) )
  {
    vostok::network_core::udp_match_connection::instant_disconnect(
      v4,
      a2,
      (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)2);
  }
  else
  {
    predicate.m_packets_allocator = *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784);
    predicate.m_stats = (vostok::network_core::udp_match_stats *)(a2 + 2500);
    predicate.m_logging_id = uri;
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
      (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v4,
      (_DWORD *)(a2 + 2660),
      &predicate);
    predicate.m_packets_allocator = *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784);
    predicate.m_stats = (vostok::network_core::udp_match_stats *)(a2 + 2500);
    predicate.m_logging_id = uri;
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::remove_if<remove_all_predicate>(
      v5,
      (_DWORD *)(a2 + 2628),
      &predicate);
    while ( *(_DWORD *)(a2 + 2680) )
    {
      v12 = *(_DWORD *)(a2 + 2684) - 20;
      boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1>>::erase(
        v6,
        a2 + 2676,
        (const vostok::network_core::udp_match_packet *)v12);
      vostok::network_core::delete_udp_match_packet(
        *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784),
        (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&v12);
      v6 = v9;
    }
    LOWORD(v6) = *(_WORD *)(a2 + 2840);
    *(_WORD *)(a2 + 2846) = (_WORD)v6;
    ++*(_WORD *)(a2 + 2846);
    v7 = (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)vostok::network_core::udp_match_connection::new_low_level_packet((vostok::network_core::udp_match_connection *)v6, a2, 0);
    vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      (_DWORD *)(a2 + 2628));
  }
}
