void __usercall vostok::physics::bt_character_controller::deactivate(
        vostok::physics::bt_character_controller *this@<ecx>,
        vostok::physics::bullet_character_controller **a2@<eax>)
{
  vostok::physics::bullet_character_controller::remove(*a2, *a2);
}
