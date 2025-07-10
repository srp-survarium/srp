void **__cdecl SpeedTree::st_delete<SpeedTree::CCore>(void **a1)
{
  void **result; // eax

  result = a1;
  if ( *a1 )
  {
    (**(void (__thiscall ***)(void *, _DWORD))*a1)(*a1, 0);
    if ( SpeedTree::g_pAllocator )
      SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, *a1);
    else
      free(*a1);
    result = a1;
    *a1 = 0;
    SpeedTree::g_siHeapMemoryUsed -= 3620;
  }
  return result;
}
