void __thiscall Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::GFx::Resource *shp)
{
  Scaleform::Render::ShapeMeshProvider *v3; // eax
  Scaleform::Render::ShapeMeshProvider *v4; // eax
  Scaleform::Render::ShapeMeshProvider *v5; // edi
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  int v7; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::SwfShapeCharacterDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->Id.Id = 0x40000;
  this->pShapeMeshProvider.pObject = 0;
  this->__vftable = (Scaleform::GFx::SwfShapeCharacterDef_vtbl *)&Scaleform::GFx::SwfShapeCharacterDef::`vftable';
  if ( shp )
    Scaleform::RefCountImpl::AddRef(shp);
  this->pShape.pObject = (Scaleform::GFx::ShapeDataBase *)shp;
  v7 = 2;
  v3 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 96,
                                                 &v7);
  if ( v3 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v3, (Scaleform::GFx::Resource *)this->pShape.pObject, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    pObject->Release(&pObject->Scaleform::Render::MeshProvider);
  this->pShapeMeshProvider.pObject = v5;
}
