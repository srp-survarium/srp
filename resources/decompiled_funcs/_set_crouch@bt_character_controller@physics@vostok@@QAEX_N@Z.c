void __usercall vostok::physics::bt_character_controller::set_crouch(
        vostok::physics::bt_character_controller *this@<ecx>,
        bool crouch@<al>)
{
  vostok::physics::bullet_character_controller::set_crouch(this->m_bt_controller, crouch);
}
