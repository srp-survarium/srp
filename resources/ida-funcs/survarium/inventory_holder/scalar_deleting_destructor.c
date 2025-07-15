survarium::inventory_holder *__thiscall survarium::inventory_holder::`scalar deleting destructor'(
        survarium::inventory_holder *this,
        char a2)
{
  this->__vftable = (survarium::inventory_holder_vtbl *)&survarium::inventory_holder::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_inventory);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
