void __stdcall `vector copy constructor iterator'(
        char *__t,
        char *__u,
        unsigned int __s,
        int __n,
        void *(__thiscall *__f)(void *, void *))
{
  int i; // ebp

  for ( i = __n - 1; i >= 0; --i )
  {
    __f(__t, __u);
    __t += __s;
    __u += __s;
  }
}
