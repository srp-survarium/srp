void __thiscall Scaleform::GFx::MovieImpl::ProcessUnloadQueue(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::InteractiveObject *pUnloadListHead; // esi
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // edi
  void (__thiscall *OnEventUnload)(Scaleform::GFx::DisplayObjectBase *); // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v9; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v9,
    this->AdvanceStats.pObject,
    "MovieImpl::ProcessUnloadQueue",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
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
  Stats = v9.Stats;
  if ( v9.Stats )
  {
    p_NativePopCallstack = &v9.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v9.StartTicks),
      (ProfileTicks - v9.StartTicks) >> 32);
  }
}
