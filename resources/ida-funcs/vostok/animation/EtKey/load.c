void __userpurge vostok::animation::EtKey::load(
        vostok::animation::EtKey *this@<ecx>,
        int a2@<esi>,
        const vostok::configs::binary_config_value *t)
{
  const vostok::configs::binary_config_value *v3; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v5; // eax
  float v6; // xmm0_4
  _DWORD *v7; // eax
  int v8; // xmm1_4
  _DWORD *v9; // eax
  int v10; // xmm1_4
  vostok::configs::binary_config_value *v11; // ecx
  const void *v12; // eax

  v3 = vostok::configs::binary_config_value::operator[](t, "time");
  if ( v3->type == 2 )
    pointer = *(float *)&v3->data.pointer;
  else
    pointer = (float)(int)v3->data.pointer;
  *(float *)a2 = pointer;
  v5 = vostok::configs::binary_config_value::operator[](t, "value");
  if ( v5->type == 2 )
    v6 = *(float *)&v5->data.pointer;
  else
    v6 = (float)(int)v5->data.pointer;
  *(float *)(a2 + 4) = v6;
  v7 = vostok::configs::binary_config_value::operator[](t, "in_tan")->data.pointer;
  v8 = v7[1];
  *(_DWORD *)(a2 + 8) = *v7;
  *(_DWORD *)(a2 + 12) = v8;
  v9 = vostok::configs::binary_config_value::operator[](t, "out_tan")->data.pointer;
  v10 = v9[1];
  *(_DWORD *)(a2 + 16) = *v9;
  *(_DWORD *)(a2 + 20) = v10;
  if ( vostok::configs::binary_config_value::value_exists(v11, (int)t, (unsigned int)"type") )
    v12 = vostok::configs::binary_config_value::operator[](t, "type")->data.pointer;
  else
    LOBYTE(v12) = 0;
  *(_BYTE *)(a2 + 24) = (_BYTE)v12;
}
