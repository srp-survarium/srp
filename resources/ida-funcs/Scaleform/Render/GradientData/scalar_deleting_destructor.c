Scaleform::Render::GradientData *__thiscall Scaleform::Render::GradientData::`scalar deleting destructor'(
        Scaleform::Render::GradientData *this,
        char a2)
{
  Scaleform::Render::GradientRecord *pRecords; // eax

  pRecords = this->pRecords;
  this->__vftable = (Scaleform::Render::GradientData_vtbl *)&Scaleform::Render::GradientData::`vftable';
  if ( pRecords )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pRecords);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
