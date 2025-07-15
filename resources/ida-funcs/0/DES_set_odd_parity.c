void __cdecl DES_set_odd_parity(unsigned __int8 (*key)[8])
{
  int v1; // ecx
  unsigned __int8 v2; // dl
  int v3; // ecx
  unsigned __int8 v4; // dl
  int v5; // ecx
  unsigned __int8 v6; // dl
  int v7; // ecx
  unsigned __int8 v8; // dl
  int v9; // ecx
  unsigned __int8 v10; // dl
  int v11; // ecx
  unsigned __int8 v12; // dl
  int v13; // ecx

  v1 = (*key)[1];
  (*key)[0] = odd_parity[(*key)[0]];
  v2 = odd_parity[v1];
  v3 = (*key)[2];
  (*key)[1] = v2;
  v4 = odd_parity[v3];
  v5 = (*key)[3];
  (*key)[2] = v4;
  v6 = odd_parity[v5];
  v7 = (*key)[4];
  (*key)[3] = v6;
  v8 = odd_parity[v7];
  v9 = (*key)[5];
  (*key)[4] = v8;
  v10 = odd_parity[v9];
  v11 = (*key)[6];
  (*key)[5] = v10;
  v12 = odd_parity[v11];
  v13 = (*key)[7];
  (*key)[6] = v12;
  (*key)[7] = odd_parity[v13];
}
