void __usercall vostok::render::constants_handler<1>::assign(
        vostok::render::constants_handler<1> *this@<ecx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  const vostok::render::shader_constant_table *m_object; // eax
  unsigned int v5; // eax
  const vostok::render::shader_constant_table *v6; // ecx
  const vostok::render::shader_constant_table *v7; // eax
  const vostok::render::shader_constant_table *v9; // ebx
  vostok::render::shader_constant *M_start; // esi
  vostok::render::shader_constant *M_finish; // ebp
  unsigned int v12; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v14; // ecx
  int m_buffer_index; // eax
  unsigned int update_marker; // [esp+10h] [ebp-4h]

  m_object = this->m_current.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && table )
  {
    vostok::render::utils::calc_lists_diff_range<vostok::render::vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>(
      &m_object->m_const_buffers,
      &table->m_const_buffers,
      &this->m_diff_range_start,
      &this->m_diff_range_end);
  }
  else
  {
    this->m_diff_range_start = 0;
    if ( table )
      v5 = table->m_const_buffers._M_impl._M_finish - table->m_const_buffers._M_impl._M_start;
    else
      v5 = 0;
    this->m_diff_range_end = v5;
  }
  v6 = 0;
  if ( table )
  {
    ++table->m_reference_count;
    v6 = table;
  }
  v7 = this->m_current.m_object;
  this->m_current.m_object = v6;
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v7);
  }
  v9 = this->m_current.m_object;
  if ( v9 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      M_start = v9->m_table._M_impl._M_start;
      M_finish = v9->m_table._M_impl._M_finish;
      v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 571);
      for ( update_marker = v12; M_start != M_finish; ++M_start )
      {
        m_host = M_start->m_host;
        *(_DWORD *)&m_host->m_shader_slots[1].m_class_id = *(_DWORD *)&M_start->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[1].m_value) = HIDWORD(M_start->m_slot.m_value);
        v14 = v12;
        if ( m_host->m_source.m_pointer != M_start->m_source.m_pointer )
          v14 = v12 - 1;
        m_host->m_update_markers[1] = v14;
        m_buffer_index = M_start->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( M_start->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set_memory(
              M_start->m_slot.m_slot_index,
              (unsigned __int8)M_start->m_slot.m_class_id * M_start->m_slot.m_array_size,
              v9->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
              (const char *)M_start->m_source.m_pointer);
            v12 = update_marker;
          }
        }
      }
    }
  }
}


void __usercall vostok::render::constants_handler<2>::assign(
        vostok::render::constants_handler<2> *this@<ecx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  const vostok::render::shader_constant_table *m_object; // eax
  unsigned int v5; // eax
  const vostok::render::shader_constant_table *v6; // ecx
  const vostok::render::shader_constant_table *v7; // eax
  const vostok::render::shader_constant_table *v9; // ebx
  vostok::render::shader_constant *M_start; // esi
  vostok::render::shader_constant *M_finish; // ebp
  unsigned int v12; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v14; // ecx
  int m_buffer_index; // eax
  unsigned int update_marker; // [esp+10h] [ebp-4h]

  m_object = this->m_current.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && table )
  {
    vostok::render::utils::calc_lists_diff_range<vostok::render::vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>(
      &m_object->m_const_buffers,
      &table->m_const_buffers,
      &this->m_diff_range_start,
      &this->m_diff_range_end);
  }
  else
  {
    this->m_diff_range_start = 0;
    if ( table )
      v5 = table->m_const_buffers._M_impl._M_finish - table->m_const_buffers._M_impl._M_start;
    else
      v5 = 0;
    this->m_diff_range_end = v5;
  }
  v6 = 0;
  if ( table )
  {
    ++table->m_reference_count;
    v6 = table;
  }
  v7 = this->m_current.m_object;
  this->m_current.m_object = v6;
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v7);
  }
  v9 = this->m_current.m_object;
  if ( v9 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      M_start = v9->m_table._M_impl._M_start;
      M_finish = v9->m_table._M_impl._M_finish;
      v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 571);
      for ( update_marker = v12; M_start != M_finish; ++M_start )
      {
        m_host = M_start->m_host;
        *(_DWORD *)&m_host->m_shader_slots[2].m_class_id = *(_DWORD *)&M_start->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[2].m_value) = HIDWORD(M_start->m_slot.m_value);
        v14 = v12;
        if ( m_host->m_source.m_pointer != M_start->m_source.m_pointer )
          v14 = v12 - 1;
        m_host->m_update_markers[2] = v14;
        m_buffer_index = M_start->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( M_start->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set_memory(
              M_start->m_slot.m_slot_index,
              (unsigned __int8)M_start->m_slot.m_class_id * M_start->m_slot.m_array_size,
              v9->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
              (const char *)M_start->m_source.m_pointer);
            v12 = update_marker;
          }
        }
      }
    }
  }
}


void __usercall vostok::render::constants_handler<0>::assign(
        vostok::render::constants_handler<0> *this@<ecx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  const vostok::render::shader_constant_table *m_object; // eax
  unsigned int v5; // eax
  const vostok::render::shader_constant_table *v6; // ecx
  const vostok::render::shader_constant_table *v7; // eax
  const vostok::render::shader_constant_table *v9; // ebx
  vostok::render::shader_constant *M_start; // esi
  vostok::render::shader_constant *M_finish; // ebp
  unsigned int v12; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v14; // ecx
  int m_buffer_index; // eax
  unsigned int update_marker; // [esp+10h] [ebp-4h]

  m_object = this->m_current.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && table )
  {
    vostok::render::utils::calc_lists_diff_range<vostok::render::vector<vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>(
      &m_object->m_const_buffers,
      &table->m_const_buffers,
      &this->m_diff_range_start,
      &this->m_diff_range_end);
  }
  else
  {
    this->m_diff_range_start = 0;
    if ( table )
      v5 = table->m_const_buffers._M_impl._M_finish - table->m_const_buffers._M_impl._M_start;
    else
      v5 = 0;
    this->m_diff_range_end = v5;
  }
  v6 = 0;
  if ( table )
  {
    ++table->m_reference_count;
    v6 = table;
  }
  v7 = this->m_current.m_object;
  this->m_current.m_object = v6;
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v7);
  }
  v9 = this->m_current.m_object;
  if ( v9 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      M_start = v9->m_table._M_impl._M_start;
      M_finish = v9->m_table._M_impl._M_finish;
      v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 571);
      for ( update_marker = v12; M_start != M_finish; ++M_start )
      {
        m_host = M_start->m_host;
        *(_DWORD *)&m_host->m_shader_slots[0].m_class_id = *(_DWORD *)&M_start->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[0].m_value) = HIDWORD(M_start->m_slot.m_value);
        v14 = v12;
        if ( m_host->m_source.m_pointer != M_start->m_source.m_pointer )
          v14 = v12 - 1;
        m_host->m_update_markers[0] = v14;
        m_buffer_index = M_start->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( M_start->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set_memory(
              M_start->m_slot.m_slot_index,
              (unsigned __int8)M_start->m_slot.m_class_id * M_start->m_slot.m_array_size,
              v9->m_const_buffers._M_impl._M_start[m_buffer_index].m_object,
              (const char *)M_start->m_source.m_pointer);
            v12 = update_marker;
          }
        }
      }
    }
  }
}
