void __usercall vostok::physics::bt_character_controller::jump(
        vostok::physics::bt_character_controller *this@<ecx>,
        int *a2@<eax>)
{
  vostok::physics::bullet_character_controller::jump((vostok::physics::bullet_character_controller *)this, *a2);
}
