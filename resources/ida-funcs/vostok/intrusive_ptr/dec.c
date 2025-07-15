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


void __thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::managed_intrusive_base::destroy(
        &this->m_object->vostok::resources::managed_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedDecrement(&this->m_object->m_reference_count) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec(
        vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *this)
{
  vostok::sound::sound_instance_proxy *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      this->m_object->free_object(this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object )
  {
    if ( !_InterlockedExchangeAdd(&this->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::vfs::vfs_intrusive_mount_base::destroy(this->m_object, this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(
        vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  if ( this->m_object
    && !vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>(&this->m_object->vostok::resources::unmanaged_intrusive_base) )
  {
    if ( this->m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        &this->m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy(
        &this->m_object->vostok::resources::unmanaged_intrusive_base,
        0);
  }
}
