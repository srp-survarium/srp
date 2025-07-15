char __cdecl vostok::vfs::mount_overlapped_if_needed(
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *env)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  unsigned int v5; // esi
  unsigned int v6; // esi
  survarium::game_camera *v7; // ecx
  vostok::memory::base_allocator *v8; // eax
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx
  bool v11; // [esp+24Eh] [ebp-4Ah]
  vostok::vfs::async_callbacks_data *v12; // [esp+250h] [ebp-48h]
  vostok::vfs::vfs_locked_iterator v13; // [esp+258h] [ebp-40h] BYREF
  vostok::vfs::vfs_locked_iterator v14; // [esp+270h] [ebp-28h] BYREF
  vostok::vfs::async_callbacks_data *async_data; // [esp+284h] [ebp-14h]
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> mounts; // [esp+288h] [ebp-10h] BYREF

  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &mounts);
  survarium::weapon_user_dead_state::finalize(v2);
  mounts.m_first = 0;
  mounts.m_last = 0;
  v11 = vostok::strings::equal((const char *)(&env->vtable)[1], (const char *)env->functor.obj_ptr);
  if ( vostok::vfs::fill_nodes_to_expand_from_overlapped(
         (vostok::vfs::base_node<1> *)env[1].functor.bound_memfunc_ptr.obj_ptr,
         (vostok::vfs::base_node<1> *)env[1].functor.vostok_pointer_size_alignment[5],
         &mounts,
         (vostok::memory::base_allocator *)env[2].functor.obj_ptr,
         (vostok::vfs::find_enum)env[2].vtable,
         (vostok::vfs::traverse_enum)v11,
         1u) == 3 )
  {
    vostok::vfs::unlock_and_decref_branch(
      (vostok::vfs::base_node<1> *)env[1].functor.bound_memfunc_ptr.obj_ptr,
      lock_type_read,
      (unsigned int)env[2].functor.vostok_pointer_size_alignment[1]);
    vostok::vfs::vfs_iterator::vfs_iterator(&v14);
    v14.mount_operation_id = 0;
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)(&env->functor.data + 16),
      (const char *)&v14,
      (const vostok::network_core::udp_match_packet *)3);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v14);
    survarium::weapon_user_dead_state::finalize(v3);
    return 1;
  }
  else if ( mounts.m_first )
  {
    v5 = vostok::strings::length((const char *)(&env->vtable)[1]);
    v6 = v5 + vostok::strings::length((const char *)env->functor.obj_ptr) + 138;
    survarium::weapon_user_dead_state::finalize(v7);
    async_data = (vostok::vfs::async_callbacks_data *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                        v8,
                                                        v6);
    if ( async_data )
    {
      v12 = (vostok::vfs::async_callbacks_data *)operator new(0x88u, async_data);
      if ( v12 )
        vostok::vfs::async_callbacks_data::async_callbacks_data(v12, type_branch, env);
      vostok::vfs::query_expand_nodes(&mounts, async_data);
      vostok::vfs::free_nodes_to_expand(&mounts);
      survarium::weapon_user_dead_state::finalize(v10);
      return 1;
    }
    else
    {
      vostok::vfs::unlock_and_decref_branch(
        (vostok::vfs::base_node<1> *)env[1].functor.bound_memfunc_ptr.obj_ptr,
        lock_type_read,
        (unsigned int)env[2].functor.vostok_pointer_size_alignment[1]);
      vostok::vfs::vfs_iterator::vfs_iterator(&v13);
      v13.mount_operation_id = 0;
      boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
        (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)(&env->functor.data + 16),
        (const char *)&v13,
        (const vostok::network_core::udp_match_packet *)3);
      vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v13);
      survarium::weapon_user_dead_state::finalize(v9);
      return 1;
    }
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)1);
    return 0;
  }
}
