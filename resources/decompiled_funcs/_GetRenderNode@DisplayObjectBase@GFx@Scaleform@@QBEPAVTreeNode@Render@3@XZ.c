Scaleform::Render::TreeNode *__thiscall Scaleform::GFx::DisplayObjectBase::GetRenderNode(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v2; // edi
  Scaleform::Render::TreeNode *pObject; // ecx
  Scaleform::Render::ContextImpl::Entry *v5; // eax
  Scaleform::Render::ContextImpl::Entry *v7; // [esp+8h] [ebp-4h] BYREF

  if ( !this->pRenNode.pObject )
  {
    v2 = this->CreateRenderNode(this, &v7, &this->pASRoot->pMovieImpl->RenderContext);
    if ( v2->pObject )
      ++v2->pObject->RefCount;
    pObject = this->pRenNode.pObject;
    if ( pObject )
    {
      if ( pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    this->pRenNode = (Scaleform::Ptr<Scaleform::Render::TreeNode>)v2->pObject;
    v5 = v7;
    if ( v7 )
    {
      --v7->RefCount;
      if ( !v5->RefCount )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
    }
    Scaleform::Render::TreeNode::SetVisible(this->pRenNode.pObject, (this->Flags & 0x4000) != 0);
  }
  return this->pRenNode.pObject;
}
