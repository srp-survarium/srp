void __thiscall Scaleform::GFx::LoaderTask::LoaderTask(
        Scaleform::GFx::LoaderTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::GFx::Task::TaskId id)
{
  Scaleform::GFx::ResourceLibBase *pLib; // edi
  Scaleform::GFx::ResourceLibBase_vtbl **v5; // eax
  Scaleform::GFx::ResourceLibBase_vtbl **v6; // ecx

  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::Task::`vftable';
  this->RefCount = 1;
  this->ThisTaskId = id;
  this->CurrentState = State_Idle;
  this->__vftable = (Scaleform::GFx::LoaderTask_vtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  if ( pls )
    Scaleform::RefCountImpl::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  pLib = pls[4].pLib;
  EnterCriticalSection((LPCRITICAL_SECTION)&pLib[4]);
  v5 = (Scaleform::GFx::ResourceLibBase_vtbl **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  12,
                                                  0);
  if ( v5 )
  {
    v5[2] = (Scaleform::GFx::ResourceLibBase_vtbl *)this;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  *v6 = pLib[3].__vftable;
  v6[1] = (Scaleform::GFx::ResourceLibBase_vtbl *)&pLib[3];
  pLib[3].RemoveResourceOnRelease = (void (__thiscall *)(Scaleform::GFx::ResourceLibBase *, Scaleform::GFx::Resource *))v6;
  pLib[3].__vftable = (Scaleform::GFx::ResourceLibBase_vtbl *)v6;
  LeaveCriticalSection((LPCRITICAL_SECTION)&pLib[4]);
}
