void __cdecl idea_set_encrypt_key(const unsigned __int8 *key, idea_key_st *ks)
{
  unsigned int *v2; // ecx
  int v3; // esi
  unsigned int *v4; // eax
  int i; // ebx
  unsigned int v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // esi
  _DWORD *v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // esi
  unsigned int v13; // edx
  unsigned int v14; // esi
  _DWORD *v15; // eax
  _DWORD *v16; // eax

  ks->data[0][0] = *key << 8;
  ks->data[0][0] |= key[1];
  ks->data[0][1] = key[2] << 8;
  ks->data[0][1] |= key[3];
  ks->data[0][2] = key[4] << 8;
  ks->data[0][2] |= key[5];
  v2 = &ks->data[0][2];
  ks->data[0][3] = key[6] << 8;
  ks->data[0][3] |= key[7];
  ks->data[0][4] = key[8] << 8;
  ks->data[0][4] |= key[9];
  ks->data[0][5] = key[10] << 8;
  ks->data[0][5] |= key[11];
  ks->data[1][0] = key[12] << 8;
  ks->data[1][0] |= key[13];
  v3 = key[14] << 8;
  ks->data[1][1] = v3;
  ks->data[1][1] = v3 | key[15];
  v4 = &ks->data[1][2];
  for ( i = 0; i < 6; ++i )
  {
    v6 = *v2;
    v7 = *(v2 - 1);
    *v4 = (unsigned __int16)(((_WORD)v7 << 9) | (*v2 >> 7));
    v8 = v2[1];
    v4[1] = (unsigned __int16)(((_WORD)v6 << 9) | (v8 >> 7));
    v9 = v2[2];
    v10 = v4 + 1;
    v10[1] = (unsigned __int16)((v9 >> 7) | ((_WORD)v8 << 9));
    v11 = v2[3];
    ++v10;
    v10[1] = (unsigned __int16)(((_WORD)v9 << 9) | (v11 >> 7));
    v12 = v2[4];
    v10 += 2;
    *v10 = (unsigned __int16)((v12 >> 7) | ((_WORD)v11 << 9));
    v13 = v2[5];
    *++v10 = (unsigned __int16)(((_WORD)v12 << 9) | (v13 >> 7));
    v14 = *(v2 - 2);
    v15 = v10 + 1;
    if ( i >= 5 )
      break;
    *v15 = (unsigned __int16)((v14 >> 7) | ((_WORD)v13 << 9));
    v16 = v15 + 1;
    *v16 = (unsigned __int16)((v7 >> 7) | ((_WORD)v14 << 9));
    v4 = v16 + 1;
    v2 += 8;
  }
}
