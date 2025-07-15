char *__thiscall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned int size,
        unsigned int alignment)
{
  unsigned int LastSegment; // eax
  char *result; // eax
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


char *__thiscall Scaleform::SysAllocMapper::allocMem(
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
  char *result; // eax
  unsigned int v25; // ecx
  unsigned int v26; // [esp+10h] [ebp-20h]
  unsigned __int8 *Memory; // [esp+14h] [ebp-1Ch]
  int v28; // [esp+18h] [ebp-18h]
  char *v29; // [esp+1Ch] [ebp-14h]
  unsigned int v30; // [esp+20h] [ebp-10h]
  unsigned int v31; // [esp+24h] [ebp-Ch]
  unsigned int num; // [esp+28h] [ebp-8h]
  Scaleform::SysAllocMapper::Segment *v33; // [esp+2Ch] [ebp-4h]

  PageShift = this->PageShift;
  v6 = &this->Segments[pos];
  v7 = v6->Size;
  v33 = v6;
  Memory = v6->Memory;
  PageSize = this->PageSize;
  v9 = (unsigned int *)&v6->Memory[v7
                                 - (~(PageSize - 1) & (((v7 + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1))];
  num = size >> PageShift;
  v10 = (v7 - (~(PageSize - 1) & (((v7 + 8 * PageSize - 1) >> (PageShift + 3)) + PageSize - 1))) >> this->PageShift;
  v11 = 0;
  v26 = 0;
  v31 = v10;
  v30 = -1;
  v28 = -1;
  if ( !v10 )
    goto LABEL_31;
  while ( 1 )
  {
    v12 = v11 >> 5;
    v13 = v11 & 0x1F;
    if ( ((v9[v11 >> 5] >> v13) & 1) == 0 )
      break;
    v11 += Scaleform::HeapPT::BitSet1::FindUsedSize(v9, v11, v31);
    v26 = v11;
LABEL_27:
    if ( v11 >= v31 )
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
    else if ( (v21 & 0xFF0000) != 0 )
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
      if ( (v16 & 0xFF0000) != 0 )
        v18 = Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(v16)] + 16;
      else
        v18 = Scaleform::HeapPT::BitSet1::LastFreeBlock[HIBYTE(v16)] + 24;
      v17 = v18;
    }
  }
  if ( size + (~(alignment - 1) & (unsigned int)&Memory[v26 * PageSize - 1 + alignment]) > (unsigned int)&Memory[v26 * PageSize + v17 * PageSize]
    || v17 - num >= v30
    || (v28 = v26, v30 = v17 - num, this->BestFit) )
  {
    v26 += v17;
    v11 = v26;
    goto LABEL_27;
  }
LABEL_28:
  if ( v28 == -1 )
  {
LABEL_31:
    result = 0;
    goto LABEL_32;
  }
  v23 = ((int)((~(alignment - 1) & (unsigned int)&Memory[v28 * PageSize - 1 + alignment])
             - v28 * PageSize
             - (_DWORD)Memory) >> this->PageShift)
      + v28;
  result = (char *)this->pMapper->MapPages(this->pMapper, &Memory[PageSize * v23], size);
  v29 = result;
  if ( !result )
  {
LABEL_32:
    v25 = -1;
    goto LABEL_33;
  }
  Scaleform::HeapPT::BitSet1::SetUsed(v9, v23, num);
  v33->PageCount += num;
  result = v29;
  v25 = pos;
  this->Footprint += num << this->PageShift;
LABEL_33:
  this->LastSegment = v25;
  this->LastUsed = (unsigned __int8 *)&result[size];
  return result;
}
