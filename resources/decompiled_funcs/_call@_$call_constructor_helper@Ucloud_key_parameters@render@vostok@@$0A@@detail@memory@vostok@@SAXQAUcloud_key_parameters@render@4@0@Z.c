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
