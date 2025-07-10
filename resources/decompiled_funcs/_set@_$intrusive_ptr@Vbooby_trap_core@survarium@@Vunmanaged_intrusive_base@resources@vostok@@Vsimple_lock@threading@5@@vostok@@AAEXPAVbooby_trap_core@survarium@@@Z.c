void __thiscall vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::booby_trap_core *object)
{
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}
