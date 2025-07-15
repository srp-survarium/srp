int __cdecl sub_373040(int a1)
{
  _iobuf *v1; // eax
  char v3[200]; // [esp+0h] [ebp-CCh] BYREF

  (*(void (__cdecl **)(int, char *))(*(_DWORD *)a1 + 12))(a1, v3);
  v1 = __iob_func();
  return fprintf(v1 + 2, "%s\n", v3);
}
