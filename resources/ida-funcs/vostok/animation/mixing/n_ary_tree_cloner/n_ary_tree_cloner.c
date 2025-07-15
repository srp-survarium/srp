void __userpurge vostok::animation::mixing::n_ary_tree_cloner::n_ary_tree_cloner(
        vostok::const_buffer *source@<edi>,
        vostok::network_core::buffer_writer *writer@<eax>,
        vostok::network_core::buffer_writer *a3@<ecx>,
        vostok::animation::mixing::n_ary_tree_cloner **this,
        unsigned int offset_time_in_ms)
{
  vostok::animation::mixing::n_ary_tree_cloner **v5; // ebx
  vostok::animation::mixing::n_ary_tree *m_buffer; // ecx
  unsigned int v8; // eax
  vostok::animation::mixing::n_ary_tree_cloner *v9; // esi
  vostok::animation::mixing::n_ary_tree *v10; // ecx
  vostok::animation::mixing::n_ary_tree_cloner *v11; // eax

  v5 = this;
  *this = 0;
  vostok::network_core::buffer_writer::w(a3, writer, (unsigned __int8 *)source->m_data, source->m_size);
  m_buffer = (vostok::animation::mixing::n_ary_tree *)writer->m_buffer;
  v8 = (unsigned int)m_buffer->m_weight_root + (unsigned int)m_buffer->m_interpolators - source->m_size;
  v9 = (vostok::animation::mixing::n_ary_tree_cloner *)(v8 + 8);
  vostok::animation::mixing::n_ary_tree::fixup_impl(
    m_buffer,
    (_DWORD *)(v8 + 8),
    (vostok::resources::managed_resource *)(v8 - (unsigned int)source->m_data));
  vostok::animation::mixing::n_ary_tree::add_offset(v10, (int)v9, offset_time_in_ms);
  v11 = 0;
  this = 0;
  if ( v9 )
  {
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this);
    ++v9->m_result.m_object;
    v11 = v9;
  }
  this = (vostok::animation::mixing::n_ary_tree_cloner **)*v5;
  *v5 = v11;
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this);
}
