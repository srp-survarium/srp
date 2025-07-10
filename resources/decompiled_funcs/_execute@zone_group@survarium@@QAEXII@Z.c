void __thiscall survarium::zone_group::execute(
        survarium::zone_group *this,
        unsigned int time_delta_ms,
        unsigned int current_time_ms)
{
  survarium::game_camera *v3; // ecx
  survarium::zone_group::zone_wrapper *M_start; // [esp+10h] [ebp-10h]
  unsigned int z; // [esp+1Ch] [ebp-4h]

  if ( this->next_recharge_time && current_time_ms >= this->next_recharge_time )
    survarium::zone_group::recharge(this);
  for ( z = 0; ; ++z )
  {
    v3 = (survarium::game_camera *)(this->zones._M_impl._M_finish - this->zones._M_impl._M_start);
    if ( z >= (unsigned int)v3 )
      break;
    survarium::weapon_user_dead_state::finalize(v3);
    M_start = this->zones._M_impl._M_start;
    if ( M_start[z].active )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)M_start[z].active);
      this->zones._M_impl._M_start[z].zone->tick(this->zones._M_impl._M_start[z].zone, time_delta_ms, current_time_ms);
    }
  }
}
