void __thiscall Scaleform::Render::ShapeMeshProvider::AttachShape(
        Scaleform::Render::ShapeMeshProvider *this,
        int shape,
        Scaleform::GFx::Resource *shapeMorph)
{
  Scaleform::Render::ShapeDataInterface *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::Resource *v6; // edi
  Scaleform::Render::MorphShapeData *v7; // eax
  Scaleform::Render::MorphShapeData *v8; // eax
  Scaleform::Render::MorphShapeData *v9; // edi
  Scaleform::RefCountVImpl *v10; // ecx

  v3 = (Scaleform::Render::ShapeDataInterface *)shape;
  if ( shape )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)shape);
  pObject = (Scaleform::RefCountVImpl *)this->pShapeData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pShapeData.pObject = v3;
  v6 = shapeMorph;
  if ( shapeMorph )
  {
    shape = 2;
    v7 = (Scaleform::Render::MorphShapeData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                156,
                                                &shape);
    if ( v7 )
    {
      Scaleform::Render::MorphShapeData::MorphShapeData(v7, v6);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    v10 = (Scaleform::RefCountVImpl *)this->pMorphData.pObject;
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    this->pMorphData.pObject = v9;
    Scaleform::Render::ShapeMeshProvider::createMorphData(this);
  }
  Scaleform::Render::ShapeMeshProvider::acquireShapeData(this);
}
