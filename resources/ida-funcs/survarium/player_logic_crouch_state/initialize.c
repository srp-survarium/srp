void __thiscall survarium::player_logic_crouch_state::initialize(survarium::player_logic_crouch_state *this)
{
  vostok::physics::bt_character_controller::set_crouch(
    *(vostok::physics::bt_character_controller **)((char *)&dword_10E74 + (unsigned int)this->m_user),
    1);
}
