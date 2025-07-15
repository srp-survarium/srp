void __thiscall survarium::generic_anomaly_core::on_zone_act(
        survarium::generic_anomaly_core *this,
        survarium::damage_zone_core *zone,
        survarium::hit_receiver *receiver)
{
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)receiver);
  this->m_was_zone_trigger_event = 1;
}
