void __thiscall Scaleform::GFx::MovieImpl::ProcessUnloadQueue(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pUnloadListHead; // esi
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // edi
  void (__thiscall *OnEventUnload)(Scaleform::GFx::DisplayObjectBase *); // edx
  Scaleform::GFx::InteractiveObject *pParent; // ecx

  pUnloadListHead = this->pUnloadListHead;
  if ( pUnloadListHead )
  {
    do
    {
      pPlayNextOpt = pUnloadListHead->pPlayNextOpt;
      OnEventUnload = pUnloadListHead->OnEventUnload;
      pUnloadListHead->pPlayNextOpt = 0;
      OnEventUnload(pUnloadListHead);
      pParent = pUnloadListHead->pParent;
      if ( pParent )
        pParent->RemoveDisplayObject(pParent, pUnloadListHead);
      Scaleform::RefCountNTSImpl::Release(pUnloadListHead);
      pUnloadListHead = pPlayNextOpt;
    }
    while ( pPlayNextOpt );
    this->pUnloadListHead = 0;
  }
}
