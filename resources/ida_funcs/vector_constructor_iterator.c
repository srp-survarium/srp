void __stdcall `vector constructor iterator'(char *__t, unsigned int __s, int __n, void *(__thiscall *__f)(void *))
{
  int i; // edi

  for ( i = __n - 1; i >= 0; --i )
  {
    __f(__t);
    __t += __s;
  }
}
