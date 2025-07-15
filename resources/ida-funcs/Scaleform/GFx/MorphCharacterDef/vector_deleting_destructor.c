Scaleform::GFx::MorphCharacterDef *__thiscall Scaleform::GFx::MorphCharacterDef::`vector deleting destructor'(
        Scaleform::GFx::MorphCharacterDef *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::Render::ShapeMeshProvider *v5; // eax

  this->__vftable = (Scaleform::GFx::MorphCharacterDef_vtbl *)&Scaleform::GFx::MorphCharacterDef::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pShape2.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pShape1.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->__vftable = (Scaleform::GFx::MorphCharacterDef_vtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable';
  v5 = this->pShapeMeshProvider.pObject;
  if ( v5 )
    v5->Release(&v5->Scaleform::Render::MeshProvider);
  this->__vftable = (Scaleform::GFx::MorphCharacterDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
