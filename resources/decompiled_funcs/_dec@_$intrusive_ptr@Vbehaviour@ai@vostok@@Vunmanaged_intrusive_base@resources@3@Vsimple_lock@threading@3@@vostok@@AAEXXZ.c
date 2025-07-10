void __thiscall vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>(&this->m_object->vostok::resources::unmanaged_intrusive_base) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}
