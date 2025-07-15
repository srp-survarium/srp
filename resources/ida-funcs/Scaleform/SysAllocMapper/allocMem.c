unsigned __int8 *__thiscall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int LastSegment; // eax
  unsigned __int8 *result; // eax
  unsigned int i; // edi

  LastSegment = this->LastSegment;
  if ( LastSegment != -1 )
  {
    result = Scaleform::SysAllocMapper::allocMem(this, LastSegment, size, alignment);
    if ( result )
      return result;
    this->LastUsed = 0;
  }
  for ( i = 0; i < this->NumSegments; ++i )
  {
    if ( i != this->LastSegment )
    {
      result = Scaleform::SysAllocMapper::allocMem(this, i, size, alignment);
      if ( result )
        return result;
      this->LastUsed = 0;
    }
  }
  return 0;
}


unsigned __int8 *__thiscall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned int pos,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int PageShift; // ebx
  Scaleform::SysAllocMapper::Segment *v6; // ecx
  unsigned int v7; // eax
  unsigned int PageSize; // esi
  unsigned int *v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ebx
  unsigned int v12; // eax
  int v13; // ecx
  unsigned int v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // edx
  int v18; // eax
  unsigned int v19; // eax
  int i; // edx
  unsigned int v21; // eax
  int v22; // eax
  unsigned int v23; // ebx
  unsigned __int8 *result; // eax
  unsigned int v25; // ecx
  unsigned int start; // [esp+10h] [ebp-20h]
  unsigned __int8 *Memory; // [esp+14h] [ebp-1Ch]
  unsigned int found; // [esp+18h] [ebp-18h]
  unsigned __int8 *ptr; // [esp+1Ch] [ebp-14h]
  unsigned int rest; // [esp+20h] [ebp-10h]
  unsigned int limit; // [esp+24h] [ebp-Ch]
  unsigned int pages; // [esp+28h] [ebp-8h]
  Scaleform::SysAllocMapper::Segment *seg; // [esp+2Ch] [ebp-4h]

  PageShift = this->PageShift;
  v6 = &this->Segments[pos];
  v7 = v6->Size;
  seg = v6;
  Memory = v6->Memory;
  PageSize = this->PageSize;
  v9 = (unsigned int *)&v6->Memory[v7
                                 - (~(PageSize - 1) & (((v7 + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1))];
  pages = size >> PageShift;
  v10 = (v7 - (~(PageSize - 1) & (((v7 + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1))) >> this->PageShift;
  v11 = 0;
  start = 0;
  limit = v10;
  rest = -1;
  found = -1;
  if ( !v10 )
    goto LABEL_31;
  while ( 1 )
  {
    v12 = v11 >> 5;
    v13 = v11 & 0x1F;
    if ( ((v9[v11 >> 5] >> v13) & 1) == 0 )
      break;
    v11 += Scaleform::HeapPT::BitSet1::FindUsedSize(v9, v11, limit);
    start = v11;
LABEL_27:
    if ( v11 >= limit )
      goto LABEL_28;
  }
  v14 = Scaleform::HeapPT::BitSet1::HeadFreeTable[v13];
  v15 = v14 | v9[v12];
  if ( v15 == v14 )
  {
    v19 = v12 + 1;
    for ( i = 32 - v13; !v9[v19]; i += 32 )
      ++v19;
    v21 = v9[v19];
    if ( (_WORD)v21 )
    {
      if ( (_BYTE)v21 )
        v22 = Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int8)v21];
      else
        v22 = Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE1(v21)] + 8;
    }
    else if ( ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & v21) != 0 )
    {
      v22 = Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(v21)] + 16;
    }
    else
    {
      v22 = Scaleform::HeapPT::BitSet1::LastFreeBlock[HIBYTE(v21)] + 24;
    }
    v17 = v22 + i;
  }
  else
  {
    v16 = v15 >> v13;
    if ( (_WORD)v16 )
    {
      if ( (_BYTE)v16 )
        v17 = Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int8)v16];
      else
        v17 = Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE1(v16)] + 8;
    }
    else
    {
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[5508664] & v16) != 0 )
        v18 = Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(v16)] + 16;
      else
        v18 = Scaleform::HeapPT::BitSet1::LastFreeBlock[HIBYTE(v16)] + 24;
      v17 = v18;
    }
  }
  if ( size + (~(alignment - 1) & (unsigned int)&Memory[start * PageSize - 1 + alignment]) > (unsigned int)&Memory[start * PageSize + v17 * PageSize]
    || v17 - pages >= rest
    || (found = start, rest = v17 - pages, this->BestFit) )
  {
    start += v17;
    v11 = start;
    goto LABEL_27;
  }
LABEL_28:
  if ( found == -1 )
  {
LABEL_31:
    result = 0;
    goto LABEL_32;
  }
  v23 = ((int)((~(alignment - 1) & (unsigned int)&Memory[found * PageSize - 1 + alignment])
             - found * PageSize
             - (_DWORD)Memory) >> this->PageShift)
      + found;
  result = (unsigned __int8 *)this->pMapper->MapPages(this->pMapper, &Memory[PageSize * v23], size);
  ptr = result;
  if ( !result )
  {
LABEL_32:
    v25 = -1;
    goto LABEL_33;
  }
  Scaleform::HeapPT::BitSet1::SetUsed(v9, v23, pages);
  seg->PageCount += pages;
  result = ptr;
  v25 = pos;
  this->Footprint += pages << this->PageShift;
LABEL_33:
  this->LastSegment = v25;
  this->LastUsed = &result[size];
  return result;
}
