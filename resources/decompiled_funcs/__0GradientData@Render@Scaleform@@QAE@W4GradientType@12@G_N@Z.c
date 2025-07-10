void __thiscall Scaleform::Render::GradientData::GradientData(
        Scaleform::Render::GradientData *this,
        Scaleform::Render::GradientType type,
        unsigned __int16 recordCount,
        bool linearRgb)
{
  this->FocalRatio = 0.0;
  this->LinearRGB = linearRgb;
  this->pRecords = 0;
  this->pMorphTo = 0;
  this->__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Type = type;
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
  this->RecordCount = 0;
  Scaleform::Render::GradientData::SetRecordCount(this, recordCount, 0);
}
