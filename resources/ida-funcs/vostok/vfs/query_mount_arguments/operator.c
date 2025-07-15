vostok::vfs::query_mount_arguments *__usercall vostok::vfs::query_mount_arguments::operator=@<eax>(
        vostok::vfs::query_mount_arguments *this@<esi>,
        const vostok::vfs::query_mount_arguments *__that@<edi>)
{
  vostok::fixed_string<260>::operator=(&__that->virtual_path.m_string, &this->virtual_path.m_string);
  vostok::fixed_string<260>::operator=(&__that->physical_path.m_string, &this->physical_path.m_string);
  vostok::fixed_string<260>::operator=(&__that->archive_physical_path.m_string, &this->archive_physical_path.m_string);
  vostok::fixed_string<260>::operator=(&__that->fat_physical_path.m_string, &this->fat_physical_path.m_string);
  boost::function<void __cdecl (vostok::vfs::mount_result)>::operator=(
    &__that->callback,
    (boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *)&this->callback);
  this->asynchronous_device = __that->asynchronous_device;
  this->synchronous_device = __that->synchronous_device;
  this->allocator = __that->allocator;
  this->type = __that->type;
  this->watcher_enabled = __that->watcher_enabled;
  this->recursive = __that->recursive;
  this->lock_operation = __that->lock_operation;
  vostok::fixed_string<260>::operator=(
    (vostok::fixed_string<260> *)&__that->descriptor,
    (const vostok::fixed_string<260> *)&this->descriptor);
  this->mount_id = __that->mount_id;
  this->root_write_lock = __that->root_write_lock;
  this->submount_node = __that->submount_node;
  this->parent_of_submount_node = __that->parent_of_submount_node;
  this->mount_ptr = __that->mount_ptr;
  this->submount_type = __that->submount_type;
  this->unlock_after_mount = __that->unlock_after_mount;
  return this;
}
