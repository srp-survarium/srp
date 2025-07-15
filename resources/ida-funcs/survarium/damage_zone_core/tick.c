void __thiscall survarium::damage_zone_core::tick(
        survarium::damage_zone_core *this,
        unsigned int frame_delta,
        survarium::game_camera *current_time)
{
  survarium::apply_hit_type m_apply_hit_type; // [esp+0h] [ebp-8h]

  survarium::collision_sensor::tick(this, frame_delta, (const unsigned int)current_time);
  m_apply_hit_type = this->m_apply_hit_type;
  switch ( m_apply_hit_type )
  {
    case on_enter:
      goto LABEL_4;
    case on_inside:
      survarium::damage_zone_core::hit_on_inside(this, frame_delta, (unsigned int)current_time);
      break;
    case on_motion_inside:
      survarium::damage_zone_core::hit_on_motion_inside(this, frame_delta, current_time);
      break;
    default:
LABEL_4:
      survarium::damage_zone_core::hit_on_enter(this, frame_delta, current_time);
      return;
  }
}
