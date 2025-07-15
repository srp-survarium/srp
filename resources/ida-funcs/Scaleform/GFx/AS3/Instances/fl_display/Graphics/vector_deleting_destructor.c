Scaleform::GFx::AS3::Instances::fl_display::Graphics *__thiscall Scaleform::GFx::AS3::Instances::fl_display::Graphics::`vector deleting destructor'(
        Scaleform::GFx::AS3::Instances::fl_display::Graphics *this,
        char a2)
{
  Scaleform::GFx::DrawingContext *pObject; // ecx

  pObject = this->pDrawing.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::AS3::Instance::~Instance(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
