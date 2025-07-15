void __stdcall __ArrayUnwind(char *ptr, unsigned int size, int count, void (*pDtor)(void))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor();
  }
}
