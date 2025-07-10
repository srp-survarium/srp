void __cdecl operator delete(void *p)
{
  free(p);
}
