void __usercall vostok::resources::resources_manager::fill_stats(
        vostok::strings::text_tree_item *stats@<eax>,
        vostok::strings::text_tree_item *a2@<ecx>)
{
  vostok::strings::text_tree_item *v3; // ecx
  vostok::strings::text_tree_item *v4; // ecx
  vostok::strings::text_tree_item *v5; // ecx
  vostok::strings::text_tree_item *v6; // edi
  vostok::threading::reader_writer_lock *v7; // ecx
  vostok::threading::reader_writer_lock *v8; // ecx
  boost::intrusive::rbtree_node<void *> *i; // ebx

  vostok::strings::text_tree_item::new_child<unsigned int>(
    a2,
    (char *)stats,
    (bool)"fs tasks",
    s_resources_manager_buffer.m_fs_tasks.m_size);
  vostok::strings::text_tree_item::new_child<unsigned int>(
    v3,
    (char *)stats,
    (bool)"fs subtasks",
    s_resources_manager_buffer.m_fs_sub_tasks.m_size);
  vostok::strings::text_tree_item::new_child<unsigned int>(
    v4,
    (char *)stats,
    (bool)"to_create",
    s_resources_manager_buffer.m_resources_to_create.m_size);
  v6 = vostok::strings::text_tree_item::new_child(v5, (const char *)stats, "threads");
  vostok::threading::reader_writer_lock::lock_read_impl(
    v7,
    (volatile signed __int64 *)&s_resources_manager_buffer.m_thread_local_data_lock);
  for ( i = s_resources_manager_buffer.m_thread_local_data.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_;
        i != (boost::intrusive::rbtree_node<void *> *)&s_resources_manager_buffer.m_thread_local_data;
        i = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(i) )
  {
    vostok::strings::text_tree_item::new_childf(
      v6,
      (const char *)i[-4].color_,
      "ready q(%d), ready fs(%d), alloc(%d), create(%d), translate(%d)",
      i[-39].color_,
      i[-36].color_,
      i[-30].color_ + i[-27].color_,
      i[-33].color_,
      i[-24].color_);
  }
  vostok::threading::reader_writer_lock::unlock_read(
    v8,
    (volatile signed __int64 *)&s_resources_manager_buffer.m_thread_local_data_lock);
}
