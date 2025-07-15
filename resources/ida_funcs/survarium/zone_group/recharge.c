void __thiscall survarium::zone_group::recharge(survarium::zone_group *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::zone_group::zone_wrapper *M_start; // [esp+28h] [ebp-10h]
  unsigned int z; // [esp+34h] [ebp-4h]

  for ( z = 0; ; ++z )
  {
    v1 = (survarium::game_camera *)(this->zones._M_impl._M_finish - this->zones._M_impl._M_start);
    if ( z >= (unsigned int)v1 )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    M_start = this->zones._M_impl._M_start;
    if ( !M_start[z].active )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)M_start[z].active);
      this->zones._M_impl._M_start[z].zone->activate(
        this->zones._M_impl._M_start[z].zone,
        this,
        this->owner->owner->m_physics_world,
        this->owner->owner->m_scheduler);
      survarium::weapon_user_dead_state::finalize(v2);
      this->zones._M_impl._M_start[z].active = 1;
    }
  }
  this->next_recharge_time = 0;
}
