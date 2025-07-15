void __thiscall vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_color *this,
        vostok::memory::base_allocator *allocator,
        vostok::configs::binary_config_value config,
        int a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  char **v5; // eax
  vostok::math::enum_evaluate_type v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  _BYTE v14[28]; // [esp-1Ch] [ebp-28h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)&config.data.max_storage + 4,
         (unsigned int)"Input") )
  {
    v5 = (char **)vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
                    "Input");
    v6 = vostok::math::string_to_evaluate_type(*v5);
    v4 = (vostok::configs::binary_config_value *)allocator;
    *(_DWORD *)&allocator[2].m_use_memory_monitor = v6;
  }
  else
  {
    *(_DWORD *)&allocator[2].m_use_memory_monitor = 0;
  }
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)&config.data.max_storage + 4, (unsigned int)"source") )
  {
    v7 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
           "source");
    if ( vostok::configs::binary_config_value::value_exists(v8, (int)v7, (unsigned int)"data") )
    {
      v9 = vostok::configs::binary_config_value::operator[](
             (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
             "source");
      v10 = vostok::configs::binary_config_value::operator[](v9, "data");
      if ( vostok::configs::binary_config_value::value_exists(v11, (int)v10, (unsigned int)"ramp") )
      {
        v12 = vostok::configs::binary_config_value::operator[](
                (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
                "source");
        v13 = vostok::configs::binary_config_value::operator[](v12, "data");
        *(_DWORD *)v14 = config.data.pointer;
        qmemcpy(&v14[4], vostok::configs::binary_config_value::operator[](v13, "ramp"), 0x18u);
        vostok::math::curve_line_points<vostok::math::float4_pod,1>::load<vostok::configs::binary_config_value>(
          0,
          (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)allocator,
          *(vostok::configs::binary_config_value *)v14,
          *(int *)&v14[24]);
      }
    }
  }
}
