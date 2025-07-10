void __thiscall survarium::network_client::on_players_ready(
        survarium::network_client *this,
        vostok::resources::queries_result *data,
        unsigned int players_count)
{
  survarium::network_client *v3; // ebx
  void (__cdecl *v4)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *m_object; // ecx
  vostok::resources::unmanaged_resource *v7; // eax
  survarium::player *p_m_prev_in_global_list; // ecx
  survarium::player *v9; // edi
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::resources::unmanaged_resource *v11; // esi
  vostok::resources::unmanaged_resource *v12; // eax
  vostok::resources::unmanaged_resource **p_m_object; // ecx
  vostok::resources::unmanaged_resource *v14; // edx
  vostok::resources::unmanaged_resource *v15; // eax
  const char *v16; // esi
  void (__cdecl *v17)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // ebx
  void (__cdecl *v18)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::player *v19; // eax
  vostok::network_core::udp_match_packet *v20; // eax
  vostok::network_core::udp_match_packet *v21; // eax
  unsigned int m_last_tick_time_in_ms; // [esp-4h] [ebp-44h]
  int v23; // [esp+10h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // [esp+14h] [ebp-2Ch]
  unsigned int v26; // [esp+1Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-20h] BYREF

  v3 = this;
  v23 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
  {
    v4 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v4 )
    {
      log_callback.functor.obj_ptr = v4;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v23 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\network_client_processing.cpp",
      0x63u,
      "void __thiscall survarium::network_client::on_players_ready(class vostok::resources::queries_result &,unsigned int)",
      "game:",
      info,
      "network_client::on_players_ready");
  }
  if ( (v23 & 1) != 0 )
  {
    v23 &= ~1u;
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  if ( players_count )
  {
    p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
    v26 = players_count;
    do
    {
      m_object = p_m_unmanaged_resource->m_object;
      v7 = 0;
      if ( p_m_unmanaged_resource->m_object )
      {
        v7 = p_m_unmanaged_resource->m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        p_m_prev_in_global_list = (survarium::player *)&m_object[-2].m_prev_in_global_list;
      }
      else
      {
        p_m_prev_in_global_list = 0;
      }
      v9 = 0;
      if ( p_m_prev_in_global_list )
      {
        v9 = p_m_prev_in_global_list;
        _InterlockedExchangeAdd(&p_m_prev_in_global_list->m_reference_count, 1u);
      }
      if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
      if ( v9 )
        v10 = &v9->vostok::resources::unmanaged_resource;
      else
        v10 = 0;
      v11 = 0;
      if ( v10 )
      {
        v11 = v10;
        _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
      }
      v12 = 0;
      p_m_object = &v3->m_net_players.elems[v9->id].player.m_object;
      if ( v11 )
      {
        v12 = v11;
        _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
      }
      v14 = v12;
      v15 = *p_m_object;
      *p_m_object = v14;
      if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
      if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", info) )
      {
        v16 = "local";
        if ( !v9->is_local )
          v16 = "remote";
        v17 = vostok::core::g_log_callback;
        log_callback.vtable = 0;
        if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
            &log_callback.functor,
            &log_callback.functor,
            destroy_functor_tag);
        if ( v17 )
        {
          log_callback.functor.obj_ptr = v17;
          log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                       + 1);
        }
        else
        {
          log_callback.vtable = 0;
        }
        v23 |= 2u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\network_client_processing.cpp",
          0x6Du,
          "void __thiscall survarium::network_client::on_players_ready(class vostok::resources::queries_result &,unsigned int)",
          "game:",
          info,
          "network_client::on_players_ready : %d => %s",
          v9->id,
          v16);
      }
      if ( (v23 & 2) != 0 )
      {
        v23 &= ~2u;
        if ( log_callback.vtable )
        {
          if ( ((int)log_callback.vtable & 1) == 0 )
          {
            v18 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
            if ( v18 )
              v18(&log_callback.functor, &log_callback.functor, 2);
          }
        }
      }
      if ( v9->is_local )
      {
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
        v3 = this;
        v19 = this->m_local_player.m_object;
        this->m_local_player.m_object = v9;
        if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &v19->vostok::resources::unmanaged_intrusive_base,
            &v19->vostok::resources::unmanaged_resource);
      }
      else
      {
        v3 = this;
      }
      if ( !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &v9->vostok::resources::unmanaged_intrusive_base,
          &v9->vostok::resources::unmanaged_resource);
      p_m_unmanaged_resource += 180;
      --v26;
    }
    while ( v26 );
  }
  v20 = vostok::network::match_client::new_packet(&v3->m_match_client.m_client, 0x48u);
  vostok::network::match_client::enqueue(&v3->m_match_client.m_client, v20);
  v3->m_match_client.m_are_there_any_packets_to_send = 1;
  v21 = vostok::network::match_client::new_packet(&v3->m_match_client.m_client, 0x42u);
  vostok::network::match_client::enqueue(&v3->m_match_client.m_client, v21);
  v3->m_match_client.m_are_there_any_packets_to_send = 1;
  m_last_tick_time_in_ms = v3->m_last_tick_time_in_ms;
  v3->m_match_client.m_last_send_queed_packets_time_in_ms = m_last_tick_time_in_ms;
  v3->m_match_client.m_are_there_any_packets_to_send = 0;
  vostok::network::match_client::send_queued_packets(&v3->m_match_client.m_client, m_last_tick_time_in_ms);
}
