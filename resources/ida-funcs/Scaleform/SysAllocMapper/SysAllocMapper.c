void __thiscall Scaleform::SysAllocMapper::SysAllocMapper(
        Scaleform::SysAllocMapper *this,
        Scaleform::SysMemMapper *mapper,
        unsigned int segSize,
        unsigned int granularity,
        bool bestFit)
{
  unsigned int v6; // eax
  unsigned int v7; // edi
  unsigned __int8 v8; // al
  unsigned int v9; // edx

  this->SegmSize = segSize;
  v6 = granularity;
  this->__vftable = (Scaleform::SysAllocMapper_vtbl *)&Scaleform::SysAllocMapper::`vftable';
  this->pMapper = mapper;
  this->PageSize = 0;
  if ( !granularity )
    v6 = 1;
  this->BestFit = bestFit;
  this->Granularity = v6;
  this->Footprint = 0;
  this->NumSegments = 0;
  this->LastSegment = -1;
  this->LastUsed = 0;
  v7 = mapper->GetPageSize(mapper);
  this->PageSize = v7;
  v8 = Scaleform::Alg::UpperBit(v7);
  v9 = ~(v7 - 1) & (v7 + this->Granularity - 1);
  this->PageShift = v8;
  this->Footprint = 0;
  this->NumSegments = 0;
  this->Granularity = v9;
  this->LastSegment = -1;
}
