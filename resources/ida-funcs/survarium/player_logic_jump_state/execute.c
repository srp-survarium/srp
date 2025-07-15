void __thiscall survarium::player_logic_jump_state::execute(survarium::player_logic_jump_state *this)
{
  vostok::ai::fsm::tick((vostok::ai::fsm *)this, (int)&this->m_logic);
}
