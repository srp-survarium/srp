void __thiscall Scaleform::GFx::DrawTextImpl::SetVisible(Scaleform::GFx::DrawTextImpl *this, bool visible)
{
  Scaleform::Render::TreeNode::SetVisible(this->pTextNode.pObject, visible);
}
