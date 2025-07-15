int __cdecl OPENSSL_indirect_call(
        int (__cdecl *a1)(int, int, int, int, int, int, int),
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  return a1(a2, a3, a4, a5, a6, a7, a8);
}
