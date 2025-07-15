void __thiscall vostok::resources::game_resources_manager::dispatch_resources_to_release(
        vostok::resources::game_resources_manager *this,
        int a2)
{
  vostok::resources::resource_base *v2; // edi
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  bool has_passed_filters; // al
  vostok::fixed_string<512> *v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // [esp-4h] [ebp-24Ch]
  int v7; // [esp+Ch] [ebp-23Ch]
  vostok::resources::resource_base *m_next_for_query_finished_callback; // [esp+10h] [ebp-238h]
  vostok::resources::resource_base resource; // [esp+14h] [ebp-234h] BYREF

  v7 = 0;
  v2 = vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
         &this->m_resources_to_capture,
         a2 + 48);
  if ( v2 )
  {
    do
    {
      m_next_for_query_finished_callback = v2->m_next_for_query_finished_callback;
      _InterlockedAnd(&v2->m_flags.m_flags, 0xFFFFFBFF);
      if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base(v2)->m_flags.m_flags & 1) != 0 )
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)&stru_802D94,
                                     (const char *)4),
              v3 = v6,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v3,
            &resource.type);
          v7 |= 1u;
          v5 = vostok::resources::log_string(v2, (int)&resource.m_children_resources.vostok::threading::simple_lock);
          vostok::logging::append(
            (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&resource.type,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_resman.cpp",
            0xDDu,
            "void __thiscall vostok::resources::game_resources_manager::dispatch_resources_to_release(void)",
            (char *)&stru_802D94,
            info,
            "releasing resource from game resources manager: %s",
            v5->m_begin);
        }
        if ( (v7 & 1) != 0 )
        {
          v7 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
            (int *)&resource.type);
        }
        resource.__vftable = (vostok::resources::resource_base_vtbl *)(a2 + 96);
        vostok::resources::releasing_functionality::release_resource(
          (vostok::resources::releasing_functionality *)v3,
          &resource,
          (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v2);
      }
      v2 = m_next_for_query_finished_callback;
    }
    while ( m_next_for_query_finished_callback );
  }
}
