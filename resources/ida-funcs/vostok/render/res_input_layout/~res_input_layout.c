void __usercall vostok::render::res_input_layout::~res_input_layout(
        vostok::render::res_input_layout *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *a2@<esi>)
{
  const vostok::render::res_signature *m_object; // eax

  m_object = a2[1].m_object;
  if ( m_object )
  {
    (*(void (__stdcall **)(const vostok::render::res_signature *))(m_object->m_reference_count + 8))(a2[1].m_object);
    a2[1].m_object = 0;
  }
  vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec(a2 + 3);
}
