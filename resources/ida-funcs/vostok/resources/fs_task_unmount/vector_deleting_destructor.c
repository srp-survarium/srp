vostok::resources::fs_task_unmount *__thiscall vostok::resources::fs_task_unmount::`vector deleting destructor'(
        vostok::resources::fs_task_unmount *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec(&this->m_next);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_sub_fat_ptr);
  this->__vftable = (vostok::resources::fs_task_unmount_vtbl *)&vostok::resources::fs_task::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
