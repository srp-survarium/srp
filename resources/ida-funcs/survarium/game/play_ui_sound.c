void __thiscall survarium::game::play_ui_sound(survarium::game *this, int sound_id, unsigned __int8 a3)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  vostok::particle::particle_system_instance_impl **v4; // eax
  int v5; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v6; // esi
  vostok::sound::sound_instance_proxy *v7; // eax
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-44h]
  const vostok::sound::sound_receiver *v10; // [esp+0h] [ebp-40h]
  bool v11; // [esp+4h] [ebp-3Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+10h] [ebp-30h] BYREF
  vostok::math::float3 v13; // [esp+14h] [ebp-2Ch] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+20h] [ebp-20h] BYREF

  v3 = 0;
  v12.m_object = 0;
  if ( a3 < *(_BYTE *)(sound_id + 15068)
    && (v4 = (vostok::particle::particle_system_instance_impl **)(*(_DWORD *)(sound_id + 15064) + 4 * a3), *v4)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      &v12,
      *v4);
    v5 = *(_DWORD *)(sound_id + 156);
    v6 = *(vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)(sound_id + 13900);
    memset(&v13, 0, sizeof(v13));
    v7 = (vostok::sound::sound_instance_proxy *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 8))(v5);
    vostok::sound::sound_emitter::emit_and_play_once(
      (vostok::sound::sound_emitter *)v12.m_object,
      v6 + 37,
      v7,
      &v13,
      (const vostok::sound::sound_producer *)1,
      v10,
      v11);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game",
                                 (const char *)2),
          v3 = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &v14);
      v12.m_object = (vostok::particle::particle_system_instance_impl *)1;
      vostok::logging::append(
        &v14,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game.cpp",
        0x60Eu,
        "void __thiscall survarium::game::play_ui_sound(unsigned char)",
        "game",
        error,
        "There is no UI sound with id[%d]",
        a3);
    }
    if ( ((int)v12.m_object & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v14);
  }
}
