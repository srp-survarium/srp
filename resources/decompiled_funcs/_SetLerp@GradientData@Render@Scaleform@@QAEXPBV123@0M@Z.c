void __thiscall Scaleform::Render::GradientData::SetLerp(
        Scaleform::Render::GradientData *this,
        const Scaleform::Render::GradientData *data1,
        const Scaleform::Render::GradientData *data2,
        float morphRatio)
{
  const Scaleform::Render::GradientData *v4; // ebp
  unsigned __int16 i; // di
  int v7; // esi
  Scaleform::Render::GradientRecord *v8; // eax
  Scaleform::Render::GradientRecord *v9; // ecx
  Scaleform::Render::GradientRecord result; // [esp+14h] [ebp-8h] BYREF

  v4 = data1;
  this->Type = data1->Type;
  Scaleform::Render::GradientData::SetRecordCount(this, data1->RecordCount, 1);
  for ( i = 0; i < this->RecordCount; v9->ColorV.Raw = v8->ColorV.Raw )
  {
    v7 = i;
    v8 = Scaleform::Render::GradientRecord::LerpTo(&v4->pRecords[v7], &result, &data2->pRecords[v7], morphRatio);
    v9 = &this->pRecords[v7];
    v9->Ratio = v8->Ratio;
    v4 = data1;
    ++i;
  }
  this->FocalRatio = (data2->FocalRatio - v4->FocalRatio) * morphRatio + v4->FocalRatio;
}
