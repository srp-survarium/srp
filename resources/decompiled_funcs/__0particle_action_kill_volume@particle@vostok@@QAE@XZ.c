void __thiscall vostok::particle::particle_action_kill_volume::particle_action_kill_volume(
        vostok::particle::particle_action_kill_volume *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->__vftable = (vostok::particle::particle_action_kill_volume_vtbl *)&vostok::particle::particle_action::`vftable';
  this->m_next.pointer = 0;
  HIDWORD(this->m_next.max_storage) = 0;
  this->m_next.pointer = 0;
  this->__vftable = (vostok::particle::particle_action_kill_volume_vtbl *)&vostok::particle::particle_modifier::`vftable';
  this->__vftable = (vostok::particle::particle_action_kill_volume_vtbl *)&vostok::particle::particle_action_kill_volume::`vftable';
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_domain);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_domain);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_domain.m_inv_transform);
}
