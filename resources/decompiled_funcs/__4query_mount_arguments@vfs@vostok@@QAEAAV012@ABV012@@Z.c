vostok::vfs::query_mount_arguments *__thiscall vostok::vfs::query_mount_arguments::operator=(
        vostok::vfs::query_mount_arguments *this,
        vostok::vfs::query_mount_arguments *__that)
{
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > v4; // [esp+10h] [ebp-3Ch] BYREF
  vostok::fixed_string<32> *p_fat_physical_path; // [esp+30h] [ebp-1Ch]
  vostok::fs_new::path_string_impl *v6; // [esp+34h] [ebp-18h]
  vostok::fixed_string<32> *p_archive_physical_path; // [esp+3Ch] [ebp-10h]
  vostok::fs_new::path_string_impl *v8; // [esp+40h] [ebp-Ch]
  vostok::fixed_string<32> *p_physical_path; // [esp+44h] [ebp-8h]
  vostok::fs_new::path_string_impl *v10; // [esp+48h] [ebp-4h]

  if ( this != __that )
    vostok::buffer_string::operator=((vostok::fixed_string<32> *)__that, (vostok::fixed_string<32> *)this);
  vostok::fs_new::path_string_impl::verify_self(&this->virtual_path);
  p_physical_path = (vostok::fixed_string<32> *)&__that->physical_path;
  v10 = &this->physical_path;
  if ( &this->physical_path != &__that->physical_path )
    vostok::buffer_string::operator=(p_physical_path, (vostok::fixed_string<32> *)v10);
  vostok::fs_new::path_string_impl::verify_self(v10);
  p_archive_physical_path = (vostok::fixed_string<32> *)&__that->archive_physical_path;
  v8 = &this->archive_physical_path;
  if ( &this->archive_physical_path != &__that->archive_physical_path )
    vostok::buffer_string::operator=(p_archive_physical_path, (vostok::fixed_string<32> *)v8);
  vostok::fs_new::path_string_impl::verify_self(v8);
  p_fat_physical_path = (vostok::fixed_string<32> *)&__that->fat_physical_path;
  v6 = &this->fat_physical_path;
  if ( &this->fat_physical_path != &__that->fat_physical_path )
    vostok::buffer_string::operator=(p_fat_physical_path, (vostok::fixed_string<32> *)v6);
  vostok::fs_new::path_string_impl::verify_self(v6);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
    &v4,
    (const boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *)&__that->callback);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v4,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&this->callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v4);
  this->asynchronous_device = __that->asynchronous_device;
  this->synchronous_device = __that->synchronous_device;
  this->allocator = __that->allocator;
  this->type = __that->type;
  this->watcher_enabled = __that->watcher_enabled;
  this->recursive = __that->recursive;
  this->lock_operation = __that->lock_operation;
  vostok::buffer_string::operator=(&__that->descriptor, &this->descriptor);
  this->mount_id = __that->mount_id;
  this->root_write_lock = __that->root_write_lock;
  this->submount_node = __that->submount_node;
  this->parent_of_submount_node = __that->parent_of_submount_node;
  this->mount_ptr = __that->mount_ptr;
  this->submount_type = __that->submount_type;
  this->unlock_after_mount = __that->unlock_after_mount;
  return this;
}
