void __thiscall Scaleform::GFx::DrawingContext::DrawingContext(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Render::ContextImpl::Context *renCtxt,
        Scaleform::GFx::Resource *imgCreator)
{
  Scaleform::Render::ContextImpl::Context *RenContext; // ebp
  Scaleform::Render::TreeNode::NodeData *v6; // eax
  Scaleform::Render::TreeNode::NodeData *v7; // edi
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeContainer *pObject; // ecx
  Scaleform::Render::TreeContainer *v10; // edi

  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::DrawingContext_vtbl *)&Scaleform::GFx::DrawingContext::`vftable';
  this->pHeap = pheap;
  this->pTreeContainer.pObject = 0;
  this->RenContext = renCtxt;
  if ( imgCreator )
    Scaleform::RefCountImpl::AddRef(imgCreator);
  this->ImgCreator.pObject = (Scaleform::GFx::ImageCreator *)imgCreator;
  this->Shapes.pObject = 0;
  this->mFillStyle.pFill.pObject = 0;
  this->mLineStyle.pFill.pObject = 0;
  this->mLineStyle.pDashes.pObject = 0;
  this->PosInfo.Sfactor = 1.0;
  this->PosInfo.Pos = 0;
  this->PosInfo.StartX = 0;
  this->PosInfo.StartY = 0;
  this->PosInfo.LastX = 0;
  this->PosInfo.LastY = 0;
  this->PosInfo.FillBase = 0;
  this->PosInfo.StrokeBase = 0;
  this->PosInfo.NumFillBits = 0;
  this->PosInfo.NumStrokeBits = 0;
  this->PosInfo.Fill0 = 0;
  this->PosInfo.Fill1 = 0;
  this->PosInfo.Stroke = 0;
  this->PosInfo.Initialized = 0;
  RenContext = this->RenContext;
  this->States = 1;
  this->pPrev = 0;
  this->pNext = 0;
  v6 = (Scaleform::Render::TreeNode::NodeData *)RenContext->pHeap->Alloc(RenContext->pHeap, 160u, 0);
  v7 = v6;
  if ( v6 )
  {
    Scaleform::Render::TreeNode::NodeData::NodeData(v6, ET_Container);
    v7->__vftable = (Scaleform::Render::TreeNode::NodeData_vtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
    *(_DWORD *)&v7[1].Type = 0;
    v7[1].__vftable = 0;
  }
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(
                  RenContext,
                  &v7->Scaleform::Render::ContextImpl::EntryData);
  pObject = this->pTreeContainer.pObject;
  v10 = (Scaleform::Render::TreeContainer *)EntryHelper;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pTreeContainer.pObject = v10;
  Scaleform::GFx::DrawingContext::Clear(this);
}
