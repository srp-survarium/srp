void __userpurge vostok::render::shader_constant_table::apply_bindings(
        const vostok::render::shader_constant_bindings *bindings@<eax>,
        vostok::render::shader_constant_table *this)
{
  vostok::render::shader_constant_binding *M_finish; // ebp
  vostok::render::shader_constant_binding *i; // esi
  vostok::render::shader_constant *M_start; // eax
  vostok::render::shader_constant *v5; // ecx
  vostok::render::shader_constant_source *p_m_source; // edi
  int m_class_id; // ecx
  int v8; // eax

  M_finish = bindings->m_bindings._M_impl._M_finish;
  for ( i = bindings->m_bindings._M_impl._M_start; i != M_finish; ++i )
  {
    M_start = this->m_table._M_impl._M_start;
    v5 = this->m_table._M_impl._M_finish;
    if ( M_start != v5 )
    {
      while ( M_start->m_host->m_name.m_pointer.m_object != i->m_name.m_pointer.m_object )
      {
        if ( ++M_start == v5 )
          goto LABEL_11;
      }
      p_m_source = &M_start->m_source;
      if ( !M_start->m_source.m_pointer )
      {
        m_class_id = M_start->m_slot.m_class_id;
        if ( ((m_class_id ^ i->m_class_id) & 0xFF00) == 0 && M_start->m_host->m_type == i->m_type )
        {
          v8 = (unsigned __int8)m_class_id
             + (i->m_source.m_size < (unsigned __int8)m_class_id ? i->m_source.m_size - (unsigned __int8)m_class_id : 0);
          if ( p_m_source )
          {
            p_m_source->m_pointer = i->m_source.m_pointer;
            p_m_source->m_size = v8;
          }
        }
      }
    }
LABEL_11:
    ;
  }
}
