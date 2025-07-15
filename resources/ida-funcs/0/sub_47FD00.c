int __usercall sub_47FD00@<eax>(int a1@<edi>, int a2)
{
  _iobuf *v2; // eax
  char v4[200]; // [esp+0h] [ebp-CCh] BYREF

  (*(void (__cdecl **)(int, char *))(*(_DWORD *)a2 + 12))(a2, v4);
  v2 = __iob_func();
  return fprintf(a1, v2 + 2, "%s\n", v4);
}
