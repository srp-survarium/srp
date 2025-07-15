void __thiscall survarium::player_logic_jump_state::initialize(survarium::player_logic_jump_state *this)
{
  survarium::game_camera *v1; // ecx

  survarium::jump_logic::activate(&this->m_logic);
  survarium::weapon_user_dead_state::finalize(v1);
}
