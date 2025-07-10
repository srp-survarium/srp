void __userpurge survarium::network_client::process_player_action(
        survarium::network_client *this@<ecx>,
        vostok::network_core::packet_reader *packet@<eax>,
        survarium::player *time_in_ms)
{
  char v4; // bl
  const unsigned __int8 *m_pointer; // eax
  int v6; // edx
  vostok::math::float4x4 *v7; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  survarium::player *m_object; // ebx
  vostok::math::float3 *angles; // eax
  vostok::math::float3 *orientation; // [esp+8h] [ebp-B0h]
  float order; // [esp+Ch] [ebp-ACh]
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player; // [esp+20h] [ebp-98h] BYREF
  int v15; // [esp+24h] [ebp-94h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-90h] BYREF
  survarium::server_player_update action; // [esp+58h] [ebp-60h] BYREF

  v4 = 0;
  v15 = 0;
  m_pointer = packet->m_pointer;
  LOBYTE(v15) = *m_pointer;
  v6 = (unsigned __int8)v15;
  packet->m_pointer = m_pointer + 1;
  this->get_player(this, &player, v6);
  survarium::player_input::player_input(&action.input);
  survarium::weapon_state::weapon_state(&action.weapon_state);
  survarium::server_player_update::deserialize(&action, packet);
  if ( player.m_object )
  {
    if ( !player.m_object->m_is_alive )
    {
      m_object = player.m_object;
      angles = vostok::math::float4x4::get_angles(v7, orientation, SLODWORD(action.state.look_pitch));
      survarium::player::set_character_transform(
        m_object,
        (const vostok::math::float3 *)&action.state.transform.lines[3],
        angles->y,
        order);
      vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
      return;
    }
    survarium::player::time_warp(
      time_in_ms,
      (const survarium::server_player_update *)player.m_object,
      (unsigned int)&action);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", warning) )
    {
      v8 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v8 )
      {
        log_callback.functor.obj_ptr = v8;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v4 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\network_client_processing.cpp",
        0x217u,
        "void __thiscall survarium::network_client::process_player_action(class vostok::network_core::packet_reader &,con"
        "st unsigned int)",
        "game:",
        warning,
        "player not found %d",
        (unsigned __int8)v15);
    }
    if ( (v4 & 1) != 0 )
    {
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v9 )
          {
            v9(&log_callback.functor, &log_callback.functor, 2);
            vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
            return;
          }
        }
      }
    }
  }
  vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
}
