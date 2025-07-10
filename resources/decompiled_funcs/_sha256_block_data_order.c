// positive sp value has been detected, the output may be wrong!
int sha256_block_data_order()
{
  int *v0; // esi
  unsigned int *v1; // edi
  int *v2; // ebp
  int v3; // eax
  int v4; // edx
  int v5; // edi
  int v6; // ebx
  int v7; // edi
  int v8; // esi
  unsigned int v9; // ebx
  int v10; // esi
  int v11; // edi
  int v12; // ebx
  int v13; // edi
  int v14; // ebx
  int v15; // edi
  int v16; // edx
  int v17; // esi
  int v18; // eax
  int v19; // ebx
  int v20; // ecx
  int v21; // edi
  int result; // eax
  int v23; // ebx
  int v24; // ecx
  int v25; // [esp-E8h] [ebp-16Ch]
  int v26; // [esp-E4h] [ebp-168h]
  int v27; // [esp-E0h] [ebp-164h]
  int v28; // [esp-DCh] [ebp-160h]
  int v29; // [esp-D8h] [ebp-15Ch]
  int v30; // [esp-D8h] [ebp-15Ch]
  int v31; // [esp-D4h] [ebp-158h]
  int v32; // [esp-D0h] [ebp-154h]
  int v33; // [esp-CCh] [ebp-150h]
  int v34; // [esp-C8h] [ebp-14Ch]
  unsigned __int32 v35; // [esp-88h] [ebp-10Ch]
  int v36; // [esp-70h] [ebp-F4h]
  unsigned int v37; // [esp-60h] [ebp-E4h]
  unsigned int *v38; // [esp-5Ch] [ebp-E0h]
  unsigned int v39; // [esp-54h] [ebp-D8h]
  unsigned int v40; // [esp-50h] [ebp-D4h]
  int v41; // [esp-4Ch] [ebp-D0h]
  int *v42; // [esp+74h] [ebp-10h]
  unsigned int *v43; // [esp+78h] [ebp-Ch]
  unsigned int v44; // [esp+7Ch] [ebp-8h]

  v0 = (int *)v37;
  v1 = v38;
  v2 = _L001K256;
  do
  {
    v35 = _byteswap_ulong(*v1);
    v3 = *v0;
    v27 = v0[1];
    v28 = v0[2];
    v29 = v0[3];
    v4 = v0[4];
    v32 = v0[5];
    v33 = v0[6];
    v34 = v0[7];
    do
    {
      v5 = __ROR4__(v4, 11);
      v31 = v4;
      v6 = v34 + (v33 ^ v4 & (v33 ^ v32)) + (__ROR4__(v5, 14) ^ v5 ^ __ROR4__(v4, 6)) + v35;
      v7 = __ROR4__(v3, 13);
      v26 = v3;
      v8 = *v2++;
      v4 = v8 + v6 + v29;
      v3 = v8 + (__ROR4__(v7, 9) ^ v7 ^ __ROR4__(v3, 2)) + v6 + (v27 & v3 | v28 & (v27 | v3));
    }
    while ( v8 != -1046744716 );
    v9 = v40;
    do
    {
      v10 = __ROR4__(v9, 7);
      v11 = __ROR4__(v37, 17);
      v12 = (v11 ^ (v37 >> 10) ^ __ROR4__(v11, 2)) + v41 + (__ROR4__(v10, 11) ^ v10 ^ (v9 >> 3));
      v13 = __ROR4__(v4, 11);
      v30 = v4;
      v14 = v33 + (v32 ^ v4 & (v32 ^ v31)) + (__ROR4__(v13, 14) ^ v13 ^ __ROR4__(v4, 6)) + v36 + v12;
      v15 = __ROR4__(v3, 13);
      v16 = v14 + v28;
      v25 = v3;
      v17 = *v2++;
      v18 = (__ROR4__(v15, 9) ^ v15 ^ __ROR4__(v3, 2)) + v14 + (v26 & v3 | v27 & (v26 | v3));
      v9 = v39;
      v4 = v17 + v16;
      v3 = v17 + v18;
    }
    while ( v17 != -965641998 );
    v0 = v42;
    v19 = v42[1] + v25;
    v20 = v42[2] + v26;
    v21 = v42[3] + v27;
    *v42 += v3;
    v42[1] = v19;
    v42[2] = v20;
    v42[3] = v21;
    v1 = v43;
    result = v42[5] + v30;
    v23 = v42[6] + v31;
    v24 = v42[7] + v32;
    v42[4] += v4;
    v42[5] = result;
    v42[6] = v23;
    v42[7] = v24;
    v2 -= 64;
  }
  while ( (unsigned int)v43 < v44 );
  return result;
}
