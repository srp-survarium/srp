char __thiscall Scaleform::SysAllocMapper::reserveSegment(Scaleform::SysAllocMapper *this, unsigned int size)
{
  unsigned int PageSize; // ebp
  unsigned int SegmSize; // edi
  unsigned int v5; // ecx
  int v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned int Granularity; // ecx
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebx
  unsigned int NumSegments; // eax
  Scaleform::SysAllocMapper::Segment *v15; // esi
  _DWORD *v16; // [esp+1Ch] [ebp+4h]

  if ( this->NumSegments >= 0x20 )
    return 0;
  PageSize = this->PageSize;
  SegmSize = this->SegmSize;
  v5 = this->PageShift + 3;
  v6 = ~(PageSize - 1);
  if ( this->SegmSize - (v6 & (((SegmSize + 8 * PageSize - 1) >> v5) + PageSize - 1)) < size )
  {
    SegmSize = this->Granularity
             * ((this->Granularity + (v6 & (((size + 8 * PageSize - 1) >> v5) + PageSize - 1)) + size - 1)
              / this->Granularity);
    v6 = ~(PageSize - 1);
  }
  if ( SegmSize - (v6 & (((SegmSize + 8 * PageSize - 1) >> v5) + PageSize - 1)) < size )
  {
    do
      SegmSize += this->Granularity;
    while ( SegmSize
          - (~(PageSize - 1) & (PageSize + ((SegmSize + 8 * PageSize - 1) >> (LOBYTE(this->PageShift) + 3)) - 1)) < size );
  }
  while ( 1 )
  {
    v7 = (unsigned __int8 *)this->pMapper->ReserveAddrSpace(this->pMapper, SegmSize);
    if ( v7 )
      break;
    Granularity = this->Granularity;
    SegmSize = Granularity * (((SegmSize >> 1) + Granularity - 1) / Granularity);
    if ( SegmSize < 2 * Granularity
      || SegmSize
       - (~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1)) < size )
    {
      return 0;
    }
  }
  v10 = (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1) & ~(this->PageSize - 1);
  v11 = this->pMapper->MapPages(this->pMapper, &v7[SegmSize - v10], v10);
  v16 = v11;
  if ( v11 )
  {
    memset((int)v11, 0, 4 * (v10 >> 2));
    v12 = (SegmSize
         - (~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1))) >> this->PageShift;
    v16[v12 >> 5] |= 1 << (v12 & 0x1F);
    v13 = Scaleform::SysAllocMapper::binarySearch(this, v7);
    NumSegments = this->NumSegments;
    if ( v13 < NumSegments )
      memmove((int)&this->Segments[v13 + 1], (const __m128i *)&this->Segments[v13], 12 * (NumSegments - v13));
    ++this->NumSegments;
    v15 = &this->Segments[v13];
    v15->Size = SegmSize;
    v15->Memory = v7;
    v15->PageCount = 0;
    return 1;
  }
  else
  {
    this->pMapper->ReleaseAddrSpace(this->pMapper, v7, SegmSize);
    return 0;
  }
}
