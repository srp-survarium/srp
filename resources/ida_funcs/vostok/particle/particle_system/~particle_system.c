void __thiscall vostok::particle::particle_system::~particle_system(vostok::particle::particle_system *this)
{
  this->__vftable = (vostok::particle::particle_system_vtbl *)&vostok::particle::particle_system::`vftable';
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_lods);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
