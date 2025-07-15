void __thiscall survarium::weapon_core_throw_grenade_state::execute(survarium::weapon_core_throw_grenade_state *this)
{
  vostok::ai::fsm::tick((vostok::ai::fsm *)this, (int)&this->m_logic);
}
