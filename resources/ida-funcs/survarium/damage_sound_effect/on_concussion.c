void __thiscall survarium::damage_sound_effect::on_concussion(
        survarium::damage_sound_effect *this,
        const char *const __formal,
        const survarium::hit_affects_type_enum affect,
        const survarium::affect_event_type_enum type)
{
  survarium::player *v5; // ecx
  char v6; // dl
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *p_m_concussion_sound_instance; // ebx
  survarium::base_game_scene *m_game_scene; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // edi
  vostok::sound::sound_type v10; // eax
  vostok::sound::world_user *v11; // eax
  boost::function<void __cdecl(void)> *v12; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> &),boost::_bi::list1<boost::reference_wrapper<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > > > v15; // [esp-8h] [ebp-40h]
  int v16; // [esp+0h] [ebp-38h]
  _DWORD *v17; // [esp+10h] [ebp-28h] BYREF
  boost::function<void __cdecl(void)> v18; // [esp+18h] [ebp-20h] BYREF

  if ( !survarium::base_player::is_in_past(this->m_user, (int)this->m_user, this->m_user->m_current_time_in_ms) )
  {
    this->m_is_concussed = type == affect_applying;
    if ( survarium::player::is_current(v5, (int)v5) )
    {
      if ( v6 )
      {
        p_m_concussion_sound_instance = &this->m_concussion_sound_instance;
        if ( !this->m_concussion_sound_instance.m_object )
        {
          m_game_scene = this->m_game_scene;
          p_m_sound_scene = &m_game_scene->m_sound_scene;
          v10 = (vostok::sound::sound_type)m_game_scene->m_game->m_sound_world->get_logic_world_user(m_game_scene->m_game->m_sound_world);
          v11 = vostok::sound::sound_emitter::emit_hud_sound(
                  this->m_sounds[8].m_object,
                  p_m_sound_scene,
                  (vostok::sound::world_user *)&v17,
                  v10);
          vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
            (const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)v11,
            p_m_concussion_sound_instance);
          if ( v17 )
          {
            if ( v17[10]-- == 1 )
              (*(void (__thiscall **)(_DWORD *))(*v17 + 32))(v17);
          }
          v15.l_.a1_.t_ = &this->m_concussion_sound_instance;
          v15.f_ = (void (__cdecl *)(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *))survarium::null_instance_after_end;
          boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
            v12,
            (boost::_bi::bind_t<void,void (__cdecl*)(vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> &),boost::_bi::list1<boost::reference_wrapper<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > > > *)&v18,
            v15,
            v16);
          boost::function<void __cdecl (void)>::operator=(
            &v18,
            (boost::function1<void,vostok::physics::contact_point const &> *)&p_m_concussion_sound_instance->m_object->m_finished_callback);
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            v14,
            (int *)&v18);
          p_m_concussion_sound_instance->m_object->play(p_m_concussion_sound_instance->m_object, once, 0, 0);
        }
      }
    }
  }
}
