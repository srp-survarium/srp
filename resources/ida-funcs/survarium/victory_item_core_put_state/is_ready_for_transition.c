bool __thiscall survarium::victory_item_core_put_state::is_ready_for_transition(
        survarium::victory_item_core_put_state *this)
{
  return this->m_animation_has_been_ended;
}
