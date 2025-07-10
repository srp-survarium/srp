void __thiscall vostok::vfs::async_callbacks_data::finish_branch_destroy_this(vostok::vfs::async_callbacks_data *this)
{
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> v1; // [esp-34h] [ebp-184h] BYREF
  vostok::vfs::find_enum v2; // [esp-14h] [ebp-164h]
  vostok::vfs::virtual_file_system *file_system; // [esp-10h] [ebp-160h]
  vostok::memory::base_allocator *allocator; // [esp-Ch] [ebp-15Ch]
  unsigned int mount_operation_id; // [esp-8h] [ebp-158h]
  unsigned int path_part_index; // [esp-4h] [ebp-154h]
  vostok::vfs::async_callbacks_data *thisa; // [esp+0h] [ebp-150h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v8; // [esp+130h] [ebp-20h]
  vostok::vfs::find_enum find_flags; // [esp+134h] [ebp-1Ch]
  vostok::vfs::vfs_locked_iterator v10; // [esp+138h] [ebp-18h] BYREF

  thisa = this;
  if ( this->result == result_error )
  {
    vostok::vfs::upgrade_branch(thisa->env.node, lock_type_write, lock_type_read);
    find_flags = thisa->env.find_flags.m_flags;
    path_part_index = thisa->env.path_part_index;
    mount_operation_id = thisa->env.mount_operation_id;
    allocator = thisa->env.allocator;
    file_system = thisa->env.file_system;
    v2 = find_flags;
    v8 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v1;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)find_flags,
      &v1);
    boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
      v8,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->env.callback);
    vostok::vfs::try_find_async(
      thisa->env.path_to_find,
      v1,
      v2,
      file_system,
      allocator,
      mount_operation_id,
      path_part_index);
  }
  else
  {
    vostok::vfs::unlock_and_decref_branch(thisa->env.node, lock_type_write, thisa->env.mount_operation_id);
    vostok::vfs::vfs_iterator::vfs_iterator(&v10);
    v10.mount_operation_id = 0;
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&thisa->env.callback,
      (const char *)&v10,
      (const vostok::network_core::udp_match_packet *)thisa->result);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v10);
  }
  vostok::vfs::async_callbacks_data::delete_this(thisa);
}
