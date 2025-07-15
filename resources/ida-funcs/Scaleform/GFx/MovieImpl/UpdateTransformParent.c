void __thiscall Scaleform::GFx::MovieImpl::UpdateTransformParent(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::DisplayObjectBase *obj,
        Scaleform::GFx::DisplayObjectBase *transfParent)
{
  unsigned int Size; // edx
  int v4; // eax
  Scaleform::GFx::MovieImpl::IndirectTransPair *Data; // esi
  Scaleform::GFx::DisplayObjectBase **i; // ecx
  Scaleform::GFx::MovieImpl::IndirectTransPair *v7; // edi
  Scaleform::Render::TreeNode *RenderNode; // eax
  Scaleform::Render::TreeNode *v9; // esi
  Scaleform::Render::ContextImpl::Entry *pObject; // ecx

  Size = this->IndirectTransformPairs.Data.Size;
  v4 = 0;
  if ( Size )
  {
    Data = this->IndirectTransformPairs.Data.Data;
    for ( i = &Data->Obj.pObject; *i != obj; i += 4 )
    {
      if ( ++v4 >= Size )
        return;
    }
    v7 = &Data[v4];
    if ( transfParent )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(transfParent);
      v9 = RenderNode;
      if ( RenderNode )
        ++RenderNode->RefCount;
    }
    else
    {
      v9 = 0;
    }
    pObject = v7->TransformParent.pObject;
    if ( v7->TransformParent.pObject )
    {
      if ( pObject->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    v7->TransformParent.pObject = v9;
    v7->OrigParentDepth = -1;
  }
}
