Scaleform::HeapPT::BinLNode *__thiscall Scaleform::HeapPT::ListBin::FindAligned(
        Scaleform::HeapPT::ListBin *this,
        Scaleform::HeapPT::BinLNode *root,
        unsigned int blocks,
        char shift,
        unsigned int alignMask)
{
  Scaleform::HeapPT::BinLNode *result; // eax
  unsigned int i; // esi
  Scaleform::HeapPT::BinLNode *v7; // edx
  unsigned int v8; // esi
  Scaleform::HeapPT::BinLNode *ShortSize; // esi

  result = root;
  if ( !root )
    return 0;
  for ( i = ~alignMask; ; i = ~alignMask )
  {
    v7 = (Scaleform::HeapPT::BinLNode *)(i & ((unsigned int)result + alignMask));
    v8 = (char *)v7 - (char *)result;
    if ( v7 != result )
    {
      do
      {
        if ( v8 >= 0x10 )
          break;
        v7 = (Scaleform::HeapPT::BinLNode *)((char *)v7 + alignMask + 1);
        v8 += alignMask + 1;
      }
      while ( v8 );
    }
    ShortSize = (Scaleform::HeapPT::BinLNode *)result->ShortSize;
    if ( (unsigned int)ShortSize >= 0x21 )
      ShortSize = result[1].pPrev;
    if ( (char *)v7 + (blocks << shift) <= (char *)result + ((_DWORD)ShortSize << shift) )
      break;
    result = result->pNext;
    if ( result == root )
      return 0;
  }
  return result;
}
