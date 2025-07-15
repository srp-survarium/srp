int __cdecl sub_648FA0(_DWORD *a1)
{
  int result; // eax
  _DWORD *v2; // [esp+0h] [ebp-Ch]
  _DWORD *v3; // [esp+4h] [ebp-8h]
  _DWORD *i; // [esp+8h] [ebp-4h]
  _DWORD *j; // [esp+8h] [ebp-4h]

  for ( i = (_DWORD *)*a1; i; i = v3 )
  {
    v3 = (_DWORD *)*i;
    (*(void (__cdecl **)(_DWORD *))(a1[5] + 8))(i);
  }
  result = (int)a1;
  for ( j = (_DWORD *)a1[1]; j; j = v2 )
  {
    v2 = (_DWORD *)*j;
    result = (*(int (__cdecl **)(_DWORD *))(a1[5] + 8))(j);
  }
  return result;
}
