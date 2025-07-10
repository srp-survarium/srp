char __thiscall Scaleform::Render::GradientData::operator==(
        Scaleform::Render::GradientData *this,
        const Scaleform::Render::GradientData *other)
{
  unsigned __int16 RecordCount; // di
  unsigned int v3; // esi
  Scaleform::Render::GradientRecord *pRecords; // edx
  Scaleform::Render::GradientRecord *v5; // eax
  unsigned int *p_Raw; // ecx
  int v7; // ebp

  RecordCount = this->RecordCount;
  if ( RecordCount != other->RecordCount
    || this->Type != other->Type
    || other->FocalRatio != this->FocalRatio
    || this->LinearRGB != other->LinearRGB )
  {
    return 0;
  }
  v3 = 0;
  if ( !RecordCount )
    return 1;
  pRecords = other->pRecords;
  v5 = this->pRecords;
  p_Raw = &pRecords->ColorV.Raw;
  v7 = (char *)pRecords - (char *)v5;
  while ( v5->Ratio == *(&v5->Ratio + v7) && v5->ColorV.Raw == *p_Raw )
  {
    ++v3;
    p_Raw += 2;
    ++v5;
    if ( v3 >= RecordCount )
      return 1;
  }
  return 0;
}
