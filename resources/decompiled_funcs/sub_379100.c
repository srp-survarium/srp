int __usercall sub_379100@<eax>(int a1@<esi>)
{
  int v1; // ebp
  int v2; // edi
  int v3; // eax
  int result; // eax
  int v5; // ebx
  _DWORD *v6; // ebp
  int v7; // edi
  int v8; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 284);
  v2 = *(_DWORD *)(a1 + 404);
  v11 = v2;
  v3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 8 * *(_DWORD *)(a1 + 36));
  *(_DWORD *)(v2 + 56) = v3;
  *(_DWORD *)(v2 + 60) = v3 + 4 * *(_DWORD *)(a1 + 36);
  result = *(_DWORD *)(a1 + 196);
  v5 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v9 = v1 + 4;
    v6 = (_DWORD *)(result + 12);
    do
    {
      v7 = *v6 * v6[7] / *(_DWORD *)(a1 + 284) * v9;
      v10 = *v6 * v6[7] / *(_DWORD *)(a1 + 284);
      v8 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 8 * v7) + 4 * v10;
      *(_DWORD *)(*(_DWORD *)(v11 + 56) + 4 * v5) = v8;
      result = v8 + 4 * v7;
      *(_DWORD *)(*(_DWORD *)(v11 + 60) + 4 * v5++) = result;
      v6 += 22;
    }
    while ( v5 < *(_DWORD *)(a1 + 36) );
  }
  return result;
}
