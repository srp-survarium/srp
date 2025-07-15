bool __thiscall survarium::victory_item_core::put_predicate(survarium::victory_item_core *this)
{
  return this->m_user->m_current_active_object != this->m_user->m_target_active_object;
}
