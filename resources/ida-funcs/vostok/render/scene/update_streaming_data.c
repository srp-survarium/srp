void __thiscall vostok::render::scene::update_streaming_data(vostok::render::scene *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // ecx
  float *j; // ebx
  int *v6; // eax
  int v7; // ecx
  double v8; // st7
  int v9; // ecx
  double v10; // st7
  float v11; // eax
  int v12; // eax
  int v13; // edx
  _BYTE v14[16]; // [esp+0h] [ebp-18h] BYREF
  int i; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]

  v2 = a2;
  v3 = *(int *)((char *)&dword_96154 + a2);
  v4 = *(int *)((char *)&dword_96158 + a2);
  v16 = v3;
  for ( i = v4; v3 != i; v16 = v3 )
  {
    for ( j = *(float **)(v3 + 272); j; j = (float *)*((_DWORD *)j + 1) )
    {
      if ( *(_BYTE *)(*(_DWORD *)j + 4) )
      {
        v6 = (int *)(***(int (__thiscall ****)(_DWORD, _BYTE *))j)(*(_DWORD *)j, v14);
        v7 = *(_DWORD *)j;
        *((_DWORD *)j + 3) = *v6;
        *((_DWORD *)j + 4) = v6[1];
        *((_DWORD *)j + 5) = v6[2];
        *((_DWORD *)j + 6) = v6[3];
        v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v7 + 4))(v7);
        v9 = *(_DWORD *)j;
        j[7] = v8;
        v10 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 8))(v9);
        v11 = *j;
        j[8] = v10;
        v2 = a2;
        j[2] = *(float *)(LODWORD(v11) + 8);
      }
    }
    v3 = v16 + 328;
  }
  v12 = *(_DWORD *)((char *)&loc_1BE17C + v2);
  v13 = *(_DWORD *)((char *)&loc_1BE17F + v2 + 1);
  while ( v12 != v13 )
  {
    *(_BYTE *)(*(_DWORD *)v12 + 4) = 0;
    v12 += 4;
  }
}
