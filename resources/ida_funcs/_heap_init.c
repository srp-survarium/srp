int __cdecl _heap_init(int mtflag)
{
  int result; // eax

  result = (int)HeapCreate(mtflag == 0, 0x1000u, 0);
  _crtheap = (void *)result;
  if ( result )
  {
    result = 1;
    __active_heap = 1;
  }
  return result;
}
