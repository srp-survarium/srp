void __thiscall vostok::math::curve_line_ranged_xyz_float::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_ranged_xyz_float *this,
        vostok::math::curve_line_points<float,0> *allocator,
        vostok::configs::binary_config_value config,
        int a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  char **v5; // eax
  float v6; // eax
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  _BYTE v9[28]; // [esp-1Ch] [ebp-28h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)&config.data.max_storage + 4,
         (unsigned int)"Input") )
  {
    v5 = (char **)vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
                    "Input");
    v6 = COERCE_FLOAT(vostok::math::string_to_evaluate_type(*v5));
    v4 = *(vostok::configs::binary_config_value **)&v9[24];
    allocator[6].curve_time_min = v6;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v4,
         (int)&config.data.max_storage + 4,
         (unsigned int)"source0") )
  {
    *(_DWORD *)v9 = config.data.pointer;
    qmemcpy(
      &v9[4],
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
        "source0"),
      0x18u);
    vostok::math::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
      0,
      allocator,
      *(vostok::configs::binary_config_value *)v9,
      *(int *)&v9[24]);
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v7,
         (int)&config.data.max_storage + 4,
         (unsigned int)"source1") )
  {
    *(_DWORD *)v9 = config.data.pointer;
    qmemcpy(
      &v9[4],
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
        "source1"),
      0x18u);
    vostok::math::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
      0,
      allocator + 2,
      *(vostok::configs::binary_config_value *)v9,
      *(int *)&v9[24]);
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v8,
         (int)&config.data.max_storage + 4,
         (unsigned int)"source2") )
  {
    *(_DWORD *)v9 = config.data.pointer;
    qmemcpy(
      &v9[4],
      vostok::configs::binary_config_value::operator[](
        (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
        "source2"),
      0x18u);
    vostok::math::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
      0,
      allocator + 4,
      *(vostok::configs::binary_config_value *)v9,
      *(int *)&v9[24]);
  }
}
