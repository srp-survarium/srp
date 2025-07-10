void __cdecl SpeedTree::st_delete_array<float>(_DWORD *a1)
{
  unsigned int i; // [esp+0h] [ebp-Ch]
  unsigned int *pointer; // [esp+8h] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 4 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          ;
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}
