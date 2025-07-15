int __cdecl pcre_compile(unsigned __int8 *buf, int a2, int a3, int a4, int a5)
{
  return pcre_compile2(buf, a2, 0, a3, a4, a5);
}
