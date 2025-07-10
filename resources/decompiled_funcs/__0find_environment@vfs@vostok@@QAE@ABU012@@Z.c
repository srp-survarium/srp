void __thiscall vostok::vfs::find_environment::find_environment(
        vostok::vfs::find_environment *this,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *__that)
{
  boost::function1<void,enum vostok::handshaking_error_types_enum> *p_callback; // [esp+4h] [ebp-4h]

  this->find_results = (vostok::vfs::find_struct *)__that->vtable;
  this->path_to_find = (const char *)(&__that->vtable)[1];
  this->partial_path = (const char *)__that->functor.obj_ptr;
  this->path_part_index = (unsigned int)__that->functor.vostok_pointer_size_alignment[1];
  this->out_iterator = (vostok::vfs::vfs_locked_iterator *)__that->functor.vostok_pointer_size_alignment[2];
  p_callback = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&this->callback;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(__that);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    p_callback,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)(&__that->functor.data + 16));
  this->node = (vostok::vfs::base_node<1> *)__that[1].functor.bound_memfunc_ptr.obj_ptr;
  this->node_parent = (vostok::vfs::base_node<1> *)__that[1].functor.vostok_pointer_size_alignment[5];
  this->find_flags.m_flags = (unsigned int)__that[2].vtable;
  this->file_system = (vostok::vfs::virtual_file_system *)(&__that[2].vtable)[1];
  this->allocator = (vostok::memory::base_allocator *)__that[2].functor.obj_ptr;
  this->mount_operation_id = (unsigned int)__that[2].functor.vostok_pointer_size_alignment[1];
}
