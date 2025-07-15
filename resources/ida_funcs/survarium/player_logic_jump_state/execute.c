void __thiscall survarium::player_logic_jump_state::execute(survarium::player_logic_jump_state *this)
{
  survarium::jump_logic::tick(&this->m_logic);
}
