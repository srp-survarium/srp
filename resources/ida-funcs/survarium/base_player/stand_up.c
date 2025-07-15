void __usercall survarium::base_player::stand_up(survarium::base_player *this@<ecx>, int a2@<eax>)
{
  vostok::physics::bt_character_controller **v2; // esi

  v2 = (vostok::physics::bt_character_controller **)((char *)&dword_10E74 + a2);
  if ( vostok::physics::bt_character_controller::can_stand(
         (vostok::physics::bt_character_controller *)this,
         *(int *)((char *)&dword_10E74 + a2)) )
  {
    vostok::physics::bt_character_controller::set_crouch(*v2, 0);
  }
}
