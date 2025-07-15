void __thiscall vostok::math::curve_line_ranged_float::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_ranged_float *this,
        vostok::memory::base_allocator *allocator,
        vostok::configs::binary_config_value config,
        int a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  char **v5; // eax
  void *v6; // eax
  _BYTE v7[28]; // [esp-1Ch] [ebp-28h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)&config.data.max_storage + 4,
         (unsigned int)"Input") )
  {
    v5 = (char **)vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
                    "Input");
    v6 = (void *)vostok::math::string_to_evaluate_type(*v5);
    v4 = *(vostok::configs::binary_config_value **)&v7[24];
    allocator[3].m_arena_start = v6;
  }
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)&config.data.max_storage + 4, (unsigned int)"source") )
  {
    *(_DWORD *)v7 = config.data.pointer;
    qmemcpy(
      &v7[4],
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
        "source"),
      0x18u);
    vostok::math::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
      0,
      (vostok::math::curve_line_points<float,0> *)allocator,
      *(vostok::configs::binary_config_value *)v7,
      *(int *)&v7[24]);
  }
}
