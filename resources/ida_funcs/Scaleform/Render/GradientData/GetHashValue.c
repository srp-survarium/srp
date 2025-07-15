unsigned int __thiscall Scaleform::Render::GradientData::GetHashValue(
        Scaleform::Render::GradientData *this,
        float morphRatio)
{
  unsigned int result; // eax
  int RecordCount; // edi
  Scaleform::Render::GradientRecord *pRecords; // edx

  result = this->Type;
  RecordCount = this->RecordCount;
  if ( this->RecordCount )
  {
    pRecords = this->pRecords;
    do
    {
      result ^= pRecords->ColorV.Raw ^ pRecords->Ratio ^ HIWORD(pRecords->ColorV.Raw);
      ++pRecords;
      --RecordCount;
    }
    while ( RecordCount );
  }
  if ( this->pMorphTo )
    result ^= LOWORD(morphRatio) ^ HIWORD(LODWORD(morphRatio));
  return result;
}
