void __thiscall survarium::victory_item_core::update_logic(survarium::victory_item_core *this)
{
  survarium::weapon_user_animations_selector *v2; // ecx

  vostok::ai::fsm::tick((vostok::ai::fsm *)this, (int)&this->m_logic);
  survarium::weapon_user_animations_selector::tick(
    v2,
    (int)&this->m_portable_interactive_object->m_user_animations_selector);
}
