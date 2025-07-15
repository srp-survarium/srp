void __thiscall vostok::particle::particle_action_billboard::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_billboard *this,
        vostok::memory::base_allocator *allocator,
        const vostok::configs::binary_config_value *prop_config,
        vostok::configs::binary_config_value *a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  char **v11; // eax
  vostok::fixed_string<128> *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  char **v14; // eax
  vostok::fixed_string<128> *v15; // ecx
  char **v16; // eax
  vostok::fixed_string<128> *v17; // ecx
  _BYTE v18[28]; // [esp-1Ch] [ebp-48h] BYREF
  vostok::fixed_string<128> name; // [esp+Ch] [ebp-20h] BYREF

  LOBYTE(allocator[10].m_arena_end) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                        "UseSubUV",
                                        (vostok::configs::binary_config_value *)this,
                                        a4,
                                        (const bool *)&allocator[10].m_arena_end);
  allocator[6].__vftable = (vostok::memory::base_allocator_vtbl *)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                                                    "SubImgHorizontal",
                                                                    v4,
                                                                    a4,
                                                                    (const vostok::configs::binary_config_value *)&allocator[6]);
  allocator[6].m_arena_start = (void *)vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                         "SubImgVertical",
                                         v5,
                                         a4,
                                         (const vostok::configs::binary_config_value *)&allocator[6].m_arena_start);
  BYTE1(allocator[10].m_arena_end) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                                       "UseMovie",
                                       v6,
                                       a4,
                                       (const bool *)&allocator[10].m_arena_end + 1);
  allocator[6].m_arena_end = (void *)vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                       "MovieFrameRate",
                                       v7,
                                       a4,
                                       (const vostok::configs::binary_config_value *)&allocator[6].m_arena_end);
  *(_DWORD *)v18 = prop_config;
  qmemcpy(&v18[4], vostok::configs::binary_config_value::operator[](a4, "MovieStartFrame"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 136),
    *(vostok::configs::binary_config_value *)v18,
    *(int *)&v18[24]);
  *(_DWORD *)&allocator[5].m_use_memory_monitor = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                                                    "SubImgChange",
                                                    v8,
                                                    a4,
                                                    (const vostok::configs::binary_config_value *)&allocator[5].m_use_memory_monitor);
  allocator[5].m_arena_end = allocator[6].__vftable;
  v9 = *(vostok::configs::binary_config_value **)&v18[24];
  allocator[5].m_arena_id = (const char *)allocator[6].m_arena_start;
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)a4, (unsigned int)"ScreenAlignment") )
  {
    v11 = (char **)vostok::configs::binary_config_value::operator[](a4, "ScreenAlignment");
    vostok::fixed_string<128>::fixed_string<128>(v12, &name, *v11);
    allocator[5].m_arena_start = (void *)vostok::particle::screen_alignment_name_to_type(&name);
  }
  if ( vostok::configs::binary_config_value::value_exists(v10, (int)a4, (unsigned int)"LockAxisFlags") )
  {
    v14 = (char **)vostok::configs::binary_config_value::operator[](a4, "LockAxisFlags");
    vostok::fixed_string<128>::fixed_string<128>(v15, &name, *v14);
    *(_DWORD *)&allocator[4].m_use_memory_monitor = vostok::particle::locked_axis_name_to_type(&name);
  }
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)a4, (unsigned int)"Method") )
  {
    v16 = (char **)vostok::configs::binary_config_value::operator[](a4, "Method");
    vostok::fixed_string<128>::fixed_string<128>(v17, &name, *v16);
    allocator[5].__vftable = (vostok::memory::base_allocator_vtbl *)vostok::particle::sub_uv_method_name_to_type(&name);
  }
  *(_DWORD *)v18 = prop_config;
  qmemcpy(&v18[4], vostok::configs::binary_config_value::operator[](a4, "SubImgIndex"), 0x18u);
  vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
    0,
    (vostok::memory::base_allocator *)((char *)allocator + 24),
    *(vostok::configs::binary_config_value *)v18,
    *(int *)&v18[24]);
}
