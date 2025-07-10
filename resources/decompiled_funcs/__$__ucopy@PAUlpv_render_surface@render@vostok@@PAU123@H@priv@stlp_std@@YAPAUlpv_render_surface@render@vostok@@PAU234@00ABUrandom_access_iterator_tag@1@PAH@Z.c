survarium::game_world::bullet_tracer *__fastcall stlp_std::priv::__ucopy<vostok::render::lpv_render_surface *,vostok::render::lpv_render_surface *,int>(
        survarium::game_world::bullet_tracer *__last,
        survarium::game_world::bullet_tracer *__first,
        survarium::game_world::bullet_tracer *__result)
{
  survarium::game_world::bullet_tracer *result; // eax
  int i; // esi
  vostok::render::tracer_model_instance *m_object; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    if ( result )
    {
      result->bullet = __first->bullet;
      result->tracer.m_object = 0;
      m_object = __first->tracer.m_object;
      if ( m_object )
      {
        result->tracer.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
    }
    --i;
    ++__first;
  }
  return result;
}
