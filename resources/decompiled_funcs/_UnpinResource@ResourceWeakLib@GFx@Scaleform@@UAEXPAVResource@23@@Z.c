void __thiscall Scaleform::GFx::ResourceWeakLib::UnpinResource(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::Lock *p_ResourceLock; // edi
  Scaleform::GFx::ResourceLib *pStrongLib; // esi
  Scaleform::GFx::Resource *v5; // esi
  Scaleform::GFx::ResourceLibBase *pLib; // ecx

  p_ResourceLock = &this->ResourceLock;
  EnterCriticalSection(&this->ResourceLock.cs);
  pStrongLib = this->pStrongLib;
  if ( pStrongLib )
  {
    Scaleform::HashSetBase<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc,Scaleform::AllocatorGH<Scaleform::GFx::Resource *,2>,Scaleform::HashsetEntry<Scaleform::GFx::Resource *,Scaleform::GFx::ResourceLib::ResourcePtrHashFunc>>::RemoveAlt<Scaleform::GFx::Resource *>(
      &pStrongLib->PinSet,
      &pres);
    v5 = pres;
    if ( InterlockedExchangeAdd(&pres->RefCount.Value, -1) == 1 )
    {
      pLib = v5->pLib;
      if ( pLib )
      {
        pLib->RemoveResourceOnRelease(pLib, v5);
        v5->pLib = 0;
      }
      ((void (__thiscall *)(Scaleform::GFx::Resource *, int))v5->~Scaleform::GFx::Resource)(v5, 1);
    }
  }
  LeaveCriticalSection(&p_ResourceLock->cs);
}
