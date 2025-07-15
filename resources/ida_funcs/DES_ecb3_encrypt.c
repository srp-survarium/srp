void __cdecl DES_ecb3_encrypt(
        unsigned __int8 (*input)[8],
        unsigned __int8 (*output)[8],
        DES_ks *ks1,
        DES_ks *ks2,
        DES_ks *ks3,
        int enc)
{
  int v6; // edx
  int v7; // esi
  __int16 v8; // ecx^2
  __int16 v9; // ecx^2
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h]

  v6 = (*input)[4];
  v7 = (*input)[5];
  v10 = ((*input)[3] << 24) | ((*input)[2] << 16) | *(unsigned __int16 *)input;
  v11 = (v7 << 8) | v6 | (*(unsigned __int16 *)&(*input)[6] << 16);
  if ( enc )
    DES_encrypt3(&v10, ks1, ks2, ks3);
  else
    DES_decrypt3(&v10, ks1, ks2, ks3);
  v8 = HIWORD(v10);
  *(_WORD *)output = v10;
  *(_WORD *)&(*output)[2] = v8;
  v9 = HIWORD(v11);
  *(_WORD *)&(*output)[4] = v11;
  *(_WORD *)&(*output)[6] = v9;
}
