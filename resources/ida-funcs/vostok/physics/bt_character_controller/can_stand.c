bool __usercall vostok::physics::bt_character_controller::can_stand@<al>(
        vostok::physics::bt_character_controller *this@<ecx>,
        int *a2@<eax>)
{
  if ( s_cc_use_old_controller_value )
    return vostok::physics::old_bullet_character_controller::can_stand(
             (vostok::physics::old_bullet_character_controller *)this,
             a2[1]);
  else
    return *(_BYTE *)(*a2 + 498);
}
