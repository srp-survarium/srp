Scaleform::GFx::AMP::MessageProfileFrame *__thiscall Scaleform::GFx::AMP::MessageProfileFrame::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageProfileFrame *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->FrameInfo.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::AMP::MessageProfileFrame_vtbl *)&Scaleform::GFx::AMP::Message::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
