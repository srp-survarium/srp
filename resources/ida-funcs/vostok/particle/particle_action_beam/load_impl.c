void __userpurge vostok::particle::particle_action_beam::load_impl<vostok::configs::binary_config_value>(
        vostok::particle::particle_action_beam *this@<ecx>,
        int a2@<eax>,
        const vostok::configs::binary_config_value *allocator,
        const vostok::configs::binary_config_value *prop_config)
{
  unsigned int *v5; // edi
  const vostok::configs::binary_config_value *v6; // ebx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  int v11; // xmm0_4
  const vostok::configs::binary_config_value *v12; // esi
  vostok::configs::binary_config_value *v13; // ecx
  unsigned int v14; // eax
  unsigned int pointer; // eax
  unsigned int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm2_4
  int *v20; // [esp+Ch] [ebp-Ch]
  float *v21; // [esp+10h] [ebp-8h]
  unsigned int *v22; // [esp+14h] [ebp-4h]

  v5 = (unsigned int *)(a2 + 24);
  v6 = (const vostok::configs::binary_config_value *)(a2 + 28);
  *(_DWORD *)(a2 + 24) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                           "SheetsCount",
                           (vostok::configs::binary_config_value *)this,
                           allocator,
                           (const vostok::configs::binary_config_value *)(a2 + 24));
  v6->data.pointer = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                       "TextureTile",
                       v7,
                       allocator,
                       v6);
  *(_BYTE *)(a2 + 36) = vostok::particle::read_config_value<bool,vostok::configs::binary_config_value>(
                          "ContinuousUV",
                          v8,
                          allocator,
                          (const bool *)(a2 + 36));
  v22 = (unsigned int *)(a2 + 32);
  *(_DWORD *)(a2 + 32) = vostok::particle::read_config_value<char const *,vostok::configs::binary_config_value>(
                           "BeamsCount",
                           v9,
                           allocator,
                           (const vostok::configs::binary_config_value *)(a2 + 32));
  v21 = (float *)(a2 + 40);
  *(_DWORD *)(a2 + 40) = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                           "Speed",
                           (vostok::configs::binary_config_value *)(a2 + 32),
                           allocator,
                           (const vostok::configs::binary_config_value *)(a2 + 40));
  v20 = (int *)(a2 + 44);
  v11 = vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
          "Noise",
          v10,
          allocator,
          (const vostok::configs::binary_config_value *)(a2 + 44));
  v12 = (const vostok::configs::binary_config_value *)(a2 + 48);
  *v20 = v11;
  v12->data.pointer = (const void *)vostok::particle::read_config_value<float,vostok::configs::binary_config_value>(
                                      "Frequency",
                                      v13,
                                      allocator,
                                      v12);
  v14 = *v5;
  if ( *v5 )
  {
    if ( v14 > 0x3E8 )
      v14 = 1000;
  }
  else
  {
    v14 = 0;
  }
  *v5 = v14;
  pointer = (unsigned int)v6->data.pointer;
  if ( v6->data.pointer )
  {
    if ( pointer > 0x3E8 )
      pointer = 1000;
  }
  else
  {
    pointer = 0;
  }
  v6->data.pointer = (const void *)pointer;
  v16 = *v22;
  if ( *v22 > 1 )
  {
    if ( v16 > 0x3E8 )
      v16 = 1000;
  }
  else
  {
    v16 = 1;
  }
  v17 = 0.0;
  *v22 = v16;
  v18 = *v21;
  if ( *v21 > 0.0 )
  {
    if ( v18 > 1000.0 )
      v18 = FLOAT_1000_0;
  }
  else
  {
    v18 = 0.0;
  }
  *v21 = v18;
  v19 = *(float *)v20;
  if ( *(float *)v20 > 0.0 )
  {
    if ( v19 > 1000.0 )
      v19 = FLOAT_1000_0;
  }
  else
  {
    v19 = 0.0;
  }
  *(float *)v20 = v19;
  if ( *(float *)&v12->data.pointer > 0.0 )
  {
    if ( *(float *)&v12->data.pointer > 1000.0 )
      v17 = FLOAT_1000_0;
    else
      v17 = *(float *)&v12->data.pointer;
  }
  *(float *)&v12->data.pointer = v17;
}
