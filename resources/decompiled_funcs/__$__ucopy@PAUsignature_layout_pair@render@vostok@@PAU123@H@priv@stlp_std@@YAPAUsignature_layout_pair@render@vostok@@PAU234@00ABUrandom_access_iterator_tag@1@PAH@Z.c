vostok::render::signature_layout_pair *__fastcall stlp_std::priv::__ucopy<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair *,int>(
        vostok::render::signature_layout_pair *__last,
        vostok::render::signature_layout_pair *__first,
        vostok::render::signature_layout_pair *__result)
{
  vostok::render::signature_layout_pair *result; // eax
  int i; // esi
  vostok::render::res_input_layout *m_object; // ecx
  const vostok::render::res_signature *v6; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->input_layout.m_object = 0;
      m_object = __first->input_layout.m_object;
      if ( __first->input_layout.m_object )
      {
        result->input_layout.m_object = m_object;
        ++m_object->m_reference_count;
      }
      result->signature.m_object = 0;
      v6 = __first->signature.m_object;
      if ( v6 )
      {
        result->signature.m_object = v6;
        ++v6->m_reference_count;
      }
    }
    --i;
    ++__first;
  }
  return result;
}
