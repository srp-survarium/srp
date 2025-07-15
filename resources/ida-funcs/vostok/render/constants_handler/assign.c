void __usercall vostok::render::constants_handler<1>::assign(
        vostok::render::constants_handler<1> *this@<edx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  unsigned int v2; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *p_m_current; // esi
  const vostok::render::shader_constant_table *m_object; // ebx
  vostok::render::shader_constant *m_begin; // esi
  unsigned int v6; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v8; // ecx
  int m_buffer_index; // eax
  void *v10; // [esp+0h] [ebp-18h]
  unsigned int v11; // [esp+4h] [ebp-14h]
  unsigned int v12; // [esp+8h] [ebp-10h]
  vostok::render::shader_constant *m_end; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  this->m_diff_range_start = 0;
  if ( table )
    v2 = table->m_const_buffers.m_end - table->m_const_buffers.m_begin;
  else
    v2 = 0;
  p_m_current = &this->m_current;
  this->m_diff_range_end = v2;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    &this->m_current,
    table);
  m_object = p_m_current->m_object;
  if ( p_m_current->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_begin = m_object->m_table.m_begin;
      v6 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7536);
      m_end = m_object->m_table.m_end;
      for ( i = v6; m_begin != m_end; ++m_begin )
      {
        m_host = m_begin->m_host;
        *(_DWORD *)&m_host->m_shader_slots[1].m_class_id = *(_DWORD *)&m_begin->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[1].m_value) = HIDWORD(m_begin->m_slot.m_value);
        v8 = v6;
        if ( m_host->m_source.m_pointer != m_begin->m_source.m_pointer )
          v8 = v6 - 1;
        m_host->m_update_markers[1] = v8;
        m_buffer_index = m_begin->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( m_begin->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set(
              (vostok::render::shader_constant_buffer *)m_begin,
              m_object->m_const_buffers.m_begin[m_buffer_index].m_object,
              (vostok::render::shader_constant_slot *)m_begin->m_source.m_pointer,
              v10,
              v11,
              v12);
            v6 = i;
          }
        }
      }
    }
  }
}


void __usercall vostok::render::constants_handler<2>::assign(
        vostok::render::constants_handler<2> *this@<edx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  unsigned int v2; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *p_m_current; // esi
  const vostok::render::shader_constant_table *m_object; // ebx
  vostok::render::shader_constant *m_begin; // esi
  unsigned int v6; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v8; // ecx
  int m_buffer_index; // eax
  void *v10; // [esp+0h] [ebp-18h]
  unsigned int v11; // [esp+4h] [ebp-14h]
  unsigned int v12; // [esp+8h] [ebp-10h]
  vostok::render::shader_constant *m_end; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  this->m_diff_range_start = 0;
  if ( table )
    v2 = table->m_const_buffers.m_end - table->m_const_buffers.m_begin;
  else
    v2 = 0;
  p_m_current = &this->m_current;
  this->m_diff_range_end = v2;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    &this->m_current,
    table);
  m_object = p_m_current->m_object;
  if ( p_m_current->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_begin = m_object->m_table.m_begin;
      v6 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7536);
      m_end = m_object->m_table.m_end;
      for ( i = v6; m_begin != m_end; ++m_begin )
      {
        m_host = m_begin->m_host;
        *(_DWORD *)&m_host->m_shader_slots[2].m_class_id = *(_DWORD *)&m_begin->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[2].m_value) = HIDWORD(m_begin->m_slot.m_value);
        v8 = v6;
        if ( m_host->m_source.m_pointer != m_begin->m_source.m_pointer )
          v8 = v6 - 1;
        m_host->m_update_markers[2] = v8;
        m_buffer_index = m_begin->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( m_begin->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set(
              (vostok::render::shader_constant_buffer *)m_begin,
              m_object->m_const_buffers.m_begin[m_buffer_index].m_object,
              (vostok::render::shader_constant_slot *)m_begin->m_source.m_pointer,
              v10,
              v11,
              v12);
            v6 = i;
          }
        }
      }
    }
  }
}


void __usercall vostok::render::constants_handler<0>::assign(
        vostok::render::constants_handler<0> *this@<edx>,
        const vostok::render::shader_constant_table *table@<eax>)
{
  unsigned int v2; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *p_m_current; // esi
  const vostok::render::shader_constant_table *m_object; // ebx
  vostok::render::shader_constant *m_begin; // esi
  unsigned int v6; // edx
  const vostok::render::shader_constant_host *m_host; // eax
  unsigned int v8; // ecx
  int m_buffer_index; // eax
  void *v10; // [esp+0h] [ebp-18h]
  unsigned int v11; // [esp+4h] [ebp-14h]
  unsigned int v12; // [esp+8h] [ebp-10h]
  vostok::render::shader_constant *m_end; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  this->m_diff_range_start = 0;
  if ( table )
    v2 = table->m_const_buffers.m_end - table->m_const_buffers.m_begin;
  else
    v2 = 0;
  p_m_current = &this->m_current;
  this->m_diff_range_end = v2;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    &this->m_current,
    table);
  m_object = p_m_current->m_object;
  if ( p_m_current->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_begin = m_object->m_table.m_begin;
      v6 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7536);
      m_end = m_object->m_table.m_end;
      for ( i = v6; m_begin != m_end; ++m_begin )
      {
        m_host = m_begin->m_host;
        *(_DWORD *)&m_host->m_shader_slots[0].m_class_id = *(_DWORD *)&m_begin->m_slot.m_class_id;
        HIDWORD(m_host->m_shader_slots[0].m_value) = HIDWORD(m_begin->m_slot.m_value);
        v8 = v6;
        if ( m_host->m_source.m_pointer != m_begin->m_source.m_pointer )
          v8 = v6 - 1;
        m_host->m_update_markers[0] = v8;
        m_buffer_index = m_begin->m_slot.m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          if ( m_begin->m_source.m_pointer )
          {
            vostok::render::shader_constant_buffer::set(
              (vostok::render::shader_constant_buffer *)m_begin,
              m_object->m_const_buffers.m_begin[m_buffer_index].m_object,
              (vostok::render::shader_constant_slot *)m_begin->m_source.m_pointer,
              v10,
              v11,
              v12);
            v6 = i;
          }
        }
      }
    }
  }
}
