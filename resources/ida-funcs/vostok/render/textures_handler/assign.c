void __usercall vostok::render::textures_handler<0>::assign(
        vostok::render::textures_handler<0> *this@<esi>,
        const vostok::render::res_texture_list *list@<edi>)
{
  const vostok::render::res_texture_list *m_object; // ecx
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // eax
  const vostok::render::res_texture_list *v7; // eax
  const vostok::render::res_texture_list *v8; // ecx
  const vostok::render::res_texture_list *v9; // eax
  unsigned int m_diff_range_end; // [esp-8h] [ebp-14h]
  unsigned int end; // [esp+4h] [ebp-8h] BYREF
  unsigned int start; // [esp+8h] [ebp-4h] BYREF

  m_object = this->m_current.m_object;
  if ( this->m_current.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && list )
  {
    vostok::render::utils::calc_lists_diff_range<vostok::render::res_texture_list>(m_object, list, &start, &end);
    v3 = end;
    v4 = start;
  }
  else
  {
    v4 = 0;
    if ( m_object )
      v5 = m_object->m_container._M_impl._M_finish - m_object->m_container._M_impl._M_start;
    else
      v5 = 0;
    if ( list )
      v6 = list->m_container._M_impl._M_finish - list->m_container._M_impl._M_start;
    else
      v6 = 0;
    v3 = vostok::math::max(v5, v6);
  }
  m_diff_range_end = this->m_diff_range_end;
  this->m_diff_range_start = v4;
  this->m_diff_range_end = vostok::math::max(m_diff_range_end, v3);
  v7 = 0;
  if ( list )
  {
    ++list->m_reference_count;
    v7 = list;
  }
  v8 = v7;
  v9 = this->m_current.m_object;
  this->m_current.m_object = v8;
  if ( v9 )
  {
    if ( v9->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v9);
  }
}
