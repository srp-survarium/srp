void __thiscall survarium::zone_group::finalize(survarium::zone_group *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::zone_group::zone_wrapper *M_start; // [esp+18h] [ebp-10h]
  unsigned int z; // [esp+24h] [ebp-4h]

  for ( z = 0; ; ++z )
  {
    v1 = (survarium::game_camera *)(this->zones._M_impl._M_finish - this->zones._M_impl._M_start);
    if ( z >= (unsigned int)v1 )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    M_start = this->zones._M_impl._M_start;
    if ( M_start[z].active )
    {
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)M_start[z].active);
      ((void (__thiscall *)(survarium::damage_zone_core *, survarium::damage_zone_core *))this->zones._M_impl._M_start[z].zone->deactivate)(
        this->zones._M_impl._M_start[z].zone,
        this->zones._M_impl._M_start[z].zone);
      survarium::weapon_user_dead_state::finalize(v2);
      this->zones._M_impl._M_start[z].active = 0;
    }
  }
}
