bool __thiscall survarium::weapon_core_throw_grenade_state::test_input_throw_action(
        survarium::weapon_core_throw_grenade_state *this,
        bool eq_value)
{
  return eq_value == survarium::player_input::is_throwing_grenade(
                       (survarium::player_input *)this->m_weapon->m_user->m_inventory.m_object->m_grenade_slot,
                       (int)&this->m_weapon->m_user->m_input);
}
