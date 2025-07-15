int __cdecl jinit_upsampler(int a1)
{
  int result; // eax
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // ebp
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  int v10; // ebp
  int v11; // edx
  int (__cdecl **v12)(int, int, int, int); // ebp
  int v13; // eax
  int v14; // [esp-8h] [ebp-20h]
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+10h] [ebp-8h]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]
  int v19; // [esp+1Ch] [ebp+4h]

  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 160);
  v3 = result;
  *(_DWORD *)(a1 + 432) = result;
  *(_DWORD *)result = sub_486DF0;
  *(_DWORD *)(result + 4) = sub_486E10;
  *(_BYTE *)(result + 8) = 0;
  v18 = result;
  if ( *(_BYTE *)(a1 + 266) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 26;
    result = (**(int (__cdecl ***)(int))a1)(a1);
  }
  v19 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v4 = *(_DWORD *)(a1 + 196) + 8;
    v5 = (_DWORD *)(v3 + 52);
    do
    {
      v6 = *(_DWORD *)v4 * *(_DWORD *)(v4 + 28) / *(_DWORD *)(a1 + 280);
      v7 = *(_DWORD *)(a1 + 276);
      v16 = v6;
      v15 = v7;
      v8 = *(_DWORD *)(v4 + 4) * *(_DWORD *)(v4 + 32) / *(_DWORD *)(a1 + 284);
      v9 = *(_DWORD *)(a1 + 272);
      v5[12] = v8;
      if ( *(_BYTE *)(v4 + 44) )
      {
        if ( v6 != v9 || v8 != v7 )
        {
          v10 = 2 * v6;
          if ( v10 == v9 )
          {
            if ( v8 == v7 )
            {
              *v5 = sub_486FE0;
LABEL_20:
              v14 = *(_DWORD *)(a1 + 276);
              v12 = (int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8);
              v13 = jround_up(*(_DWORD *)(a1 + 92), *(_DWORD *)(a1 + 272));
              *(v5 - 10) = (*v12)(a1, 1, v13, v14);
              goto LABEL_21;
            }
            if ( v10 == v9 && 2 * v8 == v7 )
            {
              *v5 = sub_487040;
              goto LABEL_20;
            }
          }
          v11 = v9 % v16;
          v17 = v9 / v16;
          if ( v11 || v15 % v8 )
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 39;
            (**(void (__cdecl ***)(int))a1)(a1);
          }
          else
          {
            *v5 = sub_486F00;
            *(_BYTE *)(v18 + v19 + 140) = v17;
            *(_BYTE *)(v18 + v19 + 150) = v15 / v8;
          }
          goto LABEL_20;
        }
        *v5 = sub_486EE0;
      }
      else
      {
        *v5 = sub_486EF0;
      }
LABEL_21:
      result = v19 + 1;
      ++v5;
      v4 += 88;
      ++v19;
    }
    while ( v19 < *(_DWORD *)(a1 + 36) );
  }
  return result;
}
