void __stdcall `eh vector destructor iterator'(
        char *ptr,
        unsigned int size,
        int count,
        void (__thiscall *pDtor)(void *))
{
  char *ptra; // [esp+34h] [ebp+8h]

  for ( ptra = &ptr[count * size]; --count >= 0; pDtor(ptra) )
    ptra -= size;
}
