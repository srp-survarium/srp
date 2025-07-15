void __usercall survarium::base_player::end_jump(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  int *v2; // eax

  *(_DWORD *)(a2 + 760) = 0;
  v2 = *(int **)((char *)&dword_10E74 + a2);
  if ( s_cc_use_old_controller_value )
    *(_BYTE *)(v2[1] + 572) = 0;
  else
    vostok::physics::bullet_character_controller::end_jump(0, *v2);
}
