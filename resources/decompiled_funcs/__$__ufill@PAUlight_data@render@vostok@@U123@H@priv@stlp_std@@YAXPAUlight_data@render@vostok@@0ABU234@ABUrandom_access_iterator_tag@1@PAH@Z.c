void __usercall stlp_std::priv::__ufill<vostok::render::light_data *,vostok::render::light_data,int>(
        vostok::render::light_data *__first@<ecx>,
        vostok::render::light_data *__last@<eax>,
        const vostok::render::light_data *__x@<esi>)
{
  int i; // edx
  vostok::render::light *m_object; // eax

  for ( i = __last - __first; i > 0; ++__first )
  {
    if ( __first )
    {
      __first->light.m_object = 0;
      m_object = __x->light.m_object;
      if ( __x->light.m_object )
      {
        __first->light.m_object = m_object;
        ++m_object->m_reference_count;
      }
      __first->id = __x->id;
    }
    --i;
  }
}
