int __cdecl jinit_d_main_controller(int a1, char a2)
{
  int (__cdecl **v2)(int *, int); // ebx
  int result; // eax
  int v4; // ecx
  int v5; // ebp
  _DWORD *v6; // edi
  int *v7; // ebx
  int v8; // [esp+18h] [ebp+8h]

  v2 = (int (__cdecl **)(int *, int))(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 80);
  *(_DWORD *)(a1 + 404) = v2;
  *v2 = sub_486310;
  if ( a2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 3;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 432) + 8) )
  {
    if ( *(int *)(a1 + 284) < 2 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 48;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    result = sub_485DC0(a1);
    v4 = *(_DWORD *)(a1 + 284) + 2;
    v8 = v4;
  }
  else
  {
    result = *(_DWORD *)(a1 + 284);
    v8 = result;
    v4 = result;
  }
  v5 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v6 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 12);
    v7 = (int *)(v2 + 2);
    while ( 1 )
    {
      result = (*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(
                 a1,
                 1,
                 v6[4] * v6[6],
                 v4 * (*v6 * v6[7] / *(_DWORD *)(a1 + 284)));
      *v7 = result;
      ++v5;
      ++v7;
      v6 += 22;
      if ( v5 >= *(_DWORD *)(a1 + 36) )
        break;
      v4 = v8;
    }
  }
  return result;
}
