survarium::artefact_container *__thiscall survarium::artefact_container::`vector deleting destructor'(
        survarium::artefact_container *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_artefact);
  survarium::usable_object::~usable_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
