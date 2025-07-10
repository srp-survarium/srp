// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::resources::fs_task_unmount::unmount_children(
        vostok::resources::fs_task_unmount *this@<ecx>,
        double a2@<st0>,
        vostok::vfs::vfs_mount *sub_fat)
{
  vostok::vfs::vfs_mount *v3; // esi
  unsigned int m_size; // edi
  void *v5; // esp
  vostok::math::float4x4 *p_m_inverted_view_matrix; // ebx
  vostok::vfs::vfs_mount *m_object; // eax
  vostok::vfs::vfs_mount *v8; // esi
  vostok::vfs::vfs_mount *v9; // eax
  vostok::vfs::vfs_mount *v10; // ecx
  survarium::game_camera_vtbl *v11; // eax
  unsigned int i; // esi
  vostok::resources::vfs_sub_fat_resource *user_data; // edi
  vostok::resources::game_resources_manager *m_variable; // ebx
  vostok::resources::game_resources_manager *v16; // eax
  vostok::resources::game_resources_manager *m_current_time_high; // esi
  survarium::game_camera _FFFFFFFC; // [esp-4h] [ebp-50h] OVERLAPPED BYREF

  v3 = sub_fat;
  m_size = sub_fat->children.m_size;
  _FFFFFFFC.m_game_scene = (survarium::base_game_scene *)this;
  if ( m_size )
  {
    v5 = alloca(4 * m_size);
    p_m_inverted_view_matrix = &_FFFFFFFC.m_inverted_view_matrix;
    LODWORD(_FFFFFFFC.m_inverted_view_matrix.c.w) = &_FFFFFFFC.m_inverted_view_matrix;
    vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, &sub_fat->children.m_policy);
    m_object = sub_fat->children.m_first.m_object;
    v8 = 0;
    if ( m_object )
    {
      v8 = sub_fat->children.m_first.m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    while ( v8 )
    {
      if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        {
          _FFFFFFFC.__vftable = (survarium::game_camera_vtbl *)v8;
          vostok::vfs::vfs_intrusive_mount_base::destroy(v8, _FFFFFFFC);
        }
        break;
      }
      if ( p_m_inverted_view_matrix )
        LODWORD(p_m_inverted_view_matrix->i.x) = v8;
      p_m_inverted_view_matrix = (vostok::math::float4x4 *)((char *)p_m_inverted_view_matrix + 4);
      _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
      v9 = vostok::intrusive_double_linked_list<vostok::vfs::vfs_intrusive_mount_base,vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>,4,8,vostok::threading::simple_lock,vostok::size_policy,vostok::debug_policy>::get_next_of_object(
             (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)&_FFFFFFFC.m_near_plane,
             (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)v8)->m_object;
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
      }
      v11 = (survarium::game_camera_vtbl *)v8;
      v8 = v10;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v11, 0xFFFFFFFF) )
      {
        _FFFFFFFC.__vftable = v11;
        vostok::vfs::vfs_intrusive_mount_base::destroy((vostok::vfs::vfs_intrusive_mount_base *)v11, _FFFFFFFC);
      }
      if ( LODWORD(_FFFFFFFC.m_near_plane) )
      {
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)LODWORD(_FFFFFFFC.m_near_plane), 0xFFFFFFFF) )
        {
          _FFFFFFFC.__vftable = (survarium::game_camera_vtbl *)LODWORD(_FFFFFFFC.m_near_plane);
          vostok::vfs::vfs_intrusive_mount_base::destroy(
            (vostok::vfs::vfs_intrusive_mount_base *)LODWORD(_FFFFFFFC.m_near_plane),
            _FFFFFFFC);
        }
      }
    }
    for ( i = 0; i < m_size; ++i )
      vostok::resources::fs_task_unmount::unmount_children(
        (vostok::resources::fs_task_unmount *)_FFFFFFFC.m_game_scene,
        *(vostok::vfs::vfs_mount **)(LODWORD(_FFFFFFFC.m_inverted_view_matrix.c.w) + 4 * i));
    if ( sub_fat->children.m_policy.m_lock-- == 1 )
      this = (vostok::resources::fs_task_unmount *)_InterlockedExchange(&sub_fat->children.m_policy.m_thread_id, 0);
    v3 = sub_fat;
  }
  if ( *(vostok::vfs::vfs_mount **)(LODWORD(_FFFFFFFC.m_game_scene->m_inverted_view_matrix.i.w) + 264) != v3 )
  {
    user_data = (vostok::resources::vfs_sub_fat_resource *)v3->user_data;
    m_variable = vostok::resources::g_game_resources_manager.m_variable;
    if ( vostok::resources::g_game_resources_manager.m_variable->m_resources_to_capture.m_first )
    {
      v16 = (vostok::resources::game_resources_manager *)vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
                                                           (vostok::intrusive_list<vostok::resources::resource_base,vostok::resources::resource_base *,180,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
                                                           (int)vostok::resources::g_game_resources_manager.m_variable);
      if ( v16 )
      {
        do
        {
          m_current_time_high = (vostok::resources::game_resources_manager *)HIDWORD(v16->m_data.increase_quality_timer.m_current_time);
          vostok::resources::game_resources_manager::dispatch_capture(v16, m_variable, a2);
          v16 = m_current_time_high;
        }
        while ( m_current_time_high );
      }
    }
    _FFFFFFFC.m_inverted_view_matrix.j.x = 0.0;
    memset(&_FFFFFFFC.m_inverted_view_matrix.lines[1].elements[2], 0, 32);
    LODWORD(_FFFFFFFC.m_inverted_view_matrix.c.z) = &_FFFFFFFC.m_inverted_view_matrix.j.0;
    LODWORD(_FFFFFFFC.m_inverted_view_matrix.c.w) = &m_variable->m_data;
    vostok::resources::resource_freeing_functionality::release_sub_fat(
      user_data,
      (vostok::threading::simple_lock *)&_FFFFFFFC.m_inverted_view_matrix.lines[1],
      (vostok::resources::resource_freeing_functionality *)&_FFFFFFFC.m_inverted_view_matrix.lines[3].elements[2]);
  }
}
