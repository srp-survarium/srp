void __usercall vostok::resources::resources_manager::~resources_manager(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::memory::doug_lea_allocator *v3; // ecx
  boost::intrusive::rbtree_node<void *> *v4; // esi
  boost::intrusive::rbtree_node<void *> *v5; // eax
  vostok::resources::thread_local_data *v6; // ecx
  boost::intrusive::rbtree_node<void *>::color *p_color; // ebp
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  void (__cdecl *v12)(char *, char *, int); // eax
  char *v13; // eax
  vostok::resources::intrusive_fs_task_unmount_base *v14; // [esp+0h] [ebp-1Ch]

  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    if ( !vostok::memory::g_use_resources_manager )
      goto LABEL_8;
    vostok::memory::doug_lea_allocator::user_current_thread_id(
      (vostok::memory::doug_lea_allocator *)this,
      (int)&vostok::memory::g_resources_helper_allocator);
    vostok::memory::doug_lea_allocator::user_current_thread_id(
      v3,
      (int)&vostok::memory::g_resources_unmanaged_allocator);
  }
  if ( vostok::memory::g_use_resources_manager )
    vostok::memory::managed_allocator_base::dump_resource_leaks(
      (vostok::memory::managed_allocator_base *)this,
      &vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base);
LABEL_8:
  vostok::resources::resources_manager::finalize_name_registry(this, a2);
  v4 = (boost::intrusive::rbtree_node<void *> *)((char *)&dword_203B8 + a2);
  while ( 1 )
  {
    v5 = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::unlink_leftmost_without_rebalance(v4);
    if ( !v5 )
      break;
    p_color = &v5[-39].color_;
    v5->parent_ = 0;
    v5->left_ = 0;
    v5->right_ = 0;
    if ( v5 == (boost::intrusive::rbtree_node<void *> *)612 )
      break;
    v8 = *((_DWORD *)p_color + 151);
    vostok::resources::thread_local_data::~thread_local_data(v6, (int)&v5[-39].color_);
    (*(void (__thiscall **)(int, boost::intrusive::rbtree_node<void *>::color *))(*(_DWORD *)v8 + 24))(v8, p_color);
  }
  vostok::uninitialized_reference<vostok::resources::hdd_manager>::destroy((vostok::uninitialized_reference<vostok::resources::hdd_manager> *)v6);
  TlsFree(*(int *)((char *)&dword_203C8 + a2));
  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)((char *)&loc_20586 + a2 + 2) + 8))(
    *(_DWORD *)((char *)&loc_20586 + a2 + 2),
    0);
  *(_DWORD *)((char *)&loc_2058C + a2) = 0;
  v9 = *(_DWORD *)(a2 + 264172);
  if ( v9 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 28), 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(
      v14,
      *(vostok::resources::fs_task_unmount **)(a2 + 264172));
  v10 = *(_DWORD *)(a2 + 264168);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 28), 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(
      v14,
      *(vostok::resources::fs_task_unmount **)(a2 + 264168));
  vostok::vfs::virtual_file_system::~virtual_file_system((vostok::vfs::virtual_file_system *)((char *)&loc_20600 + a2));
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface((vostok::fs_new::synchronous_device_interface *)((char *)&loc_205EB + a2 + 1));
  v11 = *(int *)((char *)&dword_205B0 + a2);
  if ( v11 )
  {
    if ( (v11 & 1) == 0 )
    {
      v12 = *(void (__cdecl **)(char *, char *, int))(v11 & 0xFFFFFFFE);
      if ( v12 )
        v12((char *)&loc_205B6 + a2 + 2, (char *)&loc_205B6 + a2 + 2, 2);
    }
    *(int *)((char *)&dword_205B0 + a2) = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20596 + a2 + 2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,bool>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<bool>>>>::manage_small
                                           + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_2051C + a2 + 4));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,long volatile *>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<long volatile *>>>>::manage_small
                                           + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_204DD + a2 + 3));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_204B7 + a2 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20486 + a2 + 2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20456 + a2 + 2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20426 + a2 + 2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)nullsub_154 + a2));
  CloseHandle(*(HANDLE *)((char *)&dword_203E0 + a2));
  CloseHandle(*(HANDLE *)((char *)&dword_203D0 + a2));
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::clear_and_dispose<boost::intrusive::detail::node_disposer<boost::intrusive::detail::null_disposer,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0>>>>(v4);
  v4->parent_ = 0;
  v4->left_ = v4;
  v4->right_ = v4;
  v4->color_ = red_t;
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)dword_20388 + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_2034F + a2 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *>>>>::manage_small
                                           + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_202EF + a2 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_202C0 + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20290 + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20260 + a2));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20230 + a2));
  v13 = *(char **)((char *)&loc_201FF + a2 + 1);
  if ( v13 )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free((malloc_state *)vostok::memory::g_resources_helper_allocator.m_arena, v13);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&byte_201E8[a2]);
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_201BF + a2 + 1));
  DeleteCriticalSection((LPCRITICAL_SECTION)((char *)&loc_20186 + a2 + 2));
  DeleteCriticalSection((LPCRITICAL_SECTION)&byte_20168[a2]);
  memset(a2 + 352, 0, (unsigned int)&loc_20000);
  *(_DWORD *)((char *)&loc_20160 + a2) = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 304));
}
