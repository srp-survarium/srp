void __thiscall survarium::player_logic_crouch_state::finalize(survarium::player_logic_crouch_state *this)
{
  survarium::base_player::stand_up((survarium::base_player *)this, (int)this->m_user);
}
