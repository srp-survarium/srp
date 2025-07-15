Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        int newParent)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v5; // esi
  Scaleform::Render::TreeNode *v6; // ebp
  Scaleform::Render::TreeNode *pParent; // eax
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::GFx::DisplayObjContainer *v9; // edi
  unsigned int DisplayIndex; // eax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v11; // eax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v12; // edi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v13; // edi
  bool v14; // zf
  Scaleform::Render::ContextImpl::Entry *pNext; // eax
  Scaleform::Render::TreeContainer *oldParentNode; // [esp+10h] [ebp-4h]

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v5 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  oldParentNode = (Scaleform::Render::TreeContainer *)RenderNode->pParent;
  v6 = oldParentNode;
  Scaleform::Render::TreeNode::SetOrigScale9Parent(RenderNode, oldParentNode);
  pParent = (Scaleform::Render::TreeNode *)newParent;
  if ( newParent )
  {
    while ( pParent != v5 )
    {
      pParent = (Scaleform::Render::TreeNode *)pParent->pParent;
      if ( !pParent )
        goto LABEL_6;
    }
    v13 = result;
    v14 = v5->RefCount-- == 1;
    result->pObject = 0;
  }
  else
  {
LABEL_6:
    v8 = this->pParent;
    v9 = 0;
    if ( v8 )
    {
      v9 = (v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0
         ? (Scaleform::GFx::DisplayObjContainer *)v8
         : 0;
      if ( v9 )
      {
        DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(&v9->mDisplayList, this);
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(&v9->mDisplayList, v9, DisplayIndex);
        v6 = oldParentNode;
      }
    }
    Scaleform::GFx::MovieImpl::AddIndirectTransformPair(this->pASRoot->pMovieImpl, v9, v6, this);
    if ( !this->pIndXFormData )
    {
      newParent = 322;
      v11 = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                              Scaleform::Memory::pGlobalHeap,
                                                                              this,
                                                                              64,
                                                                              &newParent);
      v12 = v11;
      if ( v11 )
      {
        memset((int)v11, 0, 0x30u);
        v12->OrigTransformMatrix.M[0][0] = 1.0;
        v12->OrigTransformMatrix.M[1][1] = 1.0;
        v12->OrigTransformMatrix.M[2][2] = 1.0;
      }
      else
      {
        v12 = 0;
      }
      this->pIndXFormData = v12;
    }
    memcpy(
      (unsigned __int8 *)this->pIndXFormData,
      (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x10)
                                    + 4 * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000)) / 28)
                                    + 20)
                        + 16),
      0x30u);
    v13 = result;
    this->pIndXFormData->IsOrig3D = (*(_WORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)v5 & 0xFFFFF000) + 0x10)
                                                          + 4
                                                          * ((int)((int)&v5[-1] - ((unsigned int)v5 & 0xFFFFF000))
                                                           / 28)
                                                          + 20)
                                              + 6)
                                   & 0x200) != 0;
    this->Flags |= 0x8000u;
    pNext = v5->pNext;
    result->pObject = v5;
    v5->RefCount = (unsigned int)pNext;
    v14 = pNext == 0;
  }
  if ( v14 )
    Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  return v13;
}
