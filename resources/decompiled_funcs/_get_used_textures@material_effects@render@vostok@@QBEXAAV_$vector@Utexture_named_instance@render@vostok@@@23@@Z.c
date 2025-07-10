void __userpurge vostok::render::material_effects::get_used_textures(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>,
        vostok::render::vector<vostok::render::texture_named_instance> *out_array)
{
  stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance> > *p_M_impl; // ecx
  vostok::render::texture_named_instance *M_start; // eax
  const vostok::render::texture_named_instance *v6; // ebx
  vostok::render::texture_named_instance *M_finish; // esi
  unsigned __int8 *m_begin; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edi
  const stlp_std::__false_type *v11; // [esp+0h] [ebp-18h]
  unsigned int v12; // [esp+4h] [ebp-14h]
  bool v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+10h] [ebp-8h]
  const vostok::render::texture_named_instance *tex_end; // [esp+14h] [ebp-4h]
  vostok::render::vector<vostok::render::texture_named_instance> *out_arraya; // [esp+1Ch] [ebp+4h]

  out_arraya = (vostok::render::vector<vostok::render::texture_named_instance> *)(a2 + 796);
  v14 = 29;
  do
  {
    p_M_impl = &out_arraya->_M_impl;
    M_start = out_arraya->_M_impl._M_start;
    if ( out_arraya->_M_impl._M_start )
    {
      v6 = *(const vostok::render::texture_named_instance **)&M_start->path.m_buffer[248];
      for ( tex_end = *(const vostok::render::texture_named_instance **)&M_start->path.m_buffer[252]; v6 != tex_end; ++v6 )
      {
        M_finish = out_array->_M_impl._M_finish;
        if ( M_finish == out_array->_M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::render::texture_named_instance,vostok::render::std_allocator<vostok::render::texture_named_instance>>::_M_insert_overflow_aux(
            p_M_impl,
            &out_array->_M_impl._M_start,
            M_finish,
            v6,
            v11,
            v12,
            v13);
        }
        else
        {
          if ( M_finish )
          {
            M_finish->texture = v6->texture;
            m_begin = (unsigned __int8 *)v6->path.m_begin;
            v9 = v6->path.m_end - (char *)m_begin;
            M_finish->path.m_max_end = (char *)&M_finish[1];
            v10 = v9;
            M_finish->path.m_begin = M_finish->path.m_buffer;
            M_finish->path.m_end = M_finish->path.m_buffer;
            memcpy((unsigned __int8 *)M_finish->path.m_buffer, m_begin, v9);
            M_finish->path.m_end += v10;
            *M_finish->path.m_end = 0;
          }
          ++out_array->_M_impl._M_finish;
        }
      }
    }
    out_arraya = (vostok::render::vector<vostok::render::texture_named_instance> *)((char *)out_arraya + 4);
    --v14;
  }
  while ( v14 );
}
