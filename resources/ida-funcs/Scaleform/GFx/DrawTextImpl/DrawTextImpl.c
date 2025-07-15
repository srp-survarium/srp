void __userpurge Scaleform::GFx::DrawTextImpl::DrawTextImpl(
        Scaleform::GFx::DrawTextImpl *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::DrawTextManager *pdtMgr)
{
  Scaleform::GFx::DrawTextManager *v3; // edi
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // edi
  Scaleform::Render::TreeText::NodeData *v8; // eax
  Scaleform::Render::ContextImpl::EntryData *v9; // ebx
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::TreeText *v12; // edi
  int v13; // ebx
  Scaleform::GFx::Resource **Log; // eax
  Scaleform::GFx::Resource *v17; // [esp+0h] [ebp-8h]

  v3 = pdtMgr;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::DrawTextImpl_vtbl *)&Scaleform::GFx::DrawTextImpl::`vftable';
  if ( v3 )
    ++v3->RefCount;
  this->pDrawTextCtxt.pObject = v3;
  this->pTextNode.pObject = 0;
  this->pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  pImpl = v3->pImpl;
  pHeap = pImpl->RenderContext.pHeap;
  p_RenderContext = &pImpl->RenderContext;
  v8 = (Scaleform::Render::TreeText::NodeData *)pHeap->Alloc(pHeap, 160u, 0);
  v9 = v8;
  if ( v8 )
    Scaleform::Render::TreeText::NodeData::NodeData(v8);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(p_RenderContext, v9);
  pObject = this->pTextNode.pObject;
  v12 = (Scaleform::Render::TreeText *)EntryHelper;
  v13 = a2;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pTextNode.pObject = v12;
  Log = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLog(
                                       &this->pDrawTextCtxt.pObject->Scaleform::GFx::StateBag,
                                       (Scaleform::Ptr<Scaleform::Log> *)&pdtMgr);
  Scaleform::Render::TreeText::Init(
    this->pTextNode.pObject,
    v13,
    this->pDrawTextCtxt.pObject->pImpl->pTextAllocator.pObject,
    (Scaleform::Render::Text::Allocator *)this->pDrawTextCtxt.pObject->pImpl->pFontManager.pObject,
    *Log,
    v17);
  if ( pdtMgr )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pdtMgr);
}
