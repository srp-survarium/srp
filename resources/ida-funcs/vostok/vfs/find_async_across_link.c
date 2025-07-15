void __usercall vostok::vfs::find_async_across_link(vostok::vfs::find_environment *env@<edi>)
{
  unsigned int v1; // kr00_4
  char *v2; // ebx
  vostok::vfs::vfs_locked_iterator *v3; // ecx
  vostok::vfs::virtual_file_system *file_system; // esi
  char *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_link_helper,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_link_helper *>,boost::arg<1>,boost::arg<2> > > v8; // [esp-40h] [ebp-190h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v9; // [esp-34h] [ebp-184h] BYREF
  unsigned int v10; // [esp-14h] [ebp-164h]
  vostok::vfs::virtual_file_system *v11; // [esp-10h] [ebp-160h]
  vostok::memory::base_allocator *v12; // [esp-Ch] [ebp-15Ch]
  unsigned int v13; // [esp-8h] [ebp-158h]
  unsigned int v14; // [esp-4h] [ebp-154h]
  vostok::fs_new::virtual_path_string v15; // [esp+8h] [ebp-148h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+120h] [ebp-30h] BYREF
  vostok::vfs::base_node<1> *node; // [esp+140h] [ebp-10h]
  unsigned int mount_operation_id; // [esp+144h] [ebp-Ch]
  vostok::memory::base_allocator *allocator; // [esp+148h] [ebp-8h]
  char *m_flags; // [esp+14Ch] [ebp-4h]

  v15.m_string.m_begin = v15.m_string.m_buffer;
  v15.m_string.m_end = v15.m_string.m_buffer;
  v15.m_string.m_max_end = &v15.m_separator;
  v15.m_string.m_buffer[0] = 0;
  v15.m_separator = 47;
  vostok::vfs::find_link_target_path<1>(&v15);
  v1 = strlen(env->partial_path);
  vostok::buffer_string::append(
    (vostok::buffer_string *)&env->path_to_find[v1],
    (int)&v15,
    (char *)&env->path_to_find[v1]);
  v2 = (char *)env->allocator->call_malloc(
                 env->allocator,
                 v15.m_string.m_end - v15.m_string.m_begin + 65,
                 "async_link_helper",
                 "vostok::vfs::find_async_across_link",
                 ".\\find_async_link.cpp",
                 69);
  if ( v2 )
  {
    file_system = env->file_system;
    m_flags = (char *)env->find_flags.m_flags;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&env->callback,
      &f);
    allocator = env->allocator;
    mount_operation_id = env->mount_operation_id;
    node = env->node;
    boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
      &f,
      (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v2);
    *((_DWORD *)v2 + 8) = node;
    *((_DWORD *)v2 + 9) = mount_operation_id;
    *((_DWORD *)v2 + 10) = allocator;
    v5 = m_flags;
    *((_DWORD *)v2 + 14) = &file_system->hashset;
    *((_DWORD *)v2 + 13) = v5;
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
    m_flags = v2 + 60;
    vostok::strings::copy(v2 + 60, v15.m_string.m_end - v15.m_string.m_begin + 1, v15.m_string.m_begin);
    v14 = -1;
    v13 = 0;
    v12 = env->allocator;
    v11 = env->file_system;
    v10 = *((_DWORD *)v2 + 13);
    v8.l_.a1_.t_ = (vostok::vfs::async_link_helper *)v2;
    v8.f_.f_ = (void (__thiscall *)(vostok::vfs::async_link_helper *, const vostok::vfs::vfs_locked_iterator *, vostok::vfs::result_enum))vostok::vfs::async_link_helper::on_link_received;
    boost::function<void __cdecl (vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)>::function<void __cdecl (vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)>(
      v7,
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_link_helper,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_link_helper *>,boost::arg<1>,boost::arg<2> > > *)&v9,
      v8,
      (int)v7);
    vostok::vfs::try_find_async(m_flags, v9, v10, v11, v12, v13, v14);
  }
  else
  {
    vostok::vfs::unlock_and_decref_branch(env->node, lock_type_read, env->mount_operation_id);
    memset((char *)&f.functor.bound_memfunc_ptr.memfunc_ptr + 4, 0, 20);
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)v14,
      &env->callback.vtable,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&f.functor.bound_memfunc_ptr.memfunc_ptr
    + 1,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)3);
    vostok::vfs::vfs_locked_iterator::clear(v3, (int)&f.functor.vostok_pointer_size_alignment[1]);
  }
}
