void __cdecl idea_set_decrypt_key(idea_key_st *ek, idea_key_st *dk)
{
  unsigned int *v2; // edi
  idea_key_st *v3; // esi
  int i; // ebx
  int *v5; // esi
  _DWORD *v6; // esi
  int v7; // edx
  _DWORD *v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // eax

  v2 = ek->data[8];
  v3 = dk;
  for ( i = 0; i < 9; ++i )
  {
    v3->data[0][0] = inverse(*v2);
    v5 = (int *)&v3->data[0][1];
    *v5++ = (unsigned __int16)-*((_WORD *)v2 + 4);
    *v5++ = (unsigned __int16)-*((_WORD *)v2 + 2);
    *v5 = inverse(v2[3]);
    v6 = v5 + 1;
    if ( i == 8 )
      break;
    v7 = *(v2 - 2);
    v2 -= 6;
    *v6 = v7;
    v8 = v6 + 1;
    *v8 = v2[5];
    v3 = (idea_key_st *)(v8 + 1);
  }
  v9 = dk->data[0][2];
  v10 = dk->data[8][2];
  dk->data[0][2] = dk->data[0][1];
  v11 = dk->data[8][1];
  dk->data[0][1] = v9;
  dk->data[8][1] = v10;
  dk->data[8][2] = v11;
}
