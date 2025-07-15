void __thiscall Scaleform::Render::SKI_UserData::DrawBundleEntry(
        Scaleform::Render::SKI_UserData *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r2d)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v5; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::HAL *v7; // ecx
  Scaleform::ArrayLH<Scaleform::Render::BundleEntry *,2,Scaleform::ArrayDefaultPolicy> *p_Entries; // eax
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v11; // edi
  unsigned __int64 ProfileTicks; // rax
  _DWORD v13[2]; // [esp+0h] [ebp-18h] BYREF
  Scaleform::AmpFunctionTimer v14; // [esp+8h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v5 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v5,
    "Scaleform::Render::SKI_UserData::DrawBundleEntry",
    Amp_Profile_Level_High,
    Amp_Native_Function_Id_Invalid);
  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v7 = r2d->pHal.pObject;
    if ( pObject == (Scaleform::Render::Bundle *)-32 )
      p_Entries = 0;
    else
      p_Entries = &pObject[1].Entries;
    v13[0] = p_Entries;
    Draw = v7->Draw;
    v13[1] = 0;
    Draw(v7, (const Scaleform::Render::RenderQueueItem *)v13);
  }
  Stats = v14.Stats;
  if ( v14.Stats )
  {
    v11 = v14.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v11->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v14.StartTicks),
      (ProfileTicks - v14.StartTicks) >> 32);
  }
}
