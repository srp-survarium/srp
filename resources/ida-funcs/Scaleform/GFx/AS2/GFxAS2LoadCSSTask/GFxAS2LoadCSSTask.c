void __thiscall Scaleform::GFx::AS2::GFxAS2LoadCSSTask::GFxAS2LoadCSSTask(
        Scaleform::GFx::AS2::GFxAS2LoadCSSTask *this,
        Scaleform::GFx::Resource *pls,
        const Scaleform::String *level0Path,
        const Scaleform::String *url,
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::CSSHolderType holder)
{
  Scaleform::GFx::AS2::ASCSSFileLoader *pObject; // ecx

  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadCSSTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadCSSTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadCSSTask_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadCSSTask::`vftable';
  if ( pls )
    Scaleform::RefCountImpl::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  pObject = holder.Loader.pObject;
  if ( holder.Loader.pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)holder.Loader.pObject);
    pObject = holder.Loader.pObject;
  }
  this->pLoader.pObject = pObject;
  this->Done = 0;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  if ( holder.ASObj.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&holder.ASObj);
}
