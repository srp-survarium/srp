void __usercall vostok::memory::detail::call_constructor_helper<vostok::render::cloud_key_parameters,0>::call(
        vostok::render::cloud_key_parameters *const begin@<eax>,
        vostok::render::cloud_key_parameters *const end@<ecx>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  float *p_cloud_base; // eax

  if ( begin != end )
  {
    v2 = clear_value;
    p_cloud_base = &begin->cloud_base;
    do
    {
      if ( p_cloud_base != (float *)28 )
      {
        p_cloud_base[9] = 0.0;
        *p_cloud_base = 3200.0;
        p_cloud_base[1] = 7.0;
        *((_DWORD *)p_cloud_base - 5) = v2;
        *((_DWORD *)p_cloud_base - 4) = v2;
        *((_DWORD *)p_cloud_base - 3) = v2;
        *((_DWORD *)p_cloud_base - 2) = v2;
        *((_DWORD *)p_cloud_base + 2) = v2;
        *((_DWORD *)p_cloud_base + 3) = v2;
        *((_DWORD *)p_cloud_base + 4) = v2;
        *(p_cloud_base - 6) = FLOAT_0_5;
        *((_DWORD *)p_cloud_base - 7) = v2;
        *(p_cloud_base - 1) = 0.0;
        *((_DWORD *)p_cloud_base + 5) = v2;
        p_cloud_base[6] = 0.0;
        p_cloud_base[7] = 0.0;
        *((_DWORD *)p_cloud_base + 8) = 1;
      }
      p_cloud_base += 17;
    }
    while ( p_cloud_base - 7 != (float *)end );
  }
}


void __usercall vostok::memory::detail::call_constructor_helper<vostok::render::model_asset,0>::call(
        vostok::render::model_asset *const begin@<eax>,
        vostok::render::model_asset *const end@<edx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->m_surface_name.m_string.m_buffer;
    do
    {
      if ( m_buffer != (char *)24 )
      {
        *((_DWORD *)m_buffer - 6) = 0;
        *((_DWORD *)m_buffer - 5) = 0;
        *((_DWORD *)m_buffer - 4) = 0;
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        *m_buffer = 0;
        m_buffer[260] = 47;
      }
      m_buffer += 288;
    }
    while ( m_buffer - 24 != (char *)end );
  }
}


void __usercall vostok::memory::detail::call_constructor_helper<vostok::render::sampler_slot,0>::call(
        vostok::render::texture_slot *const begin@<eax>,
        vostok::render::texture_slot *const end@<ecx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->name.m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 64;
        *m_buffer = 0;
        *m_buffer = 0;
        *((_DWORD *)m_buffer + 16) = -1;
        *((_DWORD *)m_buffer + 17) = 0;
      }
      m_buffer += 84;
    }
    while ( m_buffer - 12 != (char *)end );
  }
}


void __usercall vostok::memory::detail::call_constructor_helper<vostok::fs_new::virtual_path_string,0>::call(
        vostok::fs_new::virtual_path_string *const begin@<eax>,
        vostok::fs_new::virtual_path_string *const end@<ecx>)
{
  char *m_buffer; // eax

  if ( begin != end )
  {
    m_buffer = begin->m_string.m_buffer;
    do
    {
      if ( m_buffer != (char *)12 )
      {
        *((_DWORD *)m_buffer - 3) = m_buffer;
        *((_DWORD *)m_buffer - 2) = m_buffer;
        *((_DWORD *)m_buffer - 1) = m_buffer + 260;
        *m_buffer = 0;
        *m_buffer = 0;
        m_buffer[260] = 47;
      }
      m_buffer += 276;
    }
    while ( m_buffer - 12 != (char *)end );
  }
}
