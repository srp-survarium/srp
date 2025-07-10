vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object)
{
  survarium::weapon_user_animations_container *m_object; // [esp+Ch] [ebp-Ch]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+14h] [ebp-4h] BYREF

  v5.m_object = 0;
  if ( object->m_object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
    v5.m_object = object->m_object;
    if ( v5.m_object )
      vostok::threading::interlocked_increment(&v5.m_object->vostok::resources::unmanaged_intrusive_base);
  }
  m_object = v5.m_object;
  v5.m_object = this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  return this;
}
