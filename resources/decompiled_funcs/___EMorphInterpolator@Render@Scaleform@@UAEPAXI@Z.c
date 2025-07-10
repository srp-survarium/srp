Scaleform::Render::MorphInterpolator *__thiscall Scaleform::Render::MorphInterpolator::`vector deleting destructor'(
        Scaleform::Render::MorphInterpolator *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pMorphData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pShapeData.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
