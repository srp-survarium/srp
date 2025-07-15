void __thiscall survarium::booby_trap_set::action(
        survarium::booby_trap_set *this,
        bool key_down,
        unsigned int current_time_in_ms)
{
  survarium::booby_trap_set_core::action(this, key_down, current_time_in_ms);
  this->m_draw_ghost_model = key_down;
}
