Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *__thiscall Scaleform::GFx::ShapeBaseCharacterDef::BindResourcesInStyles(
        Scaleform::GFx::ShapeBaseCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *result,
        const Scaleform::GFx::ResourceBinding *__formal)
{
  Scaleform::Render::ShapeMeshProvider *pObject; // eax
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v5; // eax

  pObject = this->pShapeMeshProvider.pObject;
  if ( pObject )
    pObject->AddRef(&pObject->Scaleform::Render::MeshProvider);
  v5 = result;
  result->pObject = (Scaleform::Render::ShapeMeshProvider *)this->pShapeMeshProvider;
  return v5;
}
