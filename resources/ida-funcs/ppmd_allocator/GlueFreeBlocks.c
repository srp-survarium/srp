void __usercall ppmd_allocator::GlueFreeBlocks(ppmd_allocator *this@<ecx>, _DWORD *a2@<esi>)
{
  _BYTE *v2; // eax
  int *v3; // edi
  int **v4; // ecx
  int *v5; // eax
  int *v6; // edx
  int v7; // edx
  int *v8; // edx
  _DWORD *i; // ecx
  _DWORD *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // edx
  int v13; // edx
  unsigned int v14; // edi
  _DWORD *v15; // edx
  _DWORD *v16; // eax
  int v17; // edi
  _DWORD *v18; // eax
  int v19; // [esp+0h] [ebp-14h] BYREF
  _DWORD *v20; // [esp+4h] [ebp-10h]
  int v21; // [esp+Ch] [ebp-8h]
  int v22; // [esp+10h] [ebp-4h]

  v2 = (_BYTE *)a2[124];
  if ( v2 != (_BYTE *)a2[125] )
    *v2 = 0;
  v20 = 0;
  v3 = &v19;
  v4 = (int **)(a2 + 2);
  v22 = 38;
  do
  {
    while ( *v4 )
    {
      v5 = *v4;
      v6 = (int *)(*v4)[1];
      *(v4 - 1) = (int *)((char *)*(v4 - 1) - 1);
      *v4 = v6;
      v7 = v5[2];
      if ( v7 )
      {
        while ( 1 )
        {
          v8 = &v5[3 * v7];
          if ( *v8 != -1 )
            break;
          v5[2] += v8[2];
          v8[2] = 0;
          v7 = v5[2];
        }
        v5[1] = v3[1];
        v3[1] = (int)v5;
        v3 = v5;
      }
    }
    v4 += 2;
    --v22;
  }
  while ( v22 );
  for ( i = v20; v20; i = v20 )
  {
    v10 = (_DWORD *)i[1];
    --v19;
    v20 = v10;
    v11 = i[2];
    if ( v11 )
    {
      if ( v11 > 0x80 )
      {
        v12 = ((v11 - 129) >> 7) + 1;
        do
        {
          i[1] = a2[76];
          a2[76] = i;
          *i = -1;
          i[2] = 128;
          ++a2[75];
          v11 -= 128;
          i += 384;
          --v12;
        }
        while ( v12 );
      }
      v13 = *((unsigned __int8 *)a2 + v11 + 345);
      v22 = (int)a2 + v13 + 308;
      if ( *(unsigned __int8 *)v22 != v11 )
      {
        v21 = v13 - 1;
        v22 = (int)a2 + v13 + 307;
        v14 = v11 - *(unsigned __int8 *)v22;
        v15 = &a2[2 * v14 - 1];
        v16 = &i[3 * *(unsigned __int8 *)v22];
        v16[1] = a2[2 * v14];
        v15[1] = v16;
        *v16 = -1;
        v16[2] = v14;
        ++*v15;
        v13 = v21;
      }
      v17 = *(unsigned __int8 *)v22;
      v18 = &a2[2 * v13 + 1];
      i[1] = a2[2 * v13 + 2];
      v18[1] = i;
      *i = -1;
      i[2] = v17;
      ++*v18;
    }
  }
  a2[119] = 0x2000;
}
