void __thiscall vostok::particle::particle_action_light::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_light *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config,
        vostok::configs::binary_config_value *a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  _BYTE v8[28]; // [esp-1Ch] [ebp-28h] BYREF

  LOBYTE(allocator[19].m_arena_start) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                          "EnableColor",
                                          (vostok::configs::binary_config_value *)this,
                                          a4,
                                          (const bool *)&allocator[19].m_arena_start);
  allocator[22].m_use_memory_monitor = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                         "EnableShadows",
                                         v4,
                                         a4,
                                         &allocator[22].m_use_memory_monitor);
  *(&allocator[22].m_use_memory_monitor + 1) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                                 "StaticShadows",
                                                 v5,
                                                 a4,
                                                 (const bool *)&allocator[22].m_use_memory_monitor + 1);
  allocator[23].__vftable = (vostok::memory::base_allocator_vtbl *)vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                                                     "ShadowTransparency",
                                                                     v6,
                                                                     a4,
                                                                     (const vostok::configs::binary_config_value *)&allocator[23]);
  allocator[23].m_arena_start = (void *)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                          "ShadowMapSizeIndex",
                                          v7,
                                          a4,
                                          (const vostok::configs::binary_config_value *)&allocator[23].m_arena_start);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "Radius"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 24),
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "Attenuation"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 96),
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "Intensity"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 168),
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "DiffuseFactor"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    allocator + 12,
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "SpecularFactor"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 312),
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
  *(_DWORD *)v8 = prop_config;
  qmemcpy(&v8[4], vostok::configs::binary_config_value::operator[](a4, "LightColor"), 0x18u);
  vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 392),
    *(vostok::configs::binary_config_value *)v8,
    *(int *)&v8[24]);
}
