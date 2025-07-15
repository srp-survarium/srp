void __thiscall Scaleform::GFx::LoadVarsTask::LoadVarsTask(
        Scaleform::GFx::LoadVarsTask *this,
        Scaleform::GFx::Resource *pls,
        const Scaleform::String *level0Path,
        const Scaleform::String *url)
{
  this->__vftable = (Scaleform::GFx::LoadVarsTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::LoadVarsTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::LoadVarsTask_vtbl *)&Scaleform::GFx::LoadVarsTask::`vftable';
  if ( pls )
    Scaleform::RefCountImpl::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  Scaleform::String::String(&this->Data);
  this->FileLen = 0;
  this->Done = 0;
  this->Succeeded = 0;
}
