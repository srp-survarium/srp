void __thiscall Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(
        Scaleform::GFx::LoaderImpl *this,
        Scaleform::GFx::LoaderTask *ptask)
{
  Scaleform::Lock *p_LoadProcessesLock; // edi
  Scaleform::GFx::LoadProcessNode *pNext; // eax

  p_LoadProcessesLock = &this->LoadProcessesLock;
  EnterCriticalSection(&this->LoadProcessesLock.cs);
  pNext = this->LoadProcesses.Root.pNext;
  if ( pNext != (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses )
  {
    while ( pNext->pTask != ptask )
    {
      pNext = pNext->pNext;
      if ( pNext == (Scaleform::GFx::LoadProcessNode *)&this->LoadProcesses )
        goto LABEL_6;
    }
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::GFx::LoadProcessNode>::$F43B522E6CDF9F9352B616E4B3331646::pPrev = pNext->pPrev;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
  }
LABEL_6:
  LeaveCriticalSection(&p_LoadProcessesLock->cs);
}
