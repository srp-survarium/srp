bool __usercall vostok::physics::bt_character_controller::is_in_jump@<al>(
        vostok::physics::bt_character_controller *this@<ecx>,
        _DWORD *a2@<eax>)
{
  if ( s_cc_use_old_controller_value )
    return *(_BYTE *)(a2[1] + 572);
  else
    return *(_BYTE *)(*a2 + 1164);
}
