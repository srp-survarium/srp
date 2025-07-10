void __usercall survarium::game_world::set_local_player_camera(survarium::game_world *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 568) = this;
}
