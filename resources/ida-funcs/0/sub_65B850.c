int __cdecl sub_65B850(int a1, unsigned __int8 **a2, unsigned __int8 *a3, int *a4, int a5)
{
  int result; // eax
  __int16 v6; // [esp+0h] [ebp-8h]

  for ( result = a1; *a2 != a3; *a4 = result )
  {
    result = (int)a4;
    if ( *a4 == a5 )
      break;
    v6 = *(_WORD *)(a1 + 2 * **a2 + 376);
    if ( v6 )
    {
      ++*a2;
    }
    else
    {
      v6 = (*(int (__cdecl **)(_DWORD, unsigned __int8 *))(a1 + 368))(*(_DWORD *)(a1 + 372), *a2);
      *a2 = &(*a2)[*(unsigned __int8 *)(a1 + **a2 + 76) - 3];
    }
    *(_WORD *)*a4 = v6;
    result = *a4 + 2;
  }
  return result;
}
