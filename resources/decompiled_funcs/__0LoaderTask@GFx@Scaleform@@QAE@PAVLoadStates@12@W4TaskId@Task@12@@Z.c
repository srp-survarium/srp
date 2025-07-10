void __thiscall Scaleform::GFx::LoaderTask::LoaderTask(
        Scaleform::GFx::LoaderTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::Task::TaskId id)
{
  Scaleform::GFx::LoaderImpl *pLib; // edi
  Scaleform::GFx::LoadProcessNode *v5; // eax
  Scaleform::GFx::LoadProcessNode *v6; // ecx

  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = id;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  if ( pls )
    Scaleform::RefCountImpl::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  pLib = (Scaleform::GFx::LoaderImpl *)pls[4].pLib;
  EnterCriticalSection(&pLib->LoadProcessesLock.cs);
  v5 = (Scaleform::GFx::LoadProcessNode *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  if ( v5 )
  {
    v5->pTask = this;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v6->pPrev = pLib->LoadProcesses.Root.pPrev;
  v6->pNext = (Scaleform::GFx::LoadProcessNode *)&pLib->LoadProcesses;
  pLib->LoadProcesses.Root.pPrev->pNext = v6;
  pLib->LoadProcesses.Root.pPrev = v6;
  LeaveCriticalSection(&pLib->LoadProcessesLock.cs);
}
