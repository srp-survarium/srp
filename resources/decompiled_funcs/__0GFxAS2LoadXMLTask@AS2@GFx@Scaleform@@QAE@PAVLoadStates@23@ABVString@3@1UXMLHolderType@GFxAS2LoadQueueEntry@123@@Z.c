void __thiscall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(
        Scaleform::GFx::AS2::GFxAS2LoadXMLTask *this,
        Scaleform::GFx::Resource *pls,
        const Scaleform::String *level0Path,
        const Scaleform::String *url,
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType xmlholder)
{
  Scaleform::GFx::AS2::XMLFileLoader *pObject; // ecx

  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadXMLTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadXMLTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::AS2::GFxAS2LoadXMLTask_vtbl *)&Scaleform::GFx::AS2::GFxAS2LoadXMLTask::`vftable';
  if ( pls )
    Scaleform::RefCountImpl::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  pObject = xmlholder.Loader.pObject;
  if ( xmlholder.Loader.pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)xmlholder.Loader.pObject);
    pObject = xmlholder.Loader.pObject;
  }
  this->pXMLLoader.pObject = pObject;
  this->Done = 0;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  if ( xmlholder.ASObj.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&xmlholder.ASObj);
}
