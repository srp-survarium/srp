void __usercall vostok::render::environment_temp::environment_temp(
        vostok::render::environment_temp *this@<ecx>,
        _DWORD *a2@<esi>)
{
  char *v2; // eax
  char *v3; // edi
  const vostok::math::float4x4 *v4; // xmm0_4

  a2[2] = 3;
  a2[1] = 1084227584;
  v2 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                 0xD4u);
  *(_DWORD *)v2 = 3;
  v2 += 4;
  v3 = v2 + 4;
  *(_DWORD *)v2 = 68;
  vostok::memory::detail::call_constructor_helper<vostok::render::cloud_key_parameters,0>::call(
    (vostok::render::cloud_key_parameters *const)(v2 + 4),
    (vostok::render::cloud_key_parameters *const)(v2 + 208));
  *a2 = v3;
  *((_DWORD *)v3 + 7) = 1162346496;
  *(float *)(*a2 + 44) = retry_to_increase_quality_period_sec;
  v4 = clear_value;
  *(_DWORD *)(*a2 + 32) = 1086324736;
  *(_DWORD *)(*a2 + 16) = v4;
  *(_DWORD *)(*a2 + 8) = v4;
  *(_DWORD *)(*a2 + 4) = 1060320051;
  *(float *)*a2 = retry_to_increase_quality_period_sec;
  *(_DWORD *)(*a2 + 24) = 0;
  *(_DWORD *)(*a2 + 96) = 1162346496;
  *(float *)(*a2 + 112) = retry_to_increase_quality_period_sec;
  *(_DWORD *)(*a2 + 100) = 1086324736;
  *(_DWORD *)(*a2 + 84) = v4;
  *(_DWORD *)(*a2 + 76) = v4;
  *(_DWORD *)(*a2 + 72) = 1061997773;
  *(float *)(*a2 + 68) = retry_to_increase_quality_period_sec;
  *(_DWORD *)(*a2 + 92) = 0;
  *(_DWORD *)(*a2 + 164) = 1157234688;
  *(_DWORD *)(*a2 + 180) = v4;
  *(_DWORD *)(*a2 + 168) = 1086324736;
  *(_DWORD *)(*a2 + 152) = v4;
  *(_DWORD *)(*a2 + 144) = v4;
  *(float *)(*a2 + 140) = FLOAT_0_5;
  *(float *)(*a2 + 136) = retry_to_increase_quality_period_sec;
  *(_DWORD *)(*a2 + 160) = 0;
}
