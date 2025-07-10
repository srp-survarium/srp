vostok::resources::vfs_sub_fat_resource *__thiscall vostok::resources::vfs_sub_fat_resource::`scalar deleting destructor'(
        vostok::resources::vfs_sub_fat_resource *this,
        char a2)
{
  vostok::resources::vfs_sub_fat_resource *m_object; // eax

  m_object = this->parent.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->parent.m_object->vostok::resources::unmanaged_intrusive_base,
      this->parent.m_object);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&this->mount_ptr);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
