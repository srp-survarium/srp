void __usercall vostok::vfs::async_callbacks_data::continue_find_tree(
        vostok::vfs::async_callbacks_data *this@<ecx>,
        vostok::vfs::async_callbacks_data *a2@<edi>)
{
  vostok::vfs::node_to_expand *m_first; // esi
  vostok::vfs::vfs_hashset *v3; // ecx
  vostok::vfs::base_node<1> *no_lock; // eax
  vostok::vfs::base_folder_node<1> *pointer; // ecx
  vostok::vfs::base_node<1> *p_base; // ecx
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_nodes_to_expand; // ebx
  vostok::vfs::vfs_locked_iterator *v8; // ecx
  vostok::vfs::node_to_expand *v9; // eax
  vostok::vfs::node_to_expand *m_last; // eax
  unsigned int m_size; // eax
  boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *v12; // [esp-4h] [ebp-264h]
  vostok::buffer_string v13; // [esp+8h] [ebp-258h] BYREF
  _BYTE v14[260]; // [esp+14h] [ebp-24Ch] BYREF
  char v15; // [esp+118h] [ebp-148h] BYREF
  vostok::fs_new::virtual_path_string v16; // [esp+120h] [ebp-140h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> a0; // [esp+238h] [ebp-28h] BYREF
  int v18; // [esp+23Ch] [ebp-24h]
  int v19; // [esp+240h] [ebp-20h]
  int v20; // [esp+244h] [ebp-1Ch]
  int v21; // [esp+248h] [ebp-18h]
  vostok::intrusive_list<vostok::vfs::node_to_expand,vostok::vfs::node_to_expand *,8,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> list; // [esp+24Ch] [ebp-14h] BYREF
  vostok::vfs::result_enum v23; // [esp+25Ch] [ebp-4h]

  v13.m_begin = v14;
  v13.m_end = v14;
  v13.m_max_end = &v15;
  v16.m_string.m_begin = v16.m_string.m_buffer;
  v16.m_string.m_end = v16.m_string.m_buffer;
  m_first = a2->nodes_to_expand.m_first;
  a2->callbacks_count = 0;
  a2->callbacks_called_count = 0;
  list.m_size = 0;
  list.m_first = 0;
  list.m_last = 0;
  v14[0] = 0;
  v15 = 47;
  v16.m_string.m_max_end = &v16.m_separator;
  v16.m_string.m_buffer[0] = 0;
  v16.m_separator = 47;
  v23 = result_success;
  while ( m_first )
  {
    vostok::vfs::base_node<1>::get_full_path(m_first->node, &v16);
    if ( vostok::detail::strcmp_s(v16.m_string.m_begin, v13.m_begin) )
    {
      no_lock = vostok::vfs::vfs_hashset::find_no_lock(v3, &a2->env.file_system->hashset, v16.m_string.m_begin, 0);
      pointer = no_lock->m_parent.pointer;
      if ( pointer )
        p_base = &pointer->base;
      else
        p_base = 0;
      v23 = vostok::vfs::fill_expand_nodes_and_incref(
              no_lock,
              p_base,
              no_lock,
              &list,
              a2,
              (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>)m_first->increment);
      if ( v23 == result_out_of_memory )
        break;
      vostok::buffer_string::operator=(&v16.m_string, &v13);
    }
    m_first = m_first->next;
  }
  p_nodes_to_expand = &a2->nodes_to_expand;
  vostok::vfs::free_nodes_to_expand(&a2->nodes_to_expand, a2->env.allocator);
  if ( v23 == result_out_of_memory )
  {
    vostok::vfs::free_nodes_to_expand(&list, a2->env.allocator);
    a0.m_object = 0;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
      v12,
      &a2->env.callback.vtable,
      &a0,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)3);
    vostok::vfs::vfs_locked_iterator::clear(v8, (int)&a0);
  }
  else
  {
    v9 = a2->nodes_to_expand.m_first;
    a2->nodes_to_expand.m_first = list.m_first;
    list.m_first = v9;
    m_last = a2->nodes_to_expand.m_last;
    a2->nodes_to_expand.m_last = list.m_last;
    list.m_last = m_last;
    m_size = p_nodes_to_expand->m_size;
    p_nodes_to_expand->m_size = list.m_size;
    list.m_size = m_size;
  }
  vostok::vfs::query_expand_nodes(&a2->nodes_to_expand, a2);
}
