void __cdecl jinit_inverse_dct(int a1)
{
  int (__cdecl **v1)(int *); // eax
  int v2; // edi
  int *v3; // ebp
  _DWORD *v4; // ebx
  int v5; // eax

  v1 = (int (__cdecl **)(int *))(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 84);
  *(_DWORD *)(a1 + 428) = v1;
  *v1 = sub_3797B0;
  v2 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v3 = (int *)(*(_DWORD *)(a1 + 196) + 84);
    v4 = v1 + 11;
    do
    {
      v5 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 256);
      *v3 = v5;
      memset(v5, 0, 0x100u);
      *v4 = -1;
      ++v2;
      ++v4;
      v3 += 22;
    }
    while ( v2 < *(_DWORD *)(a1 + 36) );
  }
}
