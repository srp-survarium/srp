void __thiscall Scaleform::GFx::DisplayObjectBase::SetVisible(Scaleform::GFx::DisplayObjectBase *this, bool visible)
{
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::Render::TreeNode *RenderNode; // eax

  if ( visible )
  {
    this->Flags |= 0x4000u;
    pObject = this->pRenNode.pObject;
    if ( pObject )
      Scaleform::Render::TreeNode::SetVisible(pObject, visible);
  }
  else
  {
    this->Flags &= ~0x4000u;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetVisible(RenderNode, 0);
  }
}
