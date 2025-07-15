int __cdecl sub_486130(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int result; // eax
  unsigned int v6; // ebp

  v4 = a1[101];
  if ( !*(_BYTE *)(v4 + 48) )
  {
    result = (*(int (__cdecl **)(_DWORD *, int))(a1[102] + 12))(a1, v4 + 8);
    if ( !result )
      return result;
    *(_BYTE *)(v4 + 48) = 1;
  }
  v6 = a1[71];
  result = (*(int (__cdecl **)(_DWORD *, int, int, unsigned int, int, int, int))(a1[103] + 4))(
             a1,
             v4 + 8,
             v4 + 52,
             v6,
             a2,
             a3,
             a4);
  if ( *(_DWORD *)(v4 + 52) >= v6 )
  {
    *(_BYTE *)(v4 + 48) = 0;
    *(_DWORD *)(v4 + 52) = 0;
  }
  return result;
}
