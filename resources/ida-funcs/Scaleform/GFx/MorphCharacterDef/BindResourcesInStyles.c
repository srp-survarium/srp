Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__thiscall Scaleform::GFx::MorphCharacterDef::BindResourcesInStyles(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        int resourceBinding)
{
  Scaleform::GFx::Resource *v4; // edi
  Scaleform::GFx::ShapeDataBase *v5; // eax
  int v6; // ebp
  Scaleform::GFx::Resource *v7; // ebx
  Scaleform::Render::ShapeMeshProvider *v8; // eax
  Scaleform::Render::ShapeMeshProvider *v9; // eax

  v4 = (Scaleform::GFx::Resource *)this->pShape1.pObject->Clone(this->pShape1.pObject);
  v5 = this->pShape2.pObject->Clone(this->pShape2.pObject);
  v6 = resourceBinding;
  v7 = (Scaleform::GFx::Resource *)v5;
  v4->__vftable[4].GetKey(v4, (Scaleform::GFx::ResourceKey *)resourceBinding);
  v7->__vftable[4].GetKey(v7, (Scaleform::GFx::ResourceKey *)v6);
  resourceBinding = 2;
  v8 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 96,
                                                 &resourceBinding);
  if ( v8 )
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v8, v4, v7);
  else
    v9 = 0;
  result->pObject = v9;
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return result;
}
