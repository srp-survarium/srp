void __thiscall vostok::math::curve_line_points<float,0>::load<vostok::configs::binary_config_value>(
        vostok::math::curve_line_points<float,0> *this,
        vostok::math::curve_line_points<float,0> *allocator,
        vostok::configs::binary_config_value keys_config,
        int a4)
{
  vostok::buffer_string *v4; // ecx
  int v5; // ecx
  float *pointer; // eax
  float *v7; // eax
  float *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  char *v16; // edi
  vostok::configs::binary_config_value *v17; // [esp-4h] [ebp-74h]
  vostok::configs::binary_config_value *v18; // [esp-4h] [ebp-74h]
  vostok::configs::binary_config_value *v19; // [esp-4h] [ebp-74h]
  char *v20; // [esp-4h] [ebp-74h]
  vostok::configs::binary_config_value *v21; // [esp-4h] [ebp-74h]
  float v22[6]; // [esp+10h] [ebp-60h] BYREF
  vostok::configs::binary_config_value v23; // [esp+28h] [ebp-48h] BYREF
  char *key[3]; // [esp+40h] [ebp-30h] BYREF
  _BYTE v25[8]; // [esp+4Ch] [ebp-24h] BYREF
  float v26; // [esp+54h] [ebp-1Ch] BYREF
  float v27; // [esp+58h] [ebp-18h]
  float v28; // [esp+5Ch] [ebp-14h]
  float v29; // [esp+60h] [ebp-10h]
  float v30; // [esp+64h] [ebp-Ch]
  float v31; // [esp+68h] [ebp-8h]
  char *format; // [esp+6Ch] [ebp-4h]

  key[0] = v25;
  key[1] = v25;
  key[2] = (char *)&v26;
  v25[0] = 0;
  format = 0;
  vostok::fs_new::path_string_impl::assignf(
    (int)key,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)&stru_7FF7FC,
    0);
  if ( vostok::configs::binary_config_value::value_exists(
         v17,
         (int)&keys_config.data.max_storage + 4,
         (unsigned int)key[0]) )
  {
    do
    {
      qmemcpy(
        v22,
        vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
          key[0]),
        sizeof(v22));
      if ( !(24 * HIWORD(LODWORD(v22[5])) / 24) )
        break;
      vostok::fs_new::path_string_impl::assignf(
        (int)key,
        (vostok::buffer_string *)0x18,
        (vostok::buffer_string *)&stru_7FF7FC,
        ++format);
    }
    while ( vostok::configs::binary_config_value::value_exists(
              v18,
              (int)&keys_config.data.max_storage + 4,
              (unsigned int)key[0]) );
  }
  vostok::math::curve_line_points<float,0>::allocate_memory(
    allocator,
    (unsigned int)format,
    (vostok::math::curve_line_points<float,0> *)keys_config.data.pointer);
  format = 0;
  vostok::fs_new::path_string_impl::assignf((int)key, v4, (vostok::buffer_string *)&stru_7FF7FC, 0);
  if ( vostok::configs::binary_config_value::value_exists(
         v19,
         (int)&keys_config.data.max_storage + 4,
         (unsigned int)key[0]) )
  {
    keys_config.data.pointer = 0;
    do
    {
      qmemcpy(
        (void *)&v23,
        vostok::configs::binary_config_value::operator[](
          (vostok::configs::binary_config_value *)((char *)&keys_config.data.max_storage + 4),
          key[0]),
        sizeof(v23));
      v5 = 24;
      if ( !(24 * HIWORD(*(_DWORD *)&v23.type) / 24) )
        break;
      ++format;
      pointer = (float *)vostok::configs::binary_config_value::operator[](&v23, (char *)&stru_7FF7FC.m_max_end)->data.pointer;
      v28 = *pointer;
      v29 = pointer[1];
      v7 = (float *)vostok::configs::binary_config_value::operator[](&v23, "position")->data.pointer;
      v30 = *v7;
      v31 = v7[1];
      v8 = (float *)vostok::configs::binary_config_value::operator[](&v23, "right_tangent")->data.pointer;
      v26 = *v8;
      v27 = v8[1];
      if ( vostok::configs::binary_config_value::value_exists(v9, (int)&v23, (unsigned int)"delta") )
      {
        v11 = vostok::configs::binary_config_value::operator[](&v23, "delta");
        if ( v11->type == 2 )
          v12 = *(float *)&v11->data.pointer;
        else
          v12 = (float)(int)v11->data.pointer;
      }
      else
      {
        v12 = 0.0;
      }
      v22[0] = v31 + v12;
      v22[1] = v31 - v12;
      v13 = v30 - v28;
      v22[4] = v30;
      if ( (float)(v30 - v28) <= 0.0000099999997 )
        v13 = epsilon_5_392;
      v14 = (float)(v31 - v29) / v13;
      v15 = v26 - v30;
      if ( (float)(v26 - v30) <= 0.0000099999997 )
        v15 = epsilon_5_392;
      v22[2] = v14;
      v22[3] = (float)(v27 - v31) / v15;
      LODWORD(v22[5]) = !vostok::configs::binary_config_value::value_exists(v10, (int)&v23, (unsigned int)"key_type")
                     || vostok::configs::binary_config_value::operator[](&v23, "key_type")->data.pointer != (const void *)3;
      v16 = (char *)keys_config.data.pointer + (unsigned int)allocator->points.pointer;
      keys_config.data.pointer = (char *)keys_config.data.pointer + 24;
      v20 = format;
      qmemcpy(v16, v22, 0x18u);
      vostok::fs_new::path_string_impl::assignf((int)key, 0, (vostok::buffer_string *)&stru_7FF7FC, v20);
    }
    while ( vostok::configs::binary_config_value::value_exists(
              v21,
              (int)&keys_config.data.max_storage + 4,
              (unsigned int)key[0]) );
  }
  vostok::math::curve_line_points<float,0>::recalculate_ranges(
    (vostok::math::curve_line_points<float,0> *)v5,
    (int)allocator);
  vostok::math::curve_line_points<float,0>::sort_points_by_time(allocator);
}
