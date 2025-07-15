void __usercall vostok::physics::bt_character_controller::set_crouch(
        vostok::physics::bt_character_controller *this@<ecx>,
        bool crouch@<al>)
{
  vostok::physics::old_bullet_character_controller *m_old_controller; // esi

  if ( s_cc_use_old_controller_value )
  {
    m_old_controller = this->m_old_controller;
    if ( crouch != m_old_controller->m_in_crouch )
    {
      if ( crouch )
      {
        vostok::physics::old_bullet_character_controller::setup_crouch_state(1, m_old_controller, 1);
      }
      else if ( vostok::physics::old_bullet_character_controller::can_stand(
                  (vostok::physics::old_bullet_character_controller *)this,
                  (int)this->m_old_controller) )
      {
        vostok::physics::old_bullet_character_controller::setup_crouch_state(0, m_old_controller, 1);
      }
    }
  }
  else
  {
    this->m_bt_controller->m_logic_is_in_crouch = crouch;
  }
}
