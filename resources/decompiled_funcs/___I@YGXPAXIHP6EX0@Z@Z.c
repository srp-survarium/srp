void __stdcall `vector destructor iterator'(char *__t, unsigned int __s, int __n, void (__thiscall *__f)(void *))
{
  char *v4; // esi
  int i; // edi

  v4 = &__t[__n * __s];
  for ( i = __n - 1; i >= 0; --i )
  {
    v4 -= __s;
    __f(v4);
  }
}
