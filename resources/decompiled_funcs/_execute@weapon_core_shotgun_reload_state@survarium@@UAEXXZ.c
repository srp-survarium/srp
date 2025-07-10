void __thiscall survarium::weapon_core_shotgun_reload_state::execute(survarium::weapon_core_shotgun_reload_state *this)
{
  vostok::ai::fsm::tick(this->m_logic);
}
