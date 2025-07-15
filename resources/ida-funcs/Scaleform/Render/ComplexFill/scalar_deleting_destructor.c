Scaleform::Render::ComplexFill *__thiscall Scaleform::Render::ComplexFill::`scalar deleting destructor'(
        Scaleform::Render::ComplexFill *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::Image *v4; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pGradient.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = this->pImage.pObject;
  if ( v4 )
    v4->Release(v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
