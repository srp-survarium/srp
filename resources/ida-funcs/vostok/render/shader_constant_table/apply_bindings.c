void __userpurge vostok::render::shader_constant_table::apply_bindings(
        const vostok::render::shader_constant_bindings *bindings@<eax>,
        vostok::render::shader_constant_table *this)
{
  vostok::render::shader_constant_binding *m_begin; // edx
  vostok::render::shader_constant *v3; // eax
  vostok::render::shader_constant *v4; // ecx
  vostok::render::shader_constant_source *p_m_source; // edi
  int m_class_id; // ecx
  int v7; // eax
  vostok::render::shader_constant_binding *m_end; // [esp+Ch] [ebp-4h]

  m_begin = bindings->m_bindings.m_begin;
  m_end = bindings->m_bindings.m_end;
  if ( bindings->m_bindings.m_begin != m_end )
  {
    do
    {
      v3 = this->m_table.m_begin;
      v4 = this->m_table.m_end;
      if ( v3 == v4 )
      {
LABEL_5:
        v3 = 0;
      }
      else
      {
        while ( v3->m_host->m_name.m_pointer.m_object != m_begin->m_name.m_pointer.m_object )
        {
          if ( ++v3 == v4 )
            goto LABEL_5;
        }
      }
      if ( v3 )
      {
        p_m_source = &v3->m_source;
        if ( !v3->m_source.m_pointer )
        {
          m_class_id = v3->m_slot.m_class_id;
          if ( ((m_class_id ^ m_begin->m_class_id) & 0xFF00) == 0 && v3->m_host->m_type == m_begin->m_type )
          {
            v7 = (unsigned __int8)m_class_id
               + (m_begin->m_source.m_size < (unsigned __int8)m_class_id
                ? m_begin->m_source.m_size - (unsigned __int8)m_class_id
                : 0);
            if ( p_m_source )
            {
              p_m_source->m_pointer = m_begin->m_source.m_pointer;
              p_m_source->m_size = v7;
            }
          }
        }
      }
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
}
