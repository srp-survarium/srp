char __thiscall Scaleform::SysAllocMapper::reserveSegment(Scaleform::SysAllocMapper *this, unsigned int *size)
{
  unsigned int PageSize; // ebp
  unsigned int SegmSize; // edi
  unsigned int v5; // ecx
  int v6; // eax
  unsigned __int8 *v7; // ebp
  unsigned int Granularity; // ecx
  unsigned int v10; // ebx
  unsigned int *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebx
  unsigned int NumSegments; // eax
  Scaleform::SysAllocMapper::Segment *v15; // esi
  unsigned int *bitSet; // [esp+1Ch] [ebp+4h]

  if ( this->NumSegments >= 0x20 )
    return 0;
  PageSize = this->PageSize;
  SegmSize = this->SegmSize;
  v5 = this->PageShift + 3;
  v6 = ~(PageSize - 1);
  if ( this->SegmSize - (v6 & (((SegmSize + 8 * PageSize - 1) >> v5) + PageSize - 1)) < (unsigned int)size )
  {
    SegmSize = this->Granularity
             * (((unsigned int)size
               + this->Granularity
               + (v6 & ((((unsigned int)&size[2 * PageSize - 1] + 3) >> v5) + PageSize - 1))
               - 1)
              / this->Granularity);
    v6 = ~(PageSize - 1);
  }
  if ( SegmSize - (v6 & (((SegmSize + 8 * PageSize - 1) >> v5) + PageSize - 1)) < (unsigned int)size )
  {
    do
      SegmSize += this->Granularity;
    while ( SegmSize
          - (~(PageSize - 1) & (PageSize + ((SegmSize + 8 * PageSize - 1) >> (LOBYTE(this->PageShift) + 3)) - 1)) < (unsigned int)size );
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
       - (~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1)) < (unsigned int)size )
    {
      return 0;
    }
  }
  v10 = (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1) & ~(this->PageSize - 1);
  v11 = (unsigned int *)this->pMapper->MapPages(this->pMapper, &v7[SegmSize - v10], v10);
  bitSet = v11;
  if ( v11 )
  {
    memset((int)v11, 0, 4 * (v10 >> 2));
    v12 = (SegmSize
         - (~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (this->PageShift + 3)) + this->PageSize - 1))) >> this->PageShift;
    bitSet[v12 >> 5] |= 1 << (v12 & 0x1F);
    v13 = Scaleform::SysAllocMapper::binarySearch(this, v7);
    NumSegments = this->NumSegments;
    if ( v13 < NumSegments )
      memmove(
        (unsigned __int8 *)&this->Segments[v13 + 1],
        (unsigned __int8 *)&this->Segments[v13],
        12 * (NumSegments - v13));
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
