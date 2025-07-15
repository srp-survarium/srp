void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (__thiscall *pDtor)(void *))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    ((void (*)(void))pDtor)();
  }
}
