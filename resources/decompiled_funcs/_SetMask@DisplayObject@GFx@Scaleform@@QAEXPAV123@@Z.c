void __thiscall Scaleform::GFx::DisplayObject::SetMask(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::DisplayObject *pmaskSprite)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v4; // ebp
  Scaleform::GFx::DisplayObject *v5; // ebx
  Scaleform::GFx::DisplayObject *pMaskCharacter; // esi
  Scaleform::GFx::DisplayObject *v7; // ecx
  Scaleform::GFx::DisplayObject *v8; // ecx
  Scaleform::Render::TreeNode *pObject; // esi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v10; // eax
  Scaleform::Render::ContextImpl::Entry *v11; // eax
  bool v12; // zf

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  Scaleform::GFx::DisplayObject::ResetClipDepth(this);
  v5 = pmaskSprite;
  if ( pmaskSprite )
  {
    if ( this->pScrollRect )
      Scaleform::GFx::DisplayObject::SetScrollRect(this, 0);
    Scaleform::GFx::DisplayObject::ResetClipDepth(v5);
  }
  if ( this->pMaskCharacter )
  {
    if ( !this->IsUsedAsMask(this) )
    {
      pMaskCharacter = this->pMaskCharacter;
      if ( pMaskCharacter )
      {
        if ( pMaskCharacter->pMaskCharacter
          && !pMaskCharacter->IsUsedAsMask(this->pMaskCharacter)
          && pMaskCharacter->pMaskCharacter )
        {
          Scaleform::GFx::DisplayObject::SetMask(pMaskCharacter, 0);
        }
        pMaskCharacter->Flags &= ~4u;
        pMaskCharacter->pMaskCharacter = 0;
        Scaleform::Render::TreeNode::SetMaskNode(v4, 0);
        Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(pMaskCharacter);
      }
    }
    if ( this->pMaskCharacter )
    {
      if ( this->IsUsedAsMask(this) )
      {
        v7 = this->pMaskCharacter;
        if ( v7 )
          Scaleform::GFx::DisplayObject::SetMask(v7, 0);
      }
    }
  }
  if ( v5 && v5->pMaskCharacter && v5->IsUsedAsMask(v5) && v5->pMaskCharacter )
  {
    if ( v5->IsUsedAsMask(v5) )
      v8 = v5->pMaskCharacter;
    else
      v8 = 0;
    Scaleform::GFx::DisplayObject::SetMask(v8, 0);
  }
  if ( this->pMaskCharacter && !this->IsUsedAsMask(this) )
    Scaleform::RefCountNTSImpl::Release(this->pMaskCharacter);
  pObject = 0;
  if ( v5 )
  {
    v10 = Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(
            v5,
            (Scaleform::Ptr<Scaleform::Render::TreeNode> *)&pmaskSprite,
            (int)v4);
    if ( v10->pObject )
      ++v10->pObject->RefCount;
    pObject = v10->pObject;
    v11 = (Scaleform::Render::ContextImpl::Entry *)pmaskSprite;
    if ( pmaskSprite )
    {
      --pmaskSprite->RefCount;
      if ( !v11->RefCount )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v11);
    }
  }
  Scaleform::Render::TreeNode::SetMaskNode(v4, pObject);
  this->Flags &= ~4u;
  if ( pObject )
  {
    this->pMaskCharacter = v5;
    if ( v5 )
    {
      ++v5->RefCount;
      Scaleform::GFx::DisplayObject::SetMaskOwner(v5, this);
    }
    v12 = pObject->RefCount-- == 1;
    if ( v12 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  else
  {
    this->pMaskCharacter = 0;
  }
  if ( v4 )
  {
    v12 = v4->RefCount-- == 1;
    if ( v12 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
}
