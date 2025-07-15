void __thiscall survarium::generic_anomaly_core::on_hit_receiver_leave(
        survarium::generic_anomaly_core *this,
        survarium::hit_receiver *receiver,
        survarium::game_camera *zone)
{
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(zone);
}
