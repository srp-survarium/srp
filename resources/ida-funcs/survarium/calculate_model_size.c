int __usercall survarium::calculate_model_size@<eax>(const vostok::configs::binary_config_value *model_value@<eax>)
{
  int count; // ecx
  vostok::configs::binary_config_value *pointer; // eax
  int v3; // esi
  const vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // ebx
  int v6; // esi
  const vostok::configs::binary_config_value *v7; // eax
  const vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // ebx
  const vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v12; // [esp+8h] [ebp-Ch]
  int v13; // [esp+Ch] [ebp-8h]
  int v14; // [esp+Ch] [ebp-8h]
  vostok::configs::binary_config_value *v15; // [esp+10h] [ebp-4h]

  count = model_value->count;
  pointer = (vostok::configs::binary_config_value *)model_value->data.pointer;
  v3 = 224 * (count * 24 / 24) + 1800;
  v15 = pointer;
  v12 = &pointer[count];
  if ( pointer != &pointer[count] )
  {
    while ( 1 )
    {
      v4 = vostok::configs::binary_config_value::operator[](pointer, "hit_types");
      v5 = (vostok::configs::binary_config_value *)v4->data.pointer;
      v13 = (int)v4->data.pointer + 24 * v4->count;
      v6 = 32 * (24 * v4->count / 24) + v3;
      if ( v4->data.pointer != (const void *)v13 )
      {
        do
        {
          v7 = vostok::configs::binary_config_value::operator[](v5++, "bdb_coeff");
          v6 += 8 * (24 * v7->count / 24);
        }
        while ( v5 != (vostok::configs::binary_config_value *)v13 );
      }
      v8 = vostok::configs::binary_config_value::operator[](v15, "thresholds");
      v9 = (vostok::configs::binary_config_value *)v8->data.pointer;
      v14 = (int)v8->data.pointer + 24 * v8->count;
      v3 = 20 * (24 * v8->count / 24) + v6;
      if ( v8->data.pointer != (const void *)v14 )
      {
        do
        {
          v10 = vostok::configs::binary_config_value::operator[](v9++, "affects");
          v3 += 4 * (24 * v10->count / 24);
        }
        while ( v9 != (vostok::configs::binary_config_value *)v14 );
      }
      if ( ++v15 == v12 )
        break;
      pointer = v15;
    }
  }
  return v3;
}
