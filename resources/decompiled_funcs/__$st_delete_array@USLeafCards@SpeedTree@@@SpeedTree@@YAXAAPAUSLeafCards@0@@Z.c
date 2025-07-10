void __cdecl SpeedTree::st_delete_array<SpeedTree::SLeafCards>(int *a1)
{
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v2; // [esp+8h] [ebp-8h]
  unsigned int *pointer; // [esp+Ch] [ebp-4h]

  if ( *a1 )
  {
    pointer = (unsigned int *)(*a1 - 4);
    if ( *a1 != 4 )
    {
      v2 = *a1;
      if ( *a1 )
      {
        SpeedTree::g_siHeapMemoryUsed -= 60 * *pointer + 4;
        for ( i = 0; i < *pointer; ++i )
          SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)(v2 + 60 * i));
        if ( SpeedTree::g_pAllocator )
          SpeedTree::g_pAllocator->Free(SpeedTree::g_pAllocator, pointer);
        else
          free(pointer);
        *a1 = 0;
      }
    }
  }
}
