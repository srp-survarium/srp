vostok::animation::callback_return_type_enum __thiscall survarium::weapon_sound_effect::on_sound_event(
        survarium::weapon_sound_effect *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::base_network_client *v3; // edx
  bool v4; // zf
  unsigned __int8 domain_data; // al
  survarium::weapon *m_weapon; // eax
  survarium::weapon_fx_enum m_fx_type; // edx
  survarium::weapon_sound_effect *v8; // ecx
  survarium::fx_history_item v10; // [esp+8h] [ebp-14h] BYREF
  int v11; // [esp+10h] [ebp-Ch]
  int v12; // [esp+14h] [ebp-8h]

  v11 = 0;
  if ( survarium::base_network_client::is_player_current(
         (survarium::base_network_client *)this,
         (int)this->m_game_scene->m_game->m_network_client,
         this->m_weapon->m_initiator_holder->id) )
  {
    v11 = 1;
    LOBYTE(v12) = *(_DWORD *)(*(_DWORD *)((char *)&loc_11403
                                        + (unsigned int)survarium::base_network_client::get_current_player(
                                                          v3,
                                                          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10.time_in_ms)->m_object
                                        + 5)
                            + 864) == 0;
  }
  else
  {
    LOBYTE(v12) = 0;
  }
  if ( (v11 & 1) != 0 )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10.time_in_ms);
  if ( (_BYTE)v12 )
    v4 = this->m_first_view_sounds.sounds_emitters.m_begin == this->m_first_view_sounds.sounds_emitters.m_end;
  else
    v4 = this->m_third_view_sounds.sounds_emitters.m_begin == this->m_third_view_sounds.sounds_emitters.m_end;
  if ( !v4 )
  {
    domain_data = params->domain_data;
    if ( domain_data == 0xFF )
      this->m_sounds_counter = (unsigned __int8)(this->m_sounds_counter + 1)
                             % (unsigned int)(this->m_first_view_sounds.sounds_emitters.m_end
                                            - this->m_first_view_sounds.sounds_emitters.m_begin);
    else
      this->m_sounds_counter = domain_data;
    m_weapon = this->m_weapon;
    m_fx_type = this->m_fx_type;
    v10.time_in_ms = params->callback_time_in_ms;
    v10.uid = (char *)m_weapon + m_fx_type;
    if ( !survarium::weapon::is_fx_already_beeing_played((survarium::weapon *)&v10, (int)m_weapon, &v10) )
      survarium::weapon_sound_effect::play_sound(v8, (int)this, this->m_sounds_counter, v12);
  }
  return 0;
}
