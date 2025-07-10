void __thiscall survarium::player_logic_jump_state::set_user(
        survarium::player_logic_jump_state *this,
        survarium::base_player *user)
{
  survarium::player_logic_base_state::set_user(this, user);
  survarium::jump_logic::set_user(&this->m_logic, user);
}
