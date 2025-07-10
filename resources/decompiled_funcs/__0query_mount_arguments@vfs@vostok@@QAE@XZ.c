void __thiscall vostok::vfs::query_mount_arguments::query_mount_arguments(vostok::vfs::query_mount_arguments *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx

  vostok::fs_new::virtual_path_string::virtual_path_string(&this->virtual_path);
  vostok::fs_new::native_path_string::native_path_string(&this->physical_path);
  vostok::fs_new::native_path_string::native_path_string(&this->archive_physical_path);
  vostok::fs_new::native_path_string::native_path_string(&this->fat_physical_path);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->callback.vtable);
  this->asynchronous_device = 0;
  this->synchronous_device = 0;
  this->allocator = 0;
  this->type = mount_type_unknown;
  this->watcher_enabled = watcher_enabled_true;
  vostok::fixed_string<32>::fixed_string<32>(&this->descriptor);
  this->mount_id = 0;
  this->root_write_lock = 0;
  this->submount_node = 0;
  this->parent_of_submount_node = 0;
  this->mount_ptr = 0;
  this->submount_type = submount_type_unset;
  this->unlock_after_mount = 1;
}
