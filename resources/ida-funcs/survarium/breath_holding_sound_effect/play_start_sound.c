void __thiscall survarium::breath_holding_sound_effect::play_start_sound(
        survarium::breath_holding_sound_effect *this,
        survarium::breath_holding_sound_effect *a2)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // ecx
  survarium::game *m_game; // eax
  int v5; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // edi
  vostok::sound::world_user *v7; // eax
  boost::function<void __cdecl(void)> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::breath_holding_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::breath_holding_sound_effect *> > > v11; // [esp-8h] [ebp-40h]
  int v12; // [esp+0h] [ebp-38h]
  _DWORD *v13; // [esp+Ch] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+10h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v15; // [esp+14h] [ebp-24h]
  boost::function<void __cdecl(void)> v16; // [esp+18h] [ebp-20h] BYREF

  m_game_scene = a2->m_game_scene;
  p_m_sound_scene = &m_game_scene->m_sound_scene;
  m_game = m_game_scene->m_game;
  v15 = p_m_sound_scene;
  v5 = (int)m_game->m_sound_world->get_logic_world_user(m_game->m_sound_world);
  v6 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_11251 + (unsigned int)a2->m_user + 3);
  v13 = (_DWORD *)v5;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    v6);
  v7 = vostok::sound::sound_emitter::emit_hud_sound(
         (vostok::sound::sound_emitter *)v14.m_object,
         v15,
         (vostok::sound::world_user *)&v13,
         (vostok::sound::sound_type)v13);
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v7,
    &a2->m_sound_instance);
  if ( v13 )
  {
    if ( v13[10]-- == 1 )
      (*(void (__thiscall **)(_DWORD *))(*v13 + 32))(v13);
  }
  if ( a2->m_sound_instance.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v11.l_.a1_.t_ = a2;
    v11.f_.f_ = survarium::breath_holding_sound_effect::on_intro_or_looped_sound_ended;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      v8,
      (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::breath_holding_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::breath_holding_sound_effect *> > > *)&v16,
      v11,
      v12);
    boost::function<void __cdecl (void)>::operator=(
      &v16,
      (boost::function1<void,vostok::physics::contact_point const &> *)&a2->m_sound_instance.m_object->m_finished_callback);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v10,
      (int *)&v16);
    a2->m_sound_instance.m_object->play(a2->m_sound_instance.m_object, once, 0, 0);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
}
