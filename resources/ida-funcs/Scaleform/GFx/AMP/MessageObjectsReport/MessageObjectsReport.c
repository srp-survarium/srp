void __thiscall Scaleform::GFx::AMP::MessageObjectsReport::MessageObjectsReport(
        Scaleform::GFx::AMP::MessageObjectsReport *this,
        const __m128i *objectsReport)
{
  const __m128i *v2; // eax

  v2 = objectsReport;
  this->__vftable = (Scaleform::GFx::AMP::MessageObjectsReport_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Version = 33;
  this->GFxVersion = 4;
  this->__vftable = (Scaleform::GFx::AMP::MessageObjectsReport_vtbl *)&Scaleform::GFx::AMP::MessageObjectsReport::`vftable';
  if ( !objectsReport )
    v2 = (const __m128i *)uri;
  Scaleform::StringLH::StringLH(&this->ObjectsReport, v2);
}
