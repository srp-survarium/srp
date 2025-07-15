vostok::particle::particle_system *__thiscall vostok::particle::particle_system::`scalar deleting destructor'(
        vostok::particle::particle_system *this,
        char a2)
{
  this->__vftable = (vostok::particle::particle_system_vtbl *)&vostok::particle::particle_system::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
