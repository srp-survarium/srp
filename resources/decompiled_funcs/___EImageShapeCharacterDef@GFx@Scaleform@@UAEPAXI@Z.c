Scaleform::GFx::ImageShapeCharacterDef *__thiscall Scaleform::GFx::ImageShapeCharacterDef::`vector deleting destructor'(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ShapeMeshProvider *v4; // eax

  pObject = (Scaleform::RefCountVImpl *)this->pShape.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::ImageShapeCharacterDef_vtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable';
  v4 = this->pShapeMeshProvider.pObject;
  if ( v4 )
    v4->Release(&v4->Scaleform::Render::MeshProvider);
  this->__vftable = (Scaleform::GFx::ImageShapeCharacterDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
