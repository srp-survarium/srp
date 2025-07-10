vostok::render::light_data *__fastcall stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        vostok::render::light_data *__last,
        vostok::render::light_data *__first,
        vostok::render::light_data *__result)
{
  vostok::render::light_data *result; // eax
  int i; // esi
  vostok::render::light *m_object; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->light.m_object = 0;
      m_object = __first->light.m_object;
      if ( __first->light.m_object )
      {
        result->light.m_object = m_object;
        ++m_object->m_reference_count;
      }
      result->id = __first->id;
    }
    --i;
    ++__first;
  }
  return result;
}
