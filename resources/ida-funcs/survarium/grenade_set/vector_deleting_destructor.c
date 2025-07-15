survarium::grenade_set *__thiscall survarium::grenade_set::`vector deleting destructor'(
        survarium::grenade_set *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_preview_model);
  survarium::grenade_set_core::~grenade_set_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
