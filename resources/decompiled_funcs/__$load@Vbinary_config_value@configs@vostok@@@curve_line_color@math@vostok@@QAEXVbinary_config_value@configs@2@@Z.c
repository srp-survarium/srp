void __userpurge vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_color *this@<ecx>,
        int a2@<edi>,
        vostok::configs::binary_config_value config)
{
  const char **v3; // eax
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  __int64 v10; // xmm0_8
  _BYTE v11[28]; // [esp-1Ch] [ebp-20h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(&config, "Input") )
  {
    v3 = (const char **)vostok::configs::binary_config_value::operator[](&config, "Input");
    *(_DWORD *)(a2 + 56) = vostok::math::string_to_evaluate_type(*v3);
  }
  if ( vostok::configs::binary_config_value::value_exists(&config, "source") )
  {
    v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
    if ( vostok::configs::binary_config_value::value_exists(v4, "data") )
    {
      v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
      v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v5, "data");
      if ( vostok::configs::binary_config_value::value_exists(v6, "ramp") )
      {
        v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&config, "source");
        v8 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](v7, "data");
        v9 = vostok::configs::binary_config_value::operator[](v8, "ramp");
        *(_QWORD *)&v11[4] = v9->data.max_storage;
        *(_QWORD *)&v11[12] = v9->id.max_storage;
        v10 = *(_QWORD *)&v9->id_crc;
        *(_DWORD *)v11 = a2;
        *(_QWORD *)&v11[20] = v10;
        vostok::math::curve_line_points<vostok::math::float4_pod,1>::load<vostok::configs::binary_config_value>(
          (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)&v11[4],
          *(vostok::configs::binary_config_value *)v11);
      }
    }
  }
}
