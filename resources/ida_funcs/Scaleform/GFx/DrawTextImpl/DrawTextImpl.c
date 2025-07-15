void __thiscall Scaleform::GFx::DrawTextImpl::DrawTextImpl(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::RefCountVImpl *pdtMgr)
{
  Scaleform::GFx::DrawTextManager *v2; // edi
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Render::ContextImpl::Context *p_RenderContext; // edi
  Scaleform::Render::TreeText::NodeData *v7; // eax
  Scaleform::Render::ContextImpl::EntryData *v8; // ebx
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // eax
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::TreeText *v11; // edi
  Scaleform::Ptr<Scaleform::Log> *Log; // eax

  v2 = (Scaleform::GFx::DrawTextManager *)pdtMgr;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::DrawTextImpl_vtbl *)&Scaleform::GFx::DrawTextImpl::`vftable';
  if ( v2 )
    ++v2->RefCount;
  this->pDrawTextCtxt.pObject = v2;
  this->pTextNode.pObject = 0;
  this->pHeap = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  pImpl = v2->pImpl;
  pHeap = pImpl->RenderContext.pHeap;
  p_RenderContext = &pImpl->RenderContext;
  v7 = (Scaleform::Render::TreeText::NodeData *)pHeap->Alloc(pHeap, 160u, 0);
  v8 = v7;
  if ( v7 )
    Scaleform::Render::TreeText::NodeData::NodeData(v7);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(p_RenderContext, v8);
  pObject = this->pTextNode.pObject;
  v11 = (Scaleform::Render::TreeText *)EntryHelper;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pTextNode.pObject = v11;
  Log = Scaleform::GFx::StateBag::GetLog(
          &this->pDrawTextCtxt.pObject->Scaleform::GFx::StateBag,
          (Scaleform::Ptr<Scaleform::Log> *)&pdtMgr);
  Scaleform::Render::TreeText::Init(
    this->pTextNode.pObject,
    this->pDrawTextCtxt.pObject->pImpl->pTextAllocator.pObject,
    this->pDrawTextCtxt.pObject->pImpl->pFontManager.pObject,
    Log->pObject);
  if ( pdtMgr )
    Scaleform::RefCountImpl::Release(pdtMgr);
}
