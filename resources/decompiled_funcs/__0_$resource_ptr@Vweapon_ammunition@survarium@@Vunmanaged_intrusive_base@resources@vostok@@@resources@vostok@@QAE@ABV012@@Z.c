void __thiscall vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *other)
{
  this->m_object = 0;
  if ( this->m_object != other->m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = other->m_object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}
