void __usercall stlp_std::priv::__ufill<vostok::render::signature_layout_pair *,vostok::render::signature_layout_pair,int>(
        vostok::render::signature_layout_pair *__first@<eax>,
        vostok::render::signature_layout_pair *__last@<ecx>,
        const vostok::render::signature_layout_pair *__x@<edi>)
{
  int i; // edx
  vostok::render::res_input_layout *m_object; // ecx
  const vostok::render::res_signature *v5; // ecx

  for ( i = __last - __first; i > 0; ++__first )
  {
    if ( __first )
    {
      __first->input_layout.m_object = 0;
      m_object = __x->input_layout.m_object;
      if ( __x->input_layout.m_object )
      {
        __first->input_layout.m_object = m_object;
        ++m_object->m_reference_count;
      }
      __first->signature.m_object = 0;
      v5 = __x->signature.m_object;
      if ( v5 )
      {
        __first->signature.m_object = v5;
        ++v5->m_reference_count;
      }
    }
    --i;
  }
}
