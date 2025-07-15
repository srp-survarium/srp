void __thiscall vostok::math::curve_line_ranged_base::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_ranged_base *this,
        vostok::math::curve_line_points<float,0> *allocator,
        vostok::configs::binary_config_value config,
        int a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  char *v6; // edi
  _BYTE v7[28]; // [esp-1Ch] [ebp-2Ch] BYREF
  vostok::configs::binary_config_value *v8; // [esp+Ch] [ebp-4h]

  v8 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
         "data");
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)v8, (unsigned int)"curve0") )
  {
    *(_DWORD *)v7 = config.data.pointer;
    qmemcpy(&v7[4], vostok::configs::binary_config_value::operator[](v8, "curve0"), 0x18u);
    vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
      0,
      allocator,
      *(vostok::configs::binary_config_value *)v7,
      *(int *)&v7[24]);
  }
  v6 = "curve1";
  if ( !vostok::configs::binary_config_value::value_exists(v5, (int)v8, (unsigned int)"curve1") )
    v6 = "curve0";
  *(_DWORD *)v7 = config.data.pointer;
  qmemcpy(&v7[4], vostok::configs::binary_config_value::operator[](v8, v6), 0x18u);
  vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
    0,
    allocator + 1,
    *(vostok::configs::binary_config_value *)v7,
    *(int *)&v7[24]);
}
