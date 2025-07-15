void __userpurge vostok::vfs::vfs_intrusive_mount_base::destroy(
        vostok::vfs::vfs_intrusive_mount_base *this@<ecx>,
        survarium::game_camera object)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  vostok::threading::simple_lock *v5; // ecx
  survarium::game_camera *v6; // ecx
  vostok::memory::base_allocator *v7; // eax
  BOOL v8; // ecx
  bool v9; // al
  BOOL v10; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // ecx
  survarium::game_camera *v13; // ecx
  vostok::fs_new::asynchronous_device_interface *v14; // ecx
  vostok::memory::base_allocator *v15; // eax
  _BYTE v16[44]; // [esp-2Ch] [ebp-15C4h] BYREF
  survarium::game_camera_vtbl *v17; // [esp+4h] [ebp-1594h]
  char v18; // [esp+Bh] [ebp-158Dh]
  vostok::vfs::unmounter v19; // [esp+Ch] [ebp-158Ch] BYREF
  vostok::vfs::query_mount_arguments *v20; // [esp+1Ch] [ebp-157Ch]
  vostok::vfs::query_mount_arguments v21; // [esp+20h] [ebp-1578h] BYREF
  boost::function<bool __cdecl(void)> *v22; // [esp+4F8h] [ebp-10A0h]
  vostok::fs_new::path_string_impl v23; // [esp+4FCh] [ebp-109Ch] BYREF
  vostok::fs_new::path_string_impl v24; // [esp+610h] [ebp-F88h] BYREF
  vostok::vfs::query_mount_arguments *__that; // [esp+724h] [ebp-E74h]
  vostok::vfs::query_mount_arguments result; // [esp+728h] [ebp-E70h] BYREF
  boost::function<bool __cdecl(void)> *v27; // [esp+C04h] [ebp-994h]
  vostok::fs_new::path_string_impl v28; // [esp+C08h] [ebp-990h] BYREF
  vostok::fs_new::path_string_impl v29; // [esp+D1Ch] [ebp-87Ch] BYREF
  vostok::fs_new::path_string_impl v30; // [esp+E30h] [ebp-768h] BYREF
  vostok::vfs::archive_folder_mount_root_node<1> *v31; // [esp+F44h] [ebp-654h]
  vostok::fs_new::asynchronous_device_interface async_device; // [esp+F48h] [ebp-650h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v33; // [esp+1010h] [ebp-588h] BYREF
  survarium::game_camera_vtbl *v34; // [esp+1030h] [ebp-568h]
  char v35; // [esp+1037h] [ebp-561h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v36; // [esp+1038h] [ebp-560h] BYREF
  vostok::vfs::base_node<1> *out_locked_branch; // [esp+105Ch] [ebp-53Ch] BYREF
  vostok::vfs::query_mount_arguments m_args; // [esp+1060h] [ebp-538h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+1538h] [ebp-60h] BYREF
  vostok::memory::detail::call_destructor_predicate v40; // [esp+155Bh] [ebp-3Dh] BYREF
  vostok::memory::base_allocator *v41; // [esp+155Ch] [ebp-3Ch]
  survarium::game_camera_vtbl *v42; // [esp+1560h] [ebp-38h]
  vostok::threading::simple_lock::mutex_raii v43; // [esp+1564h] [ebp-34h] BYREF
  vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy> *p_mount_history; // [esp+156Ch] [ebp-2Ch]
  vostok::vfs::virtual_file_system *__formal; // [esp+1570h] [ebp-28h]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+1577h] [ebp-21h] BYREF
  vostok::memory::base_allocator *allocator; // [esp+1578h] [ebp-20h]
  char v48; // [esp+157Fh] [ebp-19h]
  signed __int32 v49; // [esp+1580h] [ebp-18h]
  survarium::game_camera_vtbl *v50; // [esp+1584h] [ebp-14h]
  void (__thiscall *tick)(survarium::game_camera *); // [esp+1588h] [ebp-10h]
  vostok::vfs::mount_root_node_base<1> *node; // [esp+158Ch] [ebp-Ch]
  int v53; // [esp+1590h] [ebp-8h]
  vostok::vfs::vfs_intrusive_mount_base *v54; // [esp+1594h] [ebp-4h]

  v54 = this;
  v53 = 0;
  node = (vostok::vfs::mount_root_node_base<1> *)object.__vftable[2].on_focus;
  tick = object.__vftable[2].tick;
  if ( node )
  {
    __formal = node->file_system.pointer;
    vostok::vfs::vfs_intrusive_mount_base::unlink_children(v54, (vostok::vfs::vfs_mount *)object.__vftable, __formal);
    p_mount_history = &__formal->mount_history;
    vostok::threading::simple_lock::mutex_raii::mutex_raii(&v43, &__formal->mount_history.m_policy, v5);
    if ( vostok::intrusive_double_linked_list<vostok::vfs::vfs_mount,vostok::vfs::vfs_mount *,16,12,vostok::threading::simple_lock,vostok::no_size_policy,vostok::debug_policy>::contains_object(
           p_mount_history,
           (vostok::vfs::vfs_mount *)object.__vftable) )
    {
      if ( *(_DWORD *)((char *)&loc_20160 + (_DWORD)__formal) == -1
        || *(_DWORD *)((char *)&loc_20160 + (_DWORD)__formal) == vostok::threading::current_thread_id() )
      {
        vostok::vfs::query_mount_arguments::query_mount_arguments(&m_args);
        out_locked_branch = 0;
        if ( vostok::vfs::vfs_hashset::find_and_lock_branch(
               &__formal->hashset,
               &out_locked_branch,
               (const char *)&buf,
               lock_type_write,
               lock_operation_try_lock) )
        {
          v35 = 0;
          survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v10);
          v34 = object.__vftable;
          if ( object.get_projection_matrix )
          {
            if ( !vostok::core::g_log_filter_tree
              || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info) )
            {
              boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v12);
              v53 |= 4u;
              *(vostok::platform_pointer_selector<char const ,1>::helper *)&v16[36] = (vostok::platform_pointer_selector<char const ,1>::helper)node->virtual_path.max_storage;
              vostok::logging::append(
                &v33,
                (void *const)vostok::core::g_log_flags,
                &vostok::core::g_log_format,
                ".\\mount_ptr.cpp",
                0x7Eu,
                "void __thiscall vostok::vfs::vfs_intrusive_mount_base::destroy(class vostok::vfs::vfs_mount *) const",
                "vfs:",
                info,
                "unmount canceled (mount-reclaimed) '%s' on '%s'",
                node->physical_path.pointer,
                (const char *)HIDWORD(node->physical_path.max_storage));
            }
            if ( (v53 & 4) != 0 )
            {
              v53 &= ~4u;
              boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
                (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v12,
                (int *)&v33);
            }
            vostok::vfs::unlock_branch(m_args.root_write_lock, lock_type_write);
            boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&m_args.callback);
            vostok::threading::simple_lock::mutex_raii::clear(&v43);
          }
          else
          {
            vostok::vfs::erase_from_mount_history((vostok::vfs::vfs_mount *)object.__vftable, __formal);
            vostok::threading::simple_lock::mutex_raii::clear(&v43);
            vostok::fs_new::asynchronous_device_interface::asynchronous_device_interface(
              &async_device,
              node->device.pointer,
              watcher_enabled_true);
            if ( node->mount_type == mount_type_archive )
            {
              v31 = vostok::vfs::node_cast<vostok::vfs::archive_folder_mount_root_node,vostok::vfs::mount_root_node_base,1>(node);
              vostok::fs_new::path_string_impl::path_string_impl(&v30, 92, (const char (*)[1])v31->fat_path_holder);
              vostok::fs_new::path_string_impl::path_string_impl(&v29, 92, (const char (*)[1])v31->archive_path_holder);
              vostok::fs_new::path_string_impl::path_string_impl(
                &v28,
                47,
                (const vostok::platform_pointer_selector<char,1>::helper *)&node->virtual_path);
              *(_DWORD *)&v16[40] = 0;
              v27 = (boost::function<bool __cdecl(void)> *)&v16[8];
              boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>((boost::function<bool __cdecl(void)> *)&v16[8]);
              __that = vostok::vfs::query_mount_arguments::mount_archive(
                         &result,
                         node->allocator.pointer,
                         (const vostok::fs_new::virtual_path_string *)&v28,
                         (const vostok::fs_new::native_path_string *)&v29,
                         (const vostok::fs_new::native_path_string *)&v30,
                         v31->descriptor,
                         &async_device,
                         0,
                         *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)&v16[8],
                         *(vostok::vfs::lock_operation_enum *)&v16[40]);
              vostok::vfs::query_mount_arguments::operator=(&m_args, __that);
              boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&result.callback);
            }
            else
            {
              vostok::fs_new::path_string_impl::path_string_impl(
                &v24,
                92,
                (const vostok::platform_pointer_selector<char,1>::helper *)&node->physical_path);
              vostok::fs_new::path_string_impl::path_string_impl(
                &v23,
                47,
                (const vostok::platform_pointer_selector<char,1>::helper *)&node->virtual_path);
              *(_DWORD *)&v16[40] = node->watcher_enabled;
              *(_DWORD *)&v16[36] = 0;
              *(_DWORD *)&v16[32] = 1;
              v22 = (boost::function<bool __cdecl(void)> *)v16;
              boost::function1<void,vostok::ai::brain_unit const *>::function1<void,vostok::ai::brain_unit const *>((boost::function<bool __cdecl(void)> *)v16);
              v20 = vostok::vfs::query_mount_arguments::mount_physical_path(
                      &v21,
                      node->allocator.pointer,
                      (const vostok::fs_new::virtual_path_string *)&v23,
                      (const vostok::fs_new::native_path_string *)&v24,
                      node->descriptor.pointer,
                      &async_device,
                      0,
                      *(boost::function<void __cdecl(vostok::vfs::mount_result)> *)v16,
                      *(vostok::vfs::recursive_bool *)&v16[32],
                      *(vostok::vfs::lock_operation_enum *)&v16[36],
                      *(vostok::fs_new::watcher_enabled_bool *)&v16[40]);
              vostok::vfs::query_mount_arguments::operator=(&m_args, v20);
              boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v21.callback);
            }
            m_args.mount_ptr = (vostok::vfs::vfs_mount *)object.__vftable;
            m_args.root_write_lock = out_locked_branch;
            vostok::vfs::unmounter::unmounter(&v19, &m_args, __formal);
            v18 = 1;
            survarium::weapon_user_dead_state::finalize(v13);
            v17 = object.__vftable;
            if ( !vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>((vostok::resources::unmanaged_intrusive_base *)&object.__vftable[3]) )
            {
              *(_DWORD *)&v16[40] = &object;
              survarium::weapon_user_dead_state::finalize(&object);
              vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vfs::vfs_mount>(
                v15,
                *(vostok::vfs::vfs_mount ***)&v16[40]);
            }
            vostok::fs_new::asynchronous_device_interface::~asynchronous_device_interface(v14, (int)&async_device);
            boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&m_args.callback);
            vostok::threading::simple_lock::mutex_raii::clear(&v43);
          }
        }
        else
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info),
                v10 = has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v10);
            v53 |= 2u;
            vostok::logging::append(
              &v36,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\mount_ptr.cpp",
              0x74u,
              "void __thiscall vostok::vfs::vfs_intrusive_mount_base::destroy(class vostok::vfs::vfs_mount *) const",
              "vfs:",
              info,
              "rescheduling unmount (cannot lock) '%s' on '%s'",
              node->physical_path.pointer,
              node->virtual_path.pointer);
          }
          if ( (v53 & 2) != 0 )
          {
            v53 &= ~2u;
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v10,
              (int *)&v36);
          }
          *(_DWORD *)&v16[40] = 0;
          *(_DWORD *)&v16[36] = v10;
          vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v16[36],
            (vostok::vfs::vfs_mount *)object.__vftable);
          vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
            (vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)(&__formal->mount_history.gap0 + (_DWORD)&loc_20146 + 2),
            *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v16[36],
            *(bool **)&v16[40]);
          boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&m_args.callback);
          vostok::threading::simple_lock::mutex_raii::clear(&v43);
        }
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (v9 = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "vfs:", info), v8 = v9) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8);
          v53 |= 1u;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\mount_ptr.cpp",
            0x6Au,
            "void __thiscall vostok::vfs::vfs_intrusive_mount_base::destroy(class vostok::vfs::vfs_mount *) const",
            "vfs:",
            info,
            "rescheduling unmount (wrong thread) '%s' on '%s'",
            node->physical_path.pointer,
            node->virtual_path.pointer);
        }
        if ( (v53 & 1) != 0 )
        {
          v53 &= ~1u;
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v8,
            (int *)&log_callback);
        }
        *(_DWORD *)&v16[40] = 0;
        *(_DWORD *)&v16[36] = v8;
        vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
          (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v16[36],
          (vostok::vfs::vfs_mount *)object.__vftable);
        vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::vfs::vfs_mount,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,20,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)(&__formal->mount_history.gap0 + (_DWORD)&loc_20146 + 2),
          *(vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&v16[36],
          *(bool **)&v16[40]);
        vostok::threading::simple_lock::mutex_raii::clear(&v43);
      }
    }
    else
    {
      v42 = object.__vftable;
      if ( !vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>((vostok::resources::unmanaged_intrusive_base *)&object.__vftable[3]) )
      {
        survarium::weapon_user_dead_state::finalize(v6);
        v41 = v7;
        v40 = 0;
        *(_DWORD *)&v16[40] = &v40;
        vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::vfs::vfs_mount,vostok::memory::detail::call_destructor_predicate>(
          v7,
          (vostok::vfs::vfs_mount **)&object);
      }
      vostok::threading::simple_lock::mutex_raii::clear(&v43);
    }
  }
  else
  {
    v50 = object.__vftable;
    v49 = vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>((vostok::resources::unmanaged_intrusive_base *)&object.__vftable[3]);
    v48 = 0;
    survarium::weapon_user_dead_state::finalize(v2);
    survarium::weapon_user_dead_state::finalize(v3);
    allocator = v4;
    call_destructor_predicate = 0;
    *(_DWORD *)&v16[40] = &call_destructor_predicate;
    vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::vfs::vfs_mount,vostok::memory::detail::call_destructor_predicate>(
      v4,
      (vostok::vfs::vfs_mount **)&object);
  }
}
