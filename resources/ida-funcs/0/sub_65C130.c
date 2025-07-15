int __cdecl sub_65C130(int a1, char a2, int a3)
{
  char v4; // [esp+3h] [ebp-5h] BYREF
  char *v5; // [esp+4h] [ebp-4h] BYREF

  v5 = &v4;
  (*(void (__cdecl **)(int, char *, int, char **, char **))(a1 + 60))(a1, &a2, a3, &v5, &v5);
  if ( v5 == &v4 )
    return -1;
  else
    return v4;
}
