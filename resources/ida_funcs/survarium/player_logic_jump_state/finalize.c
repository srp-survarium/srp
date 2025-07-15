void __thiscall survarium::player_logic_jump_state::finalize(survarium::player_logic_jump_state *this)
{
  survarium::jump_logic::deactivate(&this->m_logic);
}
