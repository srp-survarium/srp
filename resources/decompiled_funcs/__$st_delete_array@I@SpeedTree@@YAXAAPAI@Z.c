void __cdecl SpeedTree::st_delete_array<unsigned int>(void ***pRawBlock)
{
  void **v1; // eax

  if ( *pRawBlock )
  {
    v1 = *pRawBlock - 1;
    if ( *pRawBlock != (void **)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - 4 * (_DWORD)*v1;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v1);
      *pRawBlock = 0;
    }
  }
}
