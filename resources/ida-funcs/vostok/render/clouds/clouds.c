void __usercall vostok::render::clouds::clouds(vostok::render::clouds *this@<ecx>, int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4

  `vector constructor iterator'(
    (char *)a2,
    0x44u,
    32,
    (void *(__thiscall *)(void *))vostok::render::cloud_key_parameters::cloud_key_parameters);
  *(_DWORD *)(a2 + 2176) = 0;
  *(_DWORD *)(a2 + 2284) = a2 + 2184;
  *(_DWORD *)(a2 + 2288) = 0;
  *(_DWORD *)(a2 + 2292) = 0;
  *(_DWORD *)(a2 + 2396) = a2 + 2296;
  *(_DWORD *)(a2 + 2400) = 0;
  *(_DWORD *)(a2 + 2404) = 0;
  *(_DWORD *)(a2 + 2508) = a2 + 2408;
  *(_DWORD *)(a2 + 2512) = 0;
  *(_DWORD *)(a2 + 2516) = 0;
  *(_BYTE *)(a2 + 2520) = 1;
  *(_DWORD *)(a2 + 2552) = 1162346496;
  *(_DWORD *)(a2 + 2556) = 1088421888;
  v2 = clear_value;
  *(_DWORD *)(a2 + 2588) = 0;
  *(_DWORD *)(a2 + 2532) = v2;
  *(_DWORD *)(a2 + 2536) = v2;
  *(_DWORD *)(a2 + 2540) = v2;
  *(_DWORD *)(a2 + 2544) = v2;
  *(_DWORD *)(a2 + 2560) = v2;
  *(_DWORD *)(a2 + 2564) = v2;
  *(_DWORD *)(a2 + 2568) = v2;
  *(float *)(a2 + 2528) = FLOAT_0_5;
  *(_DWORD *)(a2 + 2524) = v2;
  *(_DWORD *)(a2 + 2548) = 0;
  *(_DWORD *)(a2 + 2572) = v2;
  *(_DWORD *)(a2 + 2576) = 0;
  *(_DWORD *)(a2 + 2580) = 0;
  *(_DWORD *)(a2 + 2584) = 1;
  *(_DWORD *)(a2 + 2592) = 0;
  *(_DWORD *)(a2 + 2596) = vostok::tasks::create_new_task_type((const char *)&stru_962594.m_ps_ids, 0);
  *(_DWORD *)(a2 + 2604) = 0;
  *(_DWORD *)(a2 + 2612) = 0;
  *(_DWORD *)(a2 + 2616) = 0;
  *(_DWORD *)(a2 + 2624) = 0;
  *(_DWORD *)(a2 + 2628) = 0;
  *(_DWORD *)(a2 + 2632) = 0;
  *(_DWORD *)(a2 + 2636) = 0;
  *(_DWORD *)(a2 + 2640) = 0;
  *(_DWORD *)(a2 + 2672) = 0;
  *(_DWORD *)(a2 + 2676) = 0;
  *(_DWORD *)(a2 + 2680) = 0;
  *(_DWORD *)(a2 + 2684) = 0;
  *(_DWORD *)(a2 + 2688) = 1;
  *(_DWORD *)(a2 + 2692) = 4;
  *(_DWORD *)(a2 + 2704) = -1;
  *(_DWORD *)(a2 + 2708) = -1;
  *(_BYTE *)(a2 + 2712) = 0;
  *(_DWORD *)(a2 + 2700) = 0;
  *(_DWORD *)(a2 + 2716) = 0;
  *(_DWORD *)(a2 + 2720) = -1082130432;
  *(_DWORD *)(a2 + 2724) = 0;
  *(_BYTE *)(a2 + 2728) = 0;
  *(_BYTE *)(a2 + 2520) = 0;
}
