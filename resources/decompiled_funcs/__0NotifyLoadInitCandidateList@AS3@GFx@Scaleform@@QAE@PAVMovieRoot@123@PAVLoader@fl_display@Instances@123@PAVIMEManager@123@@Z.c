void __thiscall Scaleform::GFx::AS3::NotifyLoadInitCandidateList::NotifyLoadInitCandidateList(
        Scaleform::GFx::AS3::NotifyLoadInitCandidateList *this,
        Scaleform::GFx::AS3::MovieRoot *pmovieRoot,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::GFx::Resource *pASIMEManager)
{
  this->pMovieRoot = pmovieRoot;
  this->__vftable = (Scaleform::GFx::AS3::NotifyLoadInitCandidateList_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::NotifyLoadInitCandidateList_vtbl *)&Scaleform::GFx::AS3::NotifyLoadInitCandidateList::`vftable';
  this->pLoader.pObject = loader;
  if ( loader )
    loader->RefCount = (loader->RefCount + 1) & 0x8FBFFFFF;
  if ( pASIMEManager )
    Scaleform::RefCountImpl::AddRef(pASIMEManager);
  this->pASIMEManager.pObject = (Scaleform::GFx::AS3::IMEManager *)pASIMEManager;
}
