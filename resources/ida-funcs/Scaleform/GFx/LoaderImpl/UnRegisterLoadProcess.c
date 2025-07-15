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
    pNext->pNext->Scaleform::ListNode<Scaleform::GFx::LoadProcessNode>::$BC59A0EDCD2D4A0AD47AE3B379B0B70F::pPrev = pNext->pPrev;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
  }
LABEL_6:
  LeaveCriticalSection(&p_LoadProcessesLock->cs);
}
