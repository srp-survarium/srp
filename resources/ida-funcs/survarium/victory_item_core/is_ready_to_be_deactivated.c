BOOL __thiscall survarium::victory_item_core::is_ready_to_be_deactivated(survarium::victory_item_core *this)
{
  return ((unsigned __int8 (__thiscall *)(vostok::ai::fsm_state *))this->m_logic.m_current_state->__vftable[1].initialize)(this->m_logic.m_current_state)
      && *(&this->m_portable_interactive_object->m_user_animations_selector.m_logic.m_current_state[1].transitions.gap4
         + 3);
}
