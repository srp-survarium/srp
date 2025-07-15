vostok::render::res_input_layout *__userpurge vostok::render::res_declaration::get@<eax>(
        vostok::render::res_declaration *this@<ecx>,
        const vostok::render::res_declaration *a2@<edi>,
        const vostok::render::res_signature *signature)
{
  vostok::fixed_vector<vostok::render::signature_layout_pair,128> *p_vs_to_layout; // ebx
  vostok::render::signature_layout_pair *m_begin; // ecx
  int v5; // eax
  vostok::render::signature_layout_pair *v6; // esi
  const vostok::render::signature_layout_pair *v8; // eax
  vostok::buffer_vector<vostok::render::signature_layout_pair> *v9; // ecx
  int v10; // esi
  const vostok::render::res_signature *m_object; // eax
  vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> v12; // [esp+Ch] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> v13; // [esp+10h] [ebp-Ch] BYREF
  unsigned int count; // [esp+14h] [ebp-8h] BYREF

  p_vs_to_layout = &a2->vs_to_layout;
  m_begin = a2->vs_to_layout.m_begin;
  v5 = a2->vs_to_layout.m_end - m_begin;
  count = (unsigned int)&a2->vs_to_layout;
  if ( v5 > 0 )
  {
    do
    {
      v6 = &m_begin[v5 >> 1];
      if ( v6->signature.m_object >= signature )
      {
        v5 >>= 1;
      }
      else
      {
        m_begin = v6 + 1;
        v5 += -1 - (v5 >> 1);
      }
    }
    while ( v5 > 0 );
    p_vs_to_layout = (vostok::fixed_vector<vostok::render::signature_layout_pair,128> *)count;
  }
  count = (unsigned int)m_begin;
  if ( m_begin != a2->vs_to_layout.m_end && m_begin->signature.m_object == signature )
    return m_begin->input_layout.m_object;
  vostok::render::signature_layout_pair::signature_layout_pair(m_begin, &v12, a2, signature);
  vostok::buffer_vector<vostok::render::signature_layout_pair>::insert(v9, &p_vs_to_layout->m_begin, (int *)&count, v8);
  v10 = *(_DWORD *)count;
  vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec(&v13);
  m_object = v12.m_object;
  if ( v12.m_object )
  {
    --v12.m_object->m_reference_count;
    if ( !m_object->m_reference_count )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)v12.m_object);
  }
  return (vostok::render::res_input_layout *)v10;
}
