void __userpurge vostok::sound::sound_scene::delete_sound_propagator(
        vostok::sound::new_sound_propagator *propagator@<eax>,
        boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *a2@<ecx>,
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy)
{
  bool has_passed_filters; // al
  vostok::sound::new_sound_propagator *m_first; // eax
  vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_propagators; // ecx
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *m_variable; // esi
  vostok::sound::sound_instance_proxy_internal *v10; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-20h] BYREF
  char v13; // [esp+38h] [ebp+8h]

  v13 = 0;
  if ( propagator )
  {
    m_first = proxy->m_propagators.m_first;
    p_m_propagators = &proxy->m_propagators;
    while ( m_first )
    {
      if ( m_first == propagator )
      {
        vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
          p_m_propagators,
          propagator);
        break;
      }
      m_first = m_first->m_next_for_proxies;
    }
    m_variable = this->m_propagators_allocator.m_variable;
    if ( propagator->m_voice )
      vostok::sound::new_sound_propagator::detach_voice(
        (vostok::sound::new_sound_propagator *)p_m_propagators,
        (int)propagator);
    propagator->m_next_for_proxies = (vostok::sound::new_sound_propagator *)m_variable->m_free_list_head.pointer;
    m_variable->m_free_list_head.pointer = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *)propagator;
    --m_variable->m_allocated_count;
    v10 = this->m_active_proxies.m_first;
    if ( v10 )
    {
      while ( v10 != proxy )
      {
        v10 = v10->m_next_for_sound_world;
        if ( !v10 )
          return;
      }
      if ( !proxy->m_propagators.m_first )
        vostok::intrusive_list<vostok::sound::sound_instance_proxy_internal,vostok::sound::sound_instance_proxy_internal *,96,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
          &this->m_active_proxies,
          proxy);
    }
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                                 (const char *)2),
          a2 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        a2,
        &log_callback);
      v13 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene_propagators.cpp",
        0x70u,
        "void __thiscall vostok::sound::sound_scene::delete_sound_propagator(class vostok::sound::sound_instance_proxy_in"
        "ternal &,class vostok::sound::new_sound_propagator *)",
        (char *)&initiator_raw.filter_stack.m_last,
        error,
        "can't delete sound_propagator, pointer == 0");
    }
    if ( (v13 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)a2,
        (int *)&log_callback);
  }
}
