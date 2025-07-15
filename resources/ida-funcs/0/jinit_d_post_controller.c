int (__cdecl **__cdecl jinit_d_post_controller(int a1, char a2))(int a1, int a2)
{
  int (__cdecl **result)(int, int); // eax
  int (__cdecl **v3)(int, int); // edi
  int v4; // eax
  int v5; // ebp
  int v6; // eax
  int v7; // [esp-8h] [ebp-10h]

  result = (int (__cdecl **)(int, int))(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  v3 = result;
  *(_DWORD *)(a1 + 412) = result;
  *result = sub_486C50;
  result[2] = 0;
  result[3] = 0;
  if ( *(_BYTE *)(a1 + 74) )
  {
    v4 = *(_DWORD *)(a1 + 276);
    v3[4] = (int (__cdecl *)(int, int))v4;
    if ( a2 )
    {
      v5 = *(_DWORD *)(a1 + 4);
      v7 = v4;
      v6 = jround_up(*(_DWORD *)(a1 + 96), v4);
      result = (int (__cdecl **)(int, int))(*(int (__cdecl **)(int, int, _DWORD, int, int, int))(v5 + 16))(
                                             a1,
                                             1,
                                             0,
                                             *(_DWORD *)(a1 + 92) * *(_DWORD *)(a1 + 100),
                                             v6,
                                             v7);
      v3[2] = (int (__cdecl *)(int, int))result;
    }
    else
    {
      result = (int (__cdecl **)(int, int))(*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(
                                             a1,
                                             1,
                                             *(_DWORD *)(a1 + 92) * *(_DWORD *)(a1 + 100),
                                             v4);
      v3[3] = (int (__cdecl *)(int, int))result;
    }
  }
  return result;
}
