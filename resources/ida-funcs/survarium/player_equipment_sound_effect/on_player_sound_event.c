vostok::animation::callback_return_type_enum __thiscall survarium::player_equipment_sound_effect::on_player_sound_event(
        survarium::player_equipment_sound_effect *this,
        survarium::base_player *params)
{
  int v3; // edx
  int v4; // ecx

  if ( !survarium::base_player::is_in_past(
          params,
          (int)this->m_player,
          *((_DWORD *)&params->vostok::resources::resource_flags + 3))
    && *(_DWORD *)v4 == v3 )
  {
    if ( *(_BYTE *)(v4 + 20) )
    {
      switch ( *(_BYTE *)(v4 + 20) )
      {
        case 1:
          if ( this->m_toe_transforms_are_actual )
            survarium::player_equipment_sound_effect::on_foot_step(
              (survarium::player_equipment_sound_effect *)v4,
              (int)this,
              &this->m_right_toe_position,
              &this->m_right_toe_rotation);
          break;
        case 2:
          survarium::player_equipment_sound_effect::on_pants_rustle(
            (survarium::player_equipment_sound_effect *)v4,
            this);
          break;
        case 3:
          survarium::player_equipment_sound_effect::on_backpack_rustle(
            (survarium::player_equipment_sound_effect *)v4,
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
          break;
        default:
          survarium::player_equipment_sound_effect::on_torso_rustle(
            (survarium::player_equipment_sound_effect *)v4,
            (int)this);
          break;
      }
    }
    else if ( this->m_toe_transforms_are_actual )
    {
      survarium::player_equipment_sound_effect::on_foot_step(
        (survarium::player_equipment_sound_effect *)v4,
        (int)this,
        &this->m_left_toe_position,
        &this->m_left_toe_rotation);
    }
  }
  return 0;
}
