void __stdcall `eh vector constructor iterator'(
        char *ptr,
        unsigned int size,
        int count,
        void (__thiscall *pCtor)(void *),
        void (__thiscall *pDtor)(void *))
{
  int i; // [esp+14h] [ebp-1Ch]

  for ( i = 0; i < count; ++i )
  {
    pCtor(ptr);
    ptr += size;
  }
}
