Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::AS2::GenericDisplayObj::CreateRenderNode(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // esi
  Scaleform::GFx::MovieDefImpl *v4; // eax

  pObject = this->pDef.pObject;
  v4 = (Scaleform::GFx::MovieDefImpl *)((int (*)(void))this->GetResourceMovieDef)();
  Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(
    pObject,
    result,
    (Scaleform::Render::ShapeMeshProvider *)context,
    v4);
  return result;
}
