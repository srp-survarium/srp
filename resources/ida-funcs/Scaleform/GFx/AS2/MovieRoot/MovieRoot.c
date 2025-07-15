void __thiscall Scaleform::GFx::AS2::MovieRoot::MovieRoot(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Resource *memContext,
        Scaleform::GFx::MovieImpl *pmovie,
        Scaleform::GFx::Resource *pas)
{
  Scaleform::MemoryHeap *pLib; // eax
  Scaleform::GFx::Resource_vtbl *v6; // ebp
  Scaleform::GFx::AS2::GlobalContext *pObject; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::Value::ObjectInterface *v9; // eax

  this->__vftable = (Scaleform::GFx::AS2::MovieRoot_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::MovieRoot_vtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  this->pMovieImpl = 0;
  if ( pas )
    Scaleform::RefCountImpl::AddRef(pas);
  this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject = (Scaleform::GFx::ASSupport *)pas;
  this->AVMVersion = pas->__vftable[1].GetResourceTypeCode(pas);
  this->__vftable = (Scaleform::GFx::AS2::MovieRoot_vtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable';
  this->TopNode.pObject = 0;
  Scaleform::RefCountImpl::AddRef(pas);
  this->pASSupport.pObject = (Scaleform::GFx::ASSupport *)pas;
  if ( memContext )
    Scaleform::RefCountImpl::AddRef(memContext);
  this->MemContext.pObject = (Scaleform::GFx::AS2::MemoryContextImpl *)memContext;
  this->NumAdvancesSinceCollection = 0;
  this->LastCollectionFrame = 0;
  this->pGlobalContext.pObject = 0;
  this->ExternalIntfRetVal.T.Type = 0;
  pLib = (Scaleform::MemoryHeap *)memContext->pLib;
  this->ActionQueue.Entries[0].pInsertEntry = 0;
  this->ActionQueue.Entries[0].pLastEntry = 0;
  this->ActionQueue.Entries[0].pActionRoot = 0;
  this->ActionQueue.Entries[1].pInsertEntry = 0;
  this->ActionQueue.Entries[1].pLastEntry = 0;
  this->ActionQueue.Entries[1].pActionRoot = 0;
  this->ActionQueue.Entries[2].pInsertEntry = 0;
  this->ActionQueue.Entries[2].pLastEntry = 0;
  this->ActionQueue.Entries[2].pActionRoot = 0;
  this->ActionQueue.Entries[3].pInsertEntry = 0;
  this->ActionQueue.Entries[3].pLastEntry = 0;
  this->ActionQueue.Entries[3].pActionRoot = 0;
  this->ActionQueue.Entries[4].pInsertEntry = 0;
  this->ActionQueue.Entries[4].pLastEntry = 0;
  this->ActionQueue.Entries[4].pActionRoot = 0;
  this->ActionQueue.Entries[5].pInsertEntry = 0;
  this->ActionQueue.Entries[5].pLastEntry = 0;
  this->ActionQueue.Entries[5].pActionRoot = 0;
  this->ActionQueue.pHeap = pLib;
  this->ActionQueue.ModId = 1;
  this->ActionQueue.pFreeEntry = 0;
  this->ActionQueue.LastSessionId = 1;
  this->ActionQueue.CurrentSessionId = 1;
  this->ActionQueue.FreeEntriesCount = 0;
  v6 = memContext[1].__vftable;
  memset(&this->BuiltinsMgr, 0, 0x270u);
  this->BuiltinsMgr.pStringManager = (Scaleform::GFx::ASStringManager *)v6;
  this->BuiltinsMgr.pStaticStrings = GFx_pASBuiltinTable;
  Scaleform::GFx::ASStringManager::InitBuiltinArray(
    (Scaleform::GFx::ASStringManager *)v6,
    this->BuiltinsMgr.Builtins,
    GFx_pASBuiltinTable,
    0x9Cu);
  this->SpritesWithHitArea.Data.Data = 0;
  this->SpritesWithHitArea.Data.Size = 0;
  this->SpritesWithHitArea.Data.Policy.Capacity = 0;
  this->pMovieImpl = pmovie;
  this->pASMouseListener = 0;
  this->pInvokeAliases = 0;
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = 0;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(this->pMovieImpl, (Scaleform::GFx::Resource *)this);
  pMovieImpl = this->pMovieImpl;
  v9 = (Scaleform::GFx::Value::ObjectInterface *)pMovieImpl->pHeap->Alloc(pMovieImpl->pHeap, 8u, 0);
  if ( v9 )
  {
    v9->pMovieRoot = pMovieImpl;
    v9->__vftable = (Scaleform::GFx::Value::ObjectInterface_vtbl *)&Scaleform::GFx::AS2ValueObjectInterface::`vftable';
    pMovieImpl->pObjectInterface = v9;
  }
  else
  {
    pMovieImpl->pObjectInterface = 0;
  }
}
