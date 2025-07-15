void __thiscall survarium::breath_holding_sound_effect::on_intro_or_looped_sound_ended(
        survarium::breath_holding_sound_effect *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // ecx
  survarium::game *m_game; // eax
  int v5; // eax
  boost::function<void __cdecl(void)> *v6; // ecx
  bool v7; // zf
  int v8; // esi
  survarium::breath_holding_sound_effect *v9; // eax
  vostok::sound::world_user *v10; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::breath_holding_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::breath_holding_sound_effect *> > > v12; // [esp-Ch] [ebp-5Ch]
  boost::function<void __cdecl(void)> f; // [esp+10h] [ebp-40h] BYREF
  survarium::breath_holding_sound_effect *v14; // [esp+34h] [ebp-1Ch]
  survarium::breath_holding_sound_effect *v15; // [esp+38h] [ebp-18h]
  survarium::breath_holding_sound_effect *v16; // [esp+3Ch] [ebp-14h]
  survarium::breath_holding_sound_effect *v17; // [esp+40h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v18; // [esp+44h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+48h] [ebp-8h] BYREF
  _DWORD *v20; // [esp+4Ch] [ebp-4h] BYREF

  m_game_scene = this->m_game_scene;
  p_m_sound_scene = &m_game_scene->m_sound_scene;
  m_game = m_game_scene->m_game;
  v18 = p_m_sound_scene;
  v5 = (int)m_game->m_sound_world->get_logic_world_user(m_game->m_sound_world);
  f.vtable = 0;
  v7 = !this->m_breath_held;
  v20 = (_DWORD *)v5;
  if ( v7 )
  {
    v8 = 2;
    v15 = this;
    v14 = this;
    v9 = (survarium::breath_holding_sound_effect *)survarium::breath_holding_sound_effect::on_outro_sound_ended;
  }
  else
  {
    v8 = 1;
    v17 = this;
    v16 = this;
    v9 = (survarium::breath_holding_sound_effect *)survarium::breath_holding_sound_effect::on_intro_or_looped_sound_ended;
  }
  v12.l_.a1_.t_ = v9;
  v12.f_.f_ = (void (__thiscall *)(survarium::breath_holding_sound_effect *))&f;
  boost::function<void __cdecl (void)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::breath_holding_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::breath_holding_sound_effect *>>>>(
    v6,
    v12,
    (unsigned int)this);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v19,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_11251 + (unsigned int)this->m_user + 4 * v8 + 3));
  v10 = vostok::sound::sound_emitter::emit_hud_sound(
          (vostok::sound::sound_emitter *)v19.m_object,
          v18,
          (vostok::sound::world_user *)&v20,
          (vostok::sound::sound_type)v20);
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
    (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v10,
    &this->m_sound_instance);
  if ( v20 )
  {
    v7 = v20[10]-- == 1;
    if ( v7 )
      (*(void (__thiscall **)(_DWORD *))(*v20 + 32))(v20);
  }
  if ( this->m_sound_instance.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    boost::function<void __cdecl (void)>::operator=(
      &f,
      (boost::function1<void,vostok::physics::contact_point const &> *)&this->m_sound_instance.m_object->m_finished_callback);
    this->m_sound_instance.m_object->play(this->m_sound_instance.m_object, once, 0, 0);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v11,
    (int *)&f);
}
