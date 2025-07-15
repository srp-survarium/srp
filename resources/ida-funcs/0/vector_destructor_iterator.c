void __stdcall `vector destructor iterator'(char *__t, unsigned int __s, int __n, void (__thiscall *__f)(void *))
{
  char *i; // esi

  for ( i = &__t[__n * __s]; --__n >= 0; __f(i) )
    i -= __s;
}
