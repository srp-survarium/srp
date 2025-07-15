void __cdecl DES_ecb_encrypt(unsigned __int8 (*input)[8], unsigned __int8 (*output)[8], DES_ks *ks, int enc)
{
  int v4; // edx
  __int16 v5; // ecx^2
  __int16 v6; // ecx^2
  int v7; // [esp+0h] [ebp-8h] BYREF
  int v8; // [esp+4h] [ebp-4h]

  v4 = (*input)[5];
  v7 = ((*input)[3] << 24) | ((*input)[2] << 16) | *(unsigned __int16 *)input;
  v8 = (v4 << 8) | (*input)[4] | (*(unsigned __int16 *)&(*input)[6] << 16);
  DES_encrypt1(&v7, ks, enc);
  v5 = HIWORD(v7);
  *(_WORD *)output = v7;
  *(_WORD *)&(*output)[2] = v5;
  v6 = HIWORD(v8);
  *(_WORD *)&(*output)[4] = v8;
  *(_WORD *)&(*output)[6] = v6;
}
