vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<survarium::artefact_base,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        survarium::game_world_object *object)
{
  survarium::game_world_object *m_object; // [esp+Ch] [ebp-Ch]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v5; // [esp+14h] [ebp-4h] BYREF

  v5.m_object = 0;
  if ( object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
    v5.m_object = object;
    vostok::threading::interlocked_increment(&object->vostok::resources::unmanaged_intrusive_base);
  }
  m_object = v5.m_object;
  v5.m_object = (survarium::game_world_object *)this->m_object;
  this->m_object = (survarium::artefact_base *)m_object;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return this;
}
