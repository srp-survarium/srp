void __userpurge vostok::resources::resources_manager::fill_stats(
        vostok::strings::text_tree_item *stats@<eax>,
        vostok::resources::resources_manager *this)
{
  unsigned int m_size; // edi
  vostok::strings::text_tree_item *v4; // ebp
  vostok::debug::detail::string_helper *str_impl; // eax
  int v6; // edi
  vostok::strings::text_tree_item *v7; // ebp
  vostok::debug::detail::string_helper *v8; // eax
  int v9; // edi
  vostok::strings::text_tree_item *v10; // ebp
  vostok::debug::detail::string_helper *v11; // eax
  vostok::strings::text_tree_item *v12; // ebp
  vostok::threading::reader_writer_lock *v13; // ecx
  int *v14; // ecx
  int *v15; // edi
  int v16; // eax
  int *i; // eax
  int *v18; // eax

  m_size = this->m_fs_tasks.m_size;
  v4 = vostok::strings::text_tree_item::new_child(stats, (vostok::strings::text_tree_item *)"fs tasks", 0);
  str_impl = vostok::strings::make_str_impl("%u", m_size);
  vostok::strings::text_tree_item::add_column_impl(v4, str_impl->m_buffer);
  v6 = *(volatile int *)((char *)&this->m_fs_tasks_execute_on_current_tick + (_DWORD)&loc_20546 + 2);
  v7 = vostok::strings::text_tree_item::new_child(stats, (vostok::strings::text_tree_item *)"fs subtasks", 0);
  v8 = vostok::strings::make_str_impl("%u", v6);
  vostok::strings::text_tree_item::add_column_impl(v7, v8->m_buffer);
  v9 = *(int *)((char *)&dword_203E8 + (_DWORD)this);
  v10 = vostok::strings::text_tree_item::new_child(stats, (vostok::strings::text_tree_item *)"to_create", 0);
  v11 = vostok::strings::make_str_impl("%u", v9);
  vostok::strings::text_tree_item::add_column_impl(v10, v11->m_buffer);
  v12 = vostok::strings::text_tree_item::new_child(stats, (vostok::strings::text_tree_item *)"threads", 0);
  vostok::threading::reader_writer_lock::lock_read_impl(
    v13,
    (unsigned int *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>>::manage_small
                   + (_DWORD)this));
  v15 = *(int **)((char *)&dword_203BC + (_DWORD)this);
  if ( v15 != (int *)((char *)&dword_203B8 + (_DWORD)this) )
  {
    do
    {
      vostok::strings::text_tree_item::new_childf(
        v12,
        (const char *)*(v15 - 13),
        "ready q(%d), ready fs(%d), alloc(%d), create(%d), translate(%d)",
        *(v15 - 153),
        *(v15 - 141),
        *(v15 - 117) + *(v15 - 105),
        *(v15 - 129),
        *(v15 - 93));
      v16 = v15[2];
      v14 = v15;
      if ( v16 )
      {
        v14 = (int *)v15[2];
        for ( i = *(int **)(v16 + 4); i; i = (int *)i[1] )
          v14 = i;
      }
      else
      {
        v18 = (int *)*v15;
        if ( v15 == *(int **)(*v15 + 8) )
        {
          do
          {
            v14 = v18;
            v18 = (int *)*v18;
          }
          while ( v14 == (int *)v18[2] );
        }
        if ( (int *)v14[2] != v18 )
          goto LABEL_10;
      }
      v18 = v14;
LABEL_10:
      v15 = v18;
    }
    while ( v18 != (int *)((char *)&dword_203B8 + (_DWORD)this) );
  }
  vostok::threading::reader_writer_lock::unlock_read(
    (vostok::threading::reader_writer_lock *)v14,
    (vostok::threading::reader_writer_lock::counters_type *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>>::manage_small
                                                           + (_DWORD)this));
}
