void __cdecl BF_set_key(bf_key_st *key, int len, const unsigned __int8 *data)
{
  int v4; // ecx
  const unsigned __int8 *v5; // eax
  const unsigned __int8 *v6; // ecx
  unsigned int *v7; // esi
  int v8; // edx
  const unsigned __int8 *v9; // eax
  int v10; // ebp
  const unsigned __int8 *v11; // eax
  int v12; // edx
  int v13; // ebp
  const unsigned __int8 *v14; // eax
  int v15; // edx
  int v16; // ebp
  const unsigned __int8 *v17; // eax
  int v18; // edx
  int v19; // edx
  const unsigned __int8 *v20; // eax
  int v21; // ebp
  const unsigned __int8 *v22; // eax
  int v23; // edx
  int v24; // ebp
  const unsigned __int8 *v25; // eax
  int v26; // edx
  int v27; // ebp
  const unsigned __int8 *v28; // eax
  int v29; // edx
  int v30; // edx
  const unsigned __int8 *v31; // eax
  int v32; // ebp
  const unsigned __int8 *v33; // eax
  int v34; // edx
  int v35; // ebp
  const unsigned __int8 *v36; // eax
  int v37; // edx
  int v38; // ebp
  int v39; // edx
  int i; // esi
  unsigned int v41; // edx
  int j; // esi
  unsigned int v43; // edx
  unsigned int v44; // [esp+8h] [ebp-8h] BYREF
  unsigned int v45; // [esp+Ch] [ebp-4h]
  int dst; // [esp+14h] [ebp+4h]

  memcpy((unsigned __int8 *)key, (unsigned __int8 *)&bf_init, sizeof(bf_key_st));
  v4 = len;
  if ( len > 72 )
    v4 = 72;
  v5 = data;
  v6 = &data[v4];
  v7 = &key->P[2];
  dst = 6;
  do
  {
    v8 = *v5;
    v9 = v5 + 1;
    if ( v9 >= v6 )
      v9 = data;
    v10 = *v9;
    v11 = v9 + 1;
    v12 = v10 | (v8 << 8);
    if ( v11 >= v6 )
      v11 = data;
    v13 = *v11;
    v14 = v11 + 1;
    v15 = v13 | (v12 << 8);
    if ( v14 >= v6 )
      v14 = data;
    v16 = *v14;
    v17 = v14 + 1;
    v18 = v16 | (v15 << 8);
    if ( v17 >= v6 )
      v17 = data;
    *(v7 - 2) ^= v18;
    v19 = *v17;
    v20 = v17 + 1;
    if ( v20 >= v6 )
      v20 = data;
    v21 = *v20;
    v22 = v20 + 1;
    v23 = v21 | (v19 << 8);
    if ( v22 >= v6 )
      v22 = data;
    v24 = *v22;
    v25 = v22 + 1;
    v26 = v24 | (v23 << 8);
    if ( v25 >= v6 )
      v25 = data;
    v27 = *v25;
    v28 = v25 + 1;
    v29 = v27 | (v26 << 8);
    if ( v28 >= v6 )
      v28 = data;
    *(v7 - 1) ^= v29;
    v30 = *v28;
    v31 = v28 + 1;
    if ( v31 >= v6 )
      v31 = data;
    v32 = *v31;
    v33 = v31 + 1;
    v34 = v32 | (v30 << 8);
    if ( v33 >= v6 )
      v33 = data;
    v35 = *v33;
    v36 = v33 + 1;
    v37 = v35 | (v34 << 8);
    if ( v36 >= v6 )
      v36 = data;
    v38 = *v36;
    v5 = v36 + 1;
    v39 = v38 | (v37 << 8);
    if ( v5 >= v6 )
      v5 = data;
    *v7 ^= v39;
    v7 += 3;
    --dst;
  }
  while ( dst );
  v44 = 0;
  v45 = 0;
  for ( i = 0; i < 18; i += 2 )
  {
    BF_encrypt(&v44, key);
    v41 = v45;
    key->P[i] = v44;
    key->P[i + 1] = v41;
  }
  for ( j = 0; j < 1024; j += 2 )
  {
    BF_encrypt(&v44, key);
    v43 = v45;
    key->S[j] = v44;
    key->S[j + 1] = v43;
  }
}
