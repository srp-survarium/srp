void __thiscall survarium::player_logic_crouch_state::initialize(survarium::player_logic_crouch_state *this)
{
  ((void (__thiscall *)(survarium::base_player *, survarium::player_logic_crouch_state *))this->m_user->crouch)(
    this->m_user,
    this);
}
