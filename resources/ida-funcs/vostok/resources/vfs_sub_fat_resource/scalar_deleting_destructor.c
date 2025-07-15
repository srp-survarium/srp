vostok::resources::vfs_sub_fat_resource *__thiscall vostok::resources::vfs_sub_fat_resource::`scalar deleting destructor'(
        vostok::resources::vfs_sub_fat_resource *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->parent);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&this->mount_ptr);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
