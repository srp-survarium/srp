void __thiscall survarium::weapon_core_throw_grenade_state::initialize(
        survarium::weapon_core_throw_grenade_state *this)
{
  survarium::weapon_core_throw_grenade_state::attach_grenade(
    this,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  vostok::ai::fsm::set_initial_state(&this->m_logic, this->m_logic.m_states.m_first, ignore_current_state);
  this->m_body_part_mask_for_user = body_part_whole_body;
}
