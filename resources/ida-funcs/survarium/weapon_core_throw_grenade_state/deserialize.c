void __thiscall survarium::weapon_core_throw_grenade_state::deserialize(
        survarium::weapon_core_throw_grenade_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  survarium::weapon_core_throw_grenade_state *v4; // ecx

  survarium::weapon_core_base_state::deserialize(this, reader, client_reader);
  vostok::ai::fsm::deserialize(&this->m_logic, reader, client_reader);
  if ( !this->m_grenade_set.m_object )
    survarium::weapon_core_throw_grenade_state::attach_grenade(
      v4,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
}
