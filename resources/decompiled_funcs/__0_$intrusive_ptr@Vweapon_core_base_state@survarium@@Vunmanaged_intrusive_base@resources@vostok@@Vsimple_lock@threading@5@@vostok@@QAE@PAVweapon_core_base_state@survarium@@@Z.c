void __thiscall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::weapon_core_base_state *object)
{
  this->m_object = 0;
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}
