void __cdecl vostok::vfs::dispatch_ready_referers_list()
{
  survarium::game_camera *v0; // ecx
  vostok::memory::base_allocator *v1; // eax
  vostok::vfs::mount_result v2[2]; // [esp-8h] [ebp-194h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v3; // [esp+8h] [ebp-184h]
  vostok::memory::base_allocator *v4; // [esp+Ch] [ebp-180h]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+1Fh] [ebp-16Dh] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v6; // [esp+154h] [ebp-38h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+158h] [ebp-34h] BYREF
  vostok::vfs::mount_referer *referer; // [esp+180h] [ebp-Ch] BYREF
  vostok::memory::base_allocator *allocator; // [esp+184h] [ebp-8h]
  vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *list; // [esp+188h] [ebp-4h]

  list = (vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)vostok::vfs::get_ready_referers_list(0);
  if ( list )
  {
    while ( list->m_first )
    {
      referer = vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(list);
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &other,
        &referer->result);
      v6 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v2;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
        &v2[0].mount,
        &other);
      v6[1].m_object = (vostok::vfs::vfs_mount *)1;
      vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
      v3 = v6;
      boost::function1<void,vostok::vfs::mount_result>::operator()(&referer->callback, v2[0]);
      allocator = referer->allocator;
      survarium::weapon_user_dead_state::finalize(v0);
      v4 = v1;
      call_destructor_predicate = 0;
      v2[0].result = (vostok::vfs::result_enum)&call_destructor_predicate;
      vostok::memory::detail::delete_helper_impl<vostok::memory::base_allocator,vostok::vfs::mount_referer,vostok::memory::detail::call_destructor_predicate>(
        v1,
        (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> **)&referer);
    }
  }
}
