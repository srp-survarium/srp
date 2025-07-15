void __thiscall survarium::zone_group::on_zone_act(
        survarium::zone_group *this,
        survarium::damage_zone_core *zone,
        survarium::hit_receiver *receiver)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  unsigned int z; // [esp+34h] [ebp-4h]

  survarium::generic_anomaly_core::on_zone_act(this->owner->owner, zone, receiver);
  for ( z = 0; z < this->zones._M_impl._M_finish - this->zones._M_impl._M_start; ++z )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->zones);
    if ( this->zones._M_impl._M_start[z].zone == zone )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)z);
      survarium::weapon_user_dead_state::finalize(v3);
      ((void (__thiscall *)(survarium::damage_zone_core *, survarium::damage_zone_core *))this->zones._M_impl._M_start[z].zone->deactivate)(
        this->zones._M_impl._M_start[z].zone,
        this->zones._M_impl._M_start[z].zone);
      survarium::weapon_user_dead_state::finalize(v4);
      this->zones._M_impl._M_start[z].active = 0;
      this->next_recharge_time = this->owner->owner->m_current_time + 1000 * this->recharge_time_sec;
      return;
    }
  }
}
