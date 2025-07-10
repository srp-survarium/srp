Scaleform::HeapPT::BinLNode *__thiscall Scaleform::HeapPT::FreeBin::PullBest(
        Scaleform::HeapPT::FreeBin *this,
        unsigned int blocks,
        char shift,
        unsigned int alignMask)
{
  Scaleform::HeapPT::BinLNode *result; // eax
  unsigned int v7; // eax
  Scaleform::HeapPT::BinTNode *Best; // esi
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int ShortSize; // edx
  Scaleform::HeapPT::BinTNode *head; // [esp+18h] [ebp+4h]

  if ( blocks > 0x40 )
    goto LABEL_9;
  if ( blocks > 0x20 )
  {
    v7 = blocks - 33;
  }
  else
  {
    result = Scaleform::HeapPT::ListBin::PullBest(&this->ListBin1, blocks - 1, blocks, shift, alignMask);
    if ( result )
    {
      this->FreeBlocks -= result->ShortSize;
      return result;
    }
    v7 = 0;
  }
  result = Scaleform::HeapPT::ListBin::PullBest(&this->ListBin2, v7, blocks, shift, alignMask);
  if ( result )
  {
    this->FreeBlocks -= (unsigned int)result[1].pPrev;
  }
  else
  {
LABEL_9:
    Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, blocks);
    head = Best;
    if ( Best )
    {
      while ( 1 )
      {
        v9 = ~alignMask & ((unsigned int)Best + alignMask);
        v10 = v9 - (_DWORD)Best;
        if ( v9 != (_DWORD)Best )
        {
          do
          {
            if ( v10 >= 0x10 )
              break;
            v9 += alignMask + 1;
            v10 += alignMask + 1;
          }
          while ( v10 );
        }
        ShortSize = Best->ShortSize;
        if ( ShortSize >= 0x21 )
          ShortSize = Best->Size;
        if ( (blocks << shift) + v9 <= (unsigned int)Best + (ShortSize << shift) )
          break;
        Best = (Scaleform::HeapPT::BinTNode *)Best->pNext;
        if ( Best == head )
        {
          Best = Scaleform::HeapPT::TreeBin::FindBest(&this->TreeBin1, Best->Size + 1);
          head = Best;
          if ( !Best )
            return 0;
        }
      }
      Scaleform::HeapPT::TreeBin::PullNode(&this->TreeBin1, Best);
      this->FreeBlocks -= Best->Size;
      return Best;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
