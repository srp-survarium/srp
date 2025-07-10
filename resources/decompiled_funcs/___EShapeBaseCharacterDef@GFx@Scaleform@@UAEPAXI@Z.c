Scaleform::GFx::ShapeBaseCharacterDef *__thiscall Scaleform::GFx::ShapeBaseCharacterDef::`vector deleting destructor'(
        Scaleform::GFx::ShapeBaseCharacterDef *this,
        char a2)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax

  this->__vftable = (Scaleform::GFx::ShapeBaseCharacterDef_vtbl *)&Scaleform::GFx::ShapeBaseCharacterDef::`vftable';
  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->__vftable = (Scaleform::GFx::ShapeBaseCharacterDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
