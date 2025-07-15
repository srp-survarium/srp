void __userpurge survarium::portable_interactive_object::on_weapon_user_sprint(
        survarium::portable_interactive_object *this@<ecx>,
        unsigned int a2@<esi>,
        const bool is_double_handed,
        const bool user_is_sprinting)
{
  char v4; // dl

  v4 = is_double_handed || !user_is_sprinting;
  vostok::animation::hand_to_weapon_ik_solver::activate_hand(
    left,
    v4,
    &this->m_hand_ik_solver,
    ik_locator_id_idle,
    this->m_user->m_current_time_in_ms,
    a2);
}
