void __thiscall survarium::player_logic_crouch_state::finalize(survarium::player_logic_crouch_state *this)
{
  ((void (__thiscall *)(survarium::base_player *, survarium::player_logic_crouch_state *))this->m_user->stand_up)(
    this->m_user,
    this);
}
