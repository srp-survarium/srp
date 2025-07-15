void __usercall vostok::animation::mixing::n_ary_tree_deserializer::process_animated_objects(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        int a2@<esi>)
{
  char v2; // bl
  unsigned int i; // edi
  unsigned int v4; // eax
  __int32 v5; // eax
  _DWORD *v6; // ecx
  int v7; // xmm0_4
  __int32 v8; // eax
  int v9; // xmm0_4
  __int32 v10; // eax
  int v11; // xmm0_4
  __int32 v12; // eax
  int v13; // xmm0_4
  __int32 v14; // eax
  int v15; // xmm0_4
  __int32 v16; // eax
  int v17; // xmm0_4
  __int32 v18; // eax
  int v19; // xmm0_4
  __int32 v20; // eax
  int v21; // xmm0_4
  __int32 v22; // eax
  int v23; // xmm0_4
  __int32 v24; // eax
  int v25; // xmm0_4
  __int32 v26; // eax
  int v27; // xmm0_4
  __int32 v28; // eax
  int v29; // xmm0_4
  __int32 v30; // [esp+8h] [ebp-4h] BYREF

  v2 = 0;
  for ( i = 0; i < 0x110; i += 136 )
  {
    v4 = i + *(_DWORD *)(a2 + 8248);
    if ( v4 )
    {
      *(_DWORD *)(v4 + 128) = 0;
      *(_BYTE *)(v4 + 132) = v2;
      *(_BYTE *)(v4 + 133) = 0;
    }
    vostok::math::float4x4::identity(
      (vostok::math::float4x4 *)this,
      (vostok::math::float4x4 *)(i + *(_DWORD *)(a2 + 8248)));
    ++v2;
  }
  v5 = *(_DWORD *)(a2 + 4116);
  v6 = *(_DWORD **)(a2 + 8248);
  v7 = *(_DWORD *)(v5 - 4);
  _InterlockedExchange(&v30, v5);
  *(_DWORD *)(a2 + 4116) -= 4;
  v8 = *(_DWORD *)(a2 + 4116);
  *v6 = v7;
  v9 = *(_DWORD *)(v8 - 4);
  _InterlockedExchange(&v30, v8);
  *(_DWORD *)(a2 + 4116) -= 4;
  v10 = *(_DWORD *)(a2 + 4116);
  v6[1] = v9;
  v11 = *(_DWORD *)(v10 - 4);
  _InterlockedExchange(&v30, v10);
  *(_DWORD *)(a2 + 4116) -= 4;
  v12 = *(_DWORD *)(a2 + 4116);
  v6[2] = v11;
  v13 = *(_DWORD *)(v12 - 4);
  _InterlockedExchange(&v30, v12);
  *(_DWORD *)(a2 + 4116) -= 4;
  v14 = *(_DWORD *)(a2 + 4116);
  v6[4] = v13;
  v15 = *(_DWORD *)(v14 - 4);
  _InterlockedExchange(&v30, v14);
  *(_DWORD *)(a2 + 4116) -= 4;
  v16 = *(_DWORD *)(a2 + 4116);
  v6[5] = v15;
  v17 = *(_DWORD *)(v16 - 4);
  _InterlockedExchange(&v30, v16);
  *(_DWORD *)(a2 + 4116) -= 4;
  v18 = *(_DWORD *)(a2 + 4116);
  v6[6] = v17;
  v19 = *(_DWORD *)(v18 - 4);
  _InterlockedExchange(&v30, v18);
  *(_DWORD *)(a2 + 4116) -= 4;
  v20 = *(_DWORD *)(a2 + 4116);
  v6[8] = v19;
  v21 = *(_DWORD *)(v20 - 4);
  _InterlockedExchange(&v30, v20);
  *(_DWORD *)(a2 + 4116) -= 4;
  v22 = *(_DWORD *)(a2 + 4116);
  v6[9] = v21;
  v23 = *(_DWORD *)(v22 - 4);
  _InterlockedExchange(&v30, v22);
  *(_DWORD *)(a2 + 4116) -= 4;
  v24 = *(_DWORD *)(a2 + 4116);
  v6[10] = v23;
  v25 = *(_DWORD *)(v24 - 4);
  _InterlockedExchange(&v30, v24);
  *(_DWORD *)(a2 + 4116) -= 4;
  v26 = *(_DWORD *)(a2 + 4116);
  v6[12] = v25;
  v27 = *(_DWORD *)(v26 - 4);
  _InterlockedExchange(&v30, v26);
  *(_DWORD *)(a2 + 4116) -= 4;
  v28 = *(_DWORD *)(a2 + 4116);
  v6[13] = v27;
  v29 = *(_DWORD *)(v28 - 4);
  _InterlockedExchange(&v30, v28);
  *(_DWORD *)(a2 + 4116) -= 4;
  v6[14] = v29;
}
