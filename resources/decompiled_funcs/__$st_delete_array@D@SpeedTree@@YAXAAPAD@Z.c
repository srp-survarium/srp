void __cdecl SpeedTree::st_delete_array<char>(char **pRawBlock)
{
  char *v1; // eax

  if ( *pRawBlock )
  {
    v1 = *pRawBlock - 4;
    if ( *pRawBlock != (char *)4 )
    {
      SpeedTree::g_siHeapMemoryUsed += -4 - *(_DWORD *)v1;
      if ( SpeedTree::g_pAllocator )
        SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, v1);
      *pRawBlock = 0;
    }
  }
}
