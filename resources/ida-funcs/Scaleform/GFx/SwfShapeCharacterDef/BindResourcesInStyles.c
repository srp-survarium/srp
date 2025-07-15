Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__thiscall Scaleform::GFx::SwfShapeCharacterDef::BindResourcesInStyles(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        int resourceBinding)
{
  Scaleform::GFx::Resource *v4; // esi
  Scaleform::Render::ShapeMeshProvider *v5; // eax
  Scaleform::Render::ShapeMeshProvider *v6; // eax

  v4 = (Scaleform::GFx::Resource *)this->pShape.pObject->Clone(this->pShape.pObject);
  v4->__vftable[4].GetKey(v4, (Scaleform::GFx::ResourceKey *)resourceBinding);
  resourceBinding = 2;
  v5 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 96,
                                                 &resourceBinding);
  if ( v5 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v5, v4, 0);
    result->pObject = v6;
  }
  else
  {
    result->pObject = 0;
  }
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return result;
}
