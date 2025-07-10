void __thiscall vostok::vfs::query_mount_arguments::query_mount_arguments(
        vostok::vfs::query_mount_arguments *this,
        const vostok::vfs::query_mount_arguments *__that)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v2; // ecx

  vostok::fs_new::virtual_path_string::virtual_path_string(&this->virtual_path, &__that->virtual_path);
  vostok::fs_new::native_path_string::native_path_string(&this->physical_path, &__that->physical_path);
  vostok::fs_new::native_path_string::native_path_string(&this->archive_physical_path, &__that->archive_physical_path);
  vostok::fs_new::native_path_string::native_path_string(&this->fat_physical_path, &__that->fat_physical_path);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v2);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&this->callback,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)&__that->callback);
  this->asynchronous_device = __that->asynchronous_device;
  this->synchronous_device = __that->synchronous_device;
  this->allocator = __that->allocator;
  this->type = __that->type;
  this->watcher_enabled = __that->watcher_enabled;
  this->recursive = __that->recursive;
  this->lock_operation = __that->lock_operation;
  vostok::fixed_string<32>::fixed_string<32>(&this->descriptor, &__that->descriptor);
  this->mount_id = __that->mount_id;
  this->root_write_lock = __that->root_write_lock;
  this->submount_node = __that->submount_node;
  this->parent_of_submount_node = __that->parent_of_submount_node;
  this->mount_ptr = __that->mount_ptr;
  this->submount_type = __that->submount_type;
  this->unlock_after_mount = __that->unlock_after_mount;
}
