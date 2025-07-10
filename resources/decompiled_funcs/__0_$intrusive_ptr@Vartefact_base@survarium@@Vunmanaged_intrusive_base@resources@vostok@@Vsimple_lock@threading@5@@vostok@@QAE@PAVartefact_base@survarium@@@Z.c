void __thiscall vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::artefact_base *object)
{
  this->m_object = 0;
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}
