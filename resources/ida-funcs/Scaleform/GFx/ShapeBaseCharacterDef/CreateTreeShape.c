Scaleform::Ptr<Scaleform::Render::TreeNode> *__thiscall Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(
        Scaleform::GFx::ShapeBaseCharacterDef *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::Render::ContextImpl::Context *v4; // ebx
  Scaleform::Render::TreeNode::NodeData *v6; // eax
  Scaleform::Render::TreeNode::NodeData *v7; // edi
  Scaleform::Render::TreeShape *EntryHelper; // ebx
  Scaleform::GFx::MovieDefImpl *v9; // ebp
  Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *v10; // edi

  v4 = context;
  v6 = (Scaleform::Render::TreeNode::NodeData *)context->pHeap->Alloc(context->pHeap, 160u, 0);
  v7 = v6;
  if ( v6 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v6, ET_Shape);
    v7->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeShape::NodeData::`vftable';
    v7[1].__vftable = 0;
    *(float *)&v7[1].Type = 0.0;
  }
  EntryHelper = (Scaleform::Render::TreeShape *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                  v4,
                                                  &v7->Scaleform::Render::ContextImpl::EntryData);
  if ( this->NeedsResolving(this) )
  {
    v9 = defImpl;
    Scaleform::GFx::MovieDefImpl::BindTaskData::GetShapeMeshProvider(
      defImpl->pBindData.pObject,
      (Scaleform::Ptr<Scaleform::Render::ShapeMeshProvider> *)&context,
      this->pShapeMeshProvider.pObject);
    if ( !context )
    {
      v10 = this->BindResourcesInStyles(this, &defImpl, &v9->pBindData.pObject->ResourceBinding);
      if ( v10->pObject )
        v10->pObject->AddRef(&v10->pObject->Scaleform::Render::MeshProvider);
      if ( context )
        ((void (__thiscall *)(Scaleform::Render::ContextImpl::EntryTable *))context->Table.pContext->Table.pContext)(&context->Table);
      context = (Scaleform::Render::ContextImpl::Context *)v10->pObject;
      if ( defImpl )
        ((void (__thiscall *)(Scaleform::GFx::ResourceLibBase **))defImpl->pLib[1].__vftable)(&defImpl->pLib);
      Scaleform::GFx::MovieDefImpl::BindTaskData::AddShapeMeshProvider(
        v9->pBindData.pObject,
        this->pShapeMeshProvider.pObject,
        (Scaleform::Render::ShapeMeshProvider *)context);
    }
    Scaleform::Render::TreeShape::SetShape(EntryHelper, (Scaleform::Render::ContextImpl::EntryData_vtbl *)context);
    if ( context )
      ((void (__thiscall *)(Scaleform::Render::ContextImpl::EntryTable *))context->Table.pContext->Table.pContext)(&context->Table);
  }
  else
  {
    Scaleform::Render::TreeShape::SetShape(
      EntryHelper,
      (Scaleform::Render::ContextImpl::EntryData_vtbl *)this->pShapeMeshProvider.pObject);
  }
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  result->pObject = EntryHelper;
  if ( EntryHelper )
  {
    if ( EntryHelper->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
  }
  return result;
}
