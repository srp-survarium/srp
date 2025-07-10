void __thiscall Scaleform::SysAllocStatic::AddMemSegment(Scaleform::SysAllocStatic *this, void *mem, unsigned int size)
{
  unsigned int MinSize; // eax
  int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edx
  unsigned int NumSegments; // ecx
  Scaleform::HeapPT::TreeSeg *v9; // ecx
  unsigned int v10; // edx

  MinSize = this->MinSize;
  v5 = ~(MinSize - 1);
  v6 = v5 & ((unsigned int)mem + MinSize - 1);
  v7 = v5 & ((unsigned int)mem + size);
  NumSegments = this->NumSegments;
  if ( NumSegments < 4 )
  {
    v9 = (Scaleform::HeapPT::TreeSeg *)this->Segments[NumSegments];
    v10 = v7 - v6;
    v9->Buffer = (unsigned __int8 *)v6;
    v9->Size = v10;
    v9->UseCount = 0;
    this->TotalSpace += v10;
    Scaleform::HeapPT::AllocLite::InitSegment(this->pAllocator, v9);
    ++this->NumSegments;
  }
}
