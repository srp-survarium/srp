char __thiscall Scaleform::Render::GradientData::SetRecordCount(
        Scaleform::Render::GradientData *this,
        unsigned __int16 count,
        bool tmpHeap)
{
  unsigned __int16 v3; // bx
  Scaleform::Render::GradientRecord *v6; // eax
  Scaleform::Render::GradientRecord *v7; // edi
  unsigned __int16 RecordCount; // ax
  unsigned int v9; // edx
  unsigned int v10; // esi
  Scaleform::Render::GradientRecord *pRecords; // eax
  int v12; // ecx
  unsigned int Raw; // eax

  v3 = count;
  if ( count == this->RecordCount )
    return 1;
  if ( tmpHeap )
    v6 = (Scaleform::Render::GradientRecord *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                8 * count,
                                                0);
  else
    v6 = (Scaleform::Render::GradientRecord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                8 * count,
                                                0);
  v7 = v6;
  if ( !v6 )
    return 0;
  if ( this->pRecords )
  {
    RecordCount = this->RecordCount;
    if ( count < RecordCount )
      RecordCount = count;
    v9 = RecordCount;
    v10 = 0;
    if ( RecordCount )
    {
      do
      {
        pRecords = this->pRecords;
        v12 = v10;
        v7[v12].Ratio = pRecords[v10].Ratio;
        Raw = pRecords[v10++].ColorV.Raw;
        v7[v12].ColorV.Raw = Raw;
      }
      while ( v10 < v9 );
      v3 = count;
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pRecords);
  }
  this->pRecords = v7;
  this->RecordCount = v3;
  return 1;
}
