void __userpurge vostok::animation::EtCurve::load(
        vostok::animation::EtCurve *this@<ecx>,
        int a2@<eax>,
        const vostok::configs::binary_config_value *t)
{
  int v4; // ebx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  vostok::animation::EtKey *v7; // ecx
  unsigned int v8; // eax
  unsigned int v9; // edi
  unsigned __int8 *v10; // esi
  const vostok::configs::binary_config_value *v11; // eax
  vostok::animation::EtKey *v12; // ecx
  stlp_std::__true_type v13[28]; // [esp+Ch] [ebp-28h] BYREF
  unsigned int v14; // [esp+28h] [ebp-Ch]
  int v15; // [esp+2Ch] [ebp-8h]
  int v16; // [esp+30h] [ebp-4h]

  v4 = a2 + 68;
  v5 = *(unsigned __int8 **)(a2 + 72);
  if ( *(unsigned __int8 **)v4 != v5 )
    *(_DWORD *)(v4 + 4) = stlp_std::priv::__copy_trivial(v5, v5, *(unsigned __int8 **)v4);
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = -1;
  *(_DWORD *)(a2 + 20) = -1;
  *(_BYTE *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 25) = 0;
  v14 = 24 * vostok::configs::binary_config_value::operator[](t, "keys")->count / 24;
  *(_BYTE *)a2 = vostok::configs::binary_config_value::operator[](t, "is_weighted")->data.pointer != 0;
  *(_BYTE *)(a2 + 1) = vostok::configs::binary_config_value::operator[](t, "is_static")->data.pointer != 0;
  *(_DWORD *)(a2 + 4) = vostok::configs::binary_config_value::operator[](t, "pre_inf")->data.pointer;
  *(_DWORD *)(a2 + 8) = vostok::configs::binary_config_value::operator[](t, "post_inf")->data.pointer;
  v6 = *(unsigned __int8 **)v4;
  memset(v13, 0, sizeof(v13));
  v7 = *(vostok::animation::EtKey **)(v4 + 4);
  v8 = ((char *)v7 - (char *)v6) / 28;
  v9 = v14;
  if ( v14 >= v8 )
  {
    stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey>>::_M_fill_insert(
      (stlp_std::priv::_Impl_vector<vostok::animation::EtKey,vostok::vectora_allocator<vostok::animation::EtKey> > *)v4,
      v14 - v8,
      v7,
      v13);
  }
  else if ( &v6[28 * v14] != (unsigned __int8 *)v7 )
  {
    *(_DWORD *)(v4 + 4) = stlp_std::priv::__copy_trivial((unsigned __int8 *)v7, (unsigned __int8 *)v7, &v6[28 * v14]);
  }
  if ( v9 )
  {
    v15 = 0;
    v16 = 0;
    v14 = v9;
    do
    {
      v10 = *(unsigned __int8 **)v4;
      v11 = vostok::configs::binary_config_value::operator[](t, "keys");
      vostok::animation::EtKey::load(
        v12,
        (int)&v10[v15],
        (const vostok::configs::binary_config_value *)((char *)v11->data.pointer + v16));
      v16 += 24;
      v15 += 28;
      --v14;
    }
    while ( v14 );
  }
}
