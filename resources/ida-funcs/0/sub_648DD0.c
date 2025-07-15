int __cdecl sub_648DD0(_DWORD *a1)
{
  unsigned int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < a1[2]; ++i )
    (*(void (__cdecl **)(_DWORD))(a1[4] + 8))(*(_DWORD *)(*a1 + 4 * i));
  return (*(int (__cdecl **)(_DWORD))(a1[4] + 8))(*a1);
}
