unsigned __int8 *__cdecl SpeedTree::CCore::LockTmpHeapBlock(unsigned int a1, char *a2, int *a3)
{
  int j; // [esp+24Ch] [ebp-Ch]
  int i; // [esp+250h] [ebp-8h]
  unsigned __int8 *v6; // [esp+254h] [ebp-4h]

  v6 = 0;
  EnterCriticalSection(&CriticalSection);
  for ( i = 0; i < 16; ++i )
  {
    if ( !byte_A9B250[276 * i] && dword_A9B144[69 * i] >= a1 )
    {
      *a3 = i;
      v6 = SpeedTree::CSharedHeapBlock::Lock((SpeedTree::CSharedHeapBlock *)((char *)&unk_A9B140 + 276 * i), a1, a2);
      break;
    }
  }
  if ( !v6 )
  {
    for ( j = 0; j < 16; ++j )
    {
      if ( !byte_A9B250[276 * j] )
      {
        *a3 = j;
        v6 = SpeedTree::CSharedHeapBlock::Lock((SpeedTree::CSharedHeapBlock *)((char *)&unk_A9B140 + 276 * j), a1, a2);
        break;
      }
    }
  }
  LeaveCriticalSection(&CriticalSection);
  return v6;
}
