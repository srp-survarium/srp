void __thiscall survarium::portable_interactive_object_core::initialize(
        survarium::portable_interactive_object_core *this)
{
  survarium::weapon_user_animations_selector::initialize(
    &this->m_user_animations_selector,
    &this->m_user_animations_selector.m_logic);
}
