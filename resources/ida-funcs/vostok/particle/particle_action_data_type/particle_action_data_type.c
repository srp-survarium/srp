void __thiscall vostok::particle::particle_action_data_type::particle_action_data_type(
        vostok::particle::particle_action_data_type *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action::`vftable';
  this->m_next.pointer = 0;
  HIDWORD(this->m_next.max_storage) = 0;
  this->m_next.pointer = 0;
  this->__vftable = (vostok::particle::particle_action_data_type_vtbl *)&vostok::particle::particle_action_data_type::`vftable';
}
