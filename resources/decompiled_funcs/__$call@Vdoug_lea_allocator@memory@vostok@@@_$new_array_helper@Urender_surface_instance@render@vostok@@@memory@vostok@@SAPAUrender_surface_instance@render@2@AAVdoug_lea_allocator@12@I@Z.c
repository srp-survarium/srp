vostok::render::render_surface_instance *__usercall vostok::memory::new_array_helper<vostok::render::render_surface_instance>::call<vostok::memory::doug_lea_allocator>@<eax>(
        vostok::memory::doug_lea_allocator *allocator@<ecx>,
        unsigned int count@<eax>)
{
  unsigned int v3; // esi
  char *v4; // eax
  vostok::render::render_surface_instance *result; // eax
  const vostok::math::float4x4 *v6; // xmm0_4
  float *p_m_dynamic_screen_factor; // ecx

  v3 = count;
  v4 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(allocator, 28 * count + 8);
  *(_DWORD *)v4 = count;
  v4 += 4;
  *(_DWORD *)v4 = 28;
  result = (vostok::render::render_surface_instance *)(v4 + 4);
  if ( result != &result[v3] )
  {
    v6 = clear_value;
    p_m_dynamic_screen_factor = &result->m_dynamic_screen_factor;
    do
    {
      if ( p_m_dynamic_screen_factor != (float *)16 )
      {
        *(p_m_dynamic_screen_factor - 1) = NAN;
        *(_DWORD *)p_m_dynamic_screen_factor = v6;
        *((_BYTE *)p_m_dynamic_screen_factor + 8) = 0;
        *((_BYTE *)p_m_dynamic_screen_factor + 9) = 0;
      }
      p_m_dynamic_screen_factor += 7;
    }
    while ( p_m_dynamic_screen_factor - 4 != (float *)&result[v3] );
  }
  return result;
}
