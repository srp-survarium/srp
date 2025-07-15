void __thiscall Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v3; // edi
  Scaleform::GFx::ASMovieRootBase *pASRoot; // edx
  Scaleform::GFx::DisplayList *p_mDisplayList; // ebx
  Scaleform::GFx::DisplayObjectBase *DisplayIndex; // eax
  Scaleform::Render::TreeNode *pObject; // eax
  Scaleform::GFx::MovieImpl::IndirectTransPair result; // [esp+4h] [ebp-10h] BYREF

  if ( (this->Flags & 0x8000u) != 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v3 = RenderNode;
    if ( RenderNode )
      ++RenderNode->RefCount;
    if ( this->pIndXFormData->IsOrig3D )
    {
      Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, (const __m128i *)this->pIndXFormData);
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
    Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(pASRoot->pMovieImpl, &result, this);
    if ( result.OriginalParent.pObject )
    {
      p_mDisplayList = &result.OriginalParent.pObject->mDisplayList;
      DisplayIndex = (Scaleform::GFx::DisplayObjectBase *)Scaleform::GFx::DisplayList::FindDisplayIndex(
                                                            &result.OriginalParent.pObject->mDisplayList,
                                                            this);
      if ( DisplayIndex != (Scaleform::GFx::DisplayObjectBase *)-1 )
        Scaleform::GFx::DisplayList::InsertIntoRenderTree(p_mDisplayList, result.OriginalParent.pObject, DisplayIndex);
    }
    Scaleform::Render::TreeNode::SetOrigScale9Parent(v3, 0);
    if ( result.OriginalParent.pObject )
      Scaleform::RefCountNTSImpl::Release(result.OriginalParent.pObject);
    if ( result.Obj.pObject )
      Scaleform::RefCountNTSImpl::Release(result.Obj.pObject);
    pObject = result.TransformParent.pObject;
    if ( result.TransformParent.pObject )
    {
      --result.TransformParent.pObject->RefCount;
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
