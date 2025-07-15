Scaleform::Render::ShapeDataFloatMP *__thiscall Scaleform::Render::ShapeDataFloatMP::`scalar deleting destructor'(
        Scaleform::Render::ShapeDataFloatMP *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::ShapeMeshProvider::~ShapeMeshProvider(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
