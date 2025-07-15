void __thiscall survarium::stamina_sound_effect::on_stamina_shortbreathing(survarium::stamina_sound_effect *this)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *p_m_sound_instance; // ebx
  survarium::base_game_scene *m_game_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // edi
  survarium::player *v5; // ecx
  vostok::sound::sound_type v6; // edx
  vostok::sound::world_user *v7; // edi
  boost::function<void __cdecl(void)> *m_object; // ecx
  bool v9; // zf
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v10; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::stamina_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::stamina_sound_effect *> > > v12; // [esp-8h] [ebp-40h]
  int v13; // [esp+0h] [ebp-38h]
  _DWORD *v14; // [esp+10h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v15; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(void)> v16; // [esp+18h] [ebp-20h] BYREF

  p_m_sound_instance = &this->m_sound_instance;
  if ( !this->m_sound_instance.m_object )
  {
    m_game_scene = this->m_game_scene;
    p_m_sound_scene = &m_game_scene->m_sound_scene;
    m_game_scene->m_game->m_sound_world->get_logic_world_user(m_game_scene->m_game->m_sound_world);
    if ( survarium::player::is_current(v5, (int)this->m_player) )
    {
      v7 = vostok::sound::sound_emitter::emit_hud_sound(
             this->m_sound_emitters[0][0].m_object,
             p_m_sound_scene,
             (vostok::sound::world_user *)&v14,
             v6);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v7,
        p_m_sound_instance);
      if ( v14 )
      {
        v9 = v14[10]-- == 1;
        if ( v9 )
          (*(void (__thiscall **)(_DWORD *))(*v14 + 32))(v14);
      }
    }
    else
    {
      v10 = vostok::sound::sound_emitter::emit_point_sound(
              this->m_sound_emitters[1][0].m_object,
              p_m_sound_scene,
              &v15,
              v6);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v10,
        p_m_sound_instance);
      if ( v15.m_object )
      {
        v9 = v15.m_object->m_reference_count-- == 1;
        if ( v9 )
          v15.m_object->free_object(v15.m_object);
      }
      m_object = (boost::function<void __cdecl(void)> *)p_m_sound_instance->m_object;
      if ( p_m_sound_instance->m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        ((void (__thiscall *)(boost::function<void __cdecl(void)> *, vostok::math::float3 *))m_object->vtable[4].manager)(
          m_object,
          &this->m_player_head_position);
      }
    }
    if ( p_m_sound_instance->m_object )
    {
      v12.l_.a1_.t_ = this;
      v12.f_.f_ = survarium::stamina_sound_effect::on_start_sound_ended;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        m_object,
        (boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::stamina_sound_effect>,boost::_bi::list1<boost::_bi::value<survarium::stamina_sound_effect *> > > *)&v16,
        v12,
        v13);
      boost::function<void __cdecl (void)>::operator=(
        &v16,
        (boost::function1<void,vostok::physics::contact_point const &> *)&p_m_sound_instance->m_object->m_finished_callback);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        v11,
        (int *)&v16);
      p_m_sound_instance->m_object->play(p_m_sound_instance->m_object, once, 0, 0);
    }
  }
}
