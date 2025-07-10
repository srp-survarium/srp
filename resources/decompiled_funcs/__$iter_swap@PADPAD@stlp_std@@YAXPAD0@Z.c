void __cdecl stlp_std::iter_swap<char *,char *>(char *__i1, char *__i2)
{
  char v2; // [esp+Bh] [ebp-9h]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}
