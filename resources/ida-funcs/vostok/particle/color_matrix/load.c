void __thiscall vostok::particle::color_matrix::load<vostok::configs::binary_config_value>(
        vostok::particle::color_matrix *this,
        vostok::configs::binary_config_value *allocator,
        vostok::configs::binary_config_value config,
        int a4)
{
  vostok::configs::binary_config_value *v4; // ecx
  const char *pointer; // esi
  vostok::particle::enum_evaluate_type v6; // eax
  unsigned int v7; // ebx
  const vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  vostok::buffer_string *v11; // ecx
  int v12; // ecx
  int v13; // esi
  vostok::buffer_string *v14; // ecx
  vostok::configs::binary_config_value *v15; // esi
  _DWORD *v16; // ebx
  _DWORD *v17; // eax
  int v18; // xmm0_4
  const vostok::configs::binary_config_value *v19; // eax
  _DWORD *v20; // esi
  vostok::configs::binary_config_value *v21; // [esp-4h] [ebp-A4h]
  vostok::configs::binary_config_value *v22; // [esp-4h] [ebp-A4h]
  unsigned int v23; // [esp+Ch] [ebp-94h]
  const char *v24; // [esp+Ch] [ebp-94h]
  vostok::configs::binary_config_value *v25; // [esp+10h] [ebp-90h]
  const char *v26; // [esp+14h] [ebp-8Ch]
  int v27; // [esp+18h] [ebp-88h]
  unsigned int v28; // [esp+1Ch] [ebp-84h]
  int v29; // [esp+20h] [ebp-80h]
  unsigned int v30; // [esp+24h] [ebp-7Ch]
  vostok::configs::binary_config_value *v31; // [esp+30h] [ebp-70h]
  int v32; // [esp+34h] [ebp-6Ch]
  char *v33[3]; // [esp+38h] [ebp-68h] BYREF
  _BYTE v34[16]; // [esp+44h] [ebp-5Ch] BYREF
  char *v35[3]; // [esp+54h] [ebp-4Ch] BYREF
  _BYTE v36[16]; // [esp+60h] [ebp-40h] BYREF
  vostok::configs::binary_config_value v37; // [esp+70h] [ebp-30h] BYREF
  _DWORD v38[6]; // [esp+88h] [ebp-18h] BYREF

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)&config.data.max_storage + 4,
         (unsigned int)"Input") )
  {
    pointer = (const char *)vostok::configs::binary_config_value::operator[](
                              (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
                              "Input")->data.pointer;
    v6 = vostok::strings::compare(pointer, "Age");
    if ( v6 )
      v6 = vostok::strings::compare(pointer, "Random") == 0;
    v4 = allocator;
    allocator->id_crc = v6;
  }
  v35[0] = v36;
  v35[1] = v36;
  v35[2] = (char *)&v37;
  v33[0] = v34;
  v33[1] = v34;
  v7 = 0;
  v33[2] = (char *)v35;
  v23 = 0;
  v36[0] = 0;
  v34[0] = 0;
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)&config.data.max_storage + 4, (unsigned int)"source") )
  {
    v8 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
           "source");
    if ( vostok::configs::binary_config_value::value_exists(v9, (int)v8, (unsigned int)"data") )
    {
      v10 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)((char *)&config.data.max_storage + 4),
              "source");
      v25 = vostok::configs::binary_config_value::operator[](v10, "data");
      vostok::fs_new::path_string_impl::assignf(v35, v11, (vostok::buffer_string *)"row%d", 0);
      while ( vostok::configs::binary_config_value::value_exists(v21, (int)v25, (unsigned int)v35[0]) )
      {
        qmemcpy((void *)&v37, vostok::configs::binary_config_value::operator[](v25, v35[0]), sizeof(v37));
        if ( !(24 * HIWORD(*(_DWORD *)&v37.type) / 24) )
          break;
        while ( 1 )
        {
          vostok::fs_new::path_string_impl::assignf(
            v33,
            (vostok::buffer_string *)0x18,
            (vostok::buffer_string *)"element%d",
            (const char *)v7);
          if ( !vostok::configs::binary_config_value::value_exists(v22, (int)&v37, (unsigned int)v33[0]) )
            break;
          qmemcpy(v38, vostok::configs::binary_config_value::operator[](&v37, v33[0]), sizeof(v38));
          v12 = 24;
          if ( !(24 * HIWORD(v38[5]) / 24) )
            break;
          ++v7;
        }
        vostok::fs_new::path_string_impl::assignf(
          v35,
          (vostok::buffer_string *)v12,
          (vostok::buffer_string *)"row%d",
          (const char *)++v23);
      }
      v13 = 0;
      v28 = v23;
      v30 = v7;
      if ( v23 )
      {
        if ( v7 )
        {
          vostok::particle::color_matrix::allocate_memory(
            (vostok::particle::color_matrix *)allocator,
            v23,
            (vostok::particle::color_matrix *)config.data.pointer,
            v7);
          v24 = 0;
          if ( v28 )
          {
            v29 = 0;
            v32 = 24 * v7;
            do
            {
              vostok::fs_new::path_string_impl::assignf(v35, v14, (vostok::buffer_string *)"row%d", v24);
              v26 = 0;
              v31 = vostok::configs::binary_config_value::operator[](v25, v35[0]);
              if ( v30 )
              {
                v27 = v13;
                do
                {
                  vostok::fs_new::path_string_impl::assignf(v33, v14, (vostok::buffer_string *)"element%d", v26);
                  v15 = vostok::configs::binary_config_value::operator[](v31, v33[0]);
                  v16 = (char *)allocator->data.pointer + v27;
                  v17 = vostok::configs::binary_config_value::operator[](v15, "position")->data.pointer;
                  v18 = v17[1];
                  v16[4] = *v17;
                  v16[5] = v18;
                  v19 = vostok::configs::binary_config_value::operator[](v15, "color");
                  v20 = v19->data.pointer;
                  ++v26;
                  v27 += 24;
                  *v16 = *(_DWORD *)v19->data.pointer;
                  v16[1] = *++v20;
                  v16[2] = *++v20;
                  v16[3] = v20[1];
                }
                while ( (unsigned int)v26 < v30 );
              }
              ++v24;
              v13 = v32 + v29;
              v29 += v32;
            }
            while ( (unsigned int)v24 < v28 );
          }
        }
      }
    }
  }
}
