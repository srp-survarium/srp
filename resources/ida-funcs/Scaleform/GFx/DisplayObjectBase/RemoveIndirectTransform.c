void __thiscall Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v3; // edi
  Scaleform::GFx::ASMovieRootBase *pASRoot; // edx
  Scaleform::GFx::DisplayList *p_mDisplayList; // ebx
  unsigned int DisplayIndex; // eax
  Scaleform::Render::TreeNode *pObject; // eax
  Scaleform::GFx::MovieImpl::IndirectTransPair p; // [esp+4h] [ebp-10h] BYREF

  if ( (this->Flags & 0x8000u) != 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v3 = RenderNode;
    if ( RenderNode )
      ++RenderNode->RefCount;
    if ( this->pIndXFormData->IsOrig3D )
    {
      Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &this->pIndXFormData->OrigTransformMatrix);
    }
    else
    {
      Scaleform::Render::TreeNode::Clear3D(RenderNode);
      Scaleform::Render::TreeNode::SetMatrix(v3, (const Scaleform::Render::Matrix2x4<float> *)this->pIndXFormData);
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pIndXFormData);
    pASRoot = this->pASRoot;
    this->Flags &= ~0x8000u;
    this->pIndXFormData = 0;
    Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(pASRoot->pMovieImpl, &p, this);
    if ( p.OriginalParent.pObject )
    {
      p_mDisplayList = &p.OriginalParent.pObject->mDisplayList;
      DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(&p.OriginalParent.pObject->mDisplayList, this);
      if ( DisplayIndex != -1 )
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(p_mDisplayList, p.OriginalParent.pObject, DisplayIndex);
    }
    Scaleform::Render::TreeNode::SetOrigScale9Parent(v3, 0);
    if ( p.OriginalParent.pObject )
      Scaleform::RefCountNTSImpl::Release(p.OriginalParent.pObject);
    if ( p.Obj.pObject )
      Scaleform::RefCountNTSImpl::Release(p.Obj.pObject);
    pObject = p.TransformParent.pObject;
    if ( p.TransformParent.pObject )
    {
      --p.TransformParent.pObject->RefCount;
      if ( !pObject->RefCount )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    if ( v3 )
    {
      if ( v3->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
    }
  }
}
