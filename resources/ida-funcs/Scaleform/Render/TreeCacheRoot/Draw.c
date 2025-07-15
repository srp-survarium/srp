void __thiscall Scaleform::Render::TreeCacheRoot::Draw(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v3; // eax
  Scaleform::AmpStats *Stats; // esi
  unsigned int v5; // eax
  _DWORD *v6; // edi
  Scaleform::AmpServer *v7; // eax
  Scaleform::AmpStats *v8; // eax
  Scaleform::AmpStats *v9; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 v13; // rax
  Scaleform::AmpFunctionTimer v14; // [esp+14h] [ebp-20h] BYREF
  Scaleform::AmpFunctionTimer v15; // [esp+24h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v3 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v3,
    "TreeCacheRoot::Draw",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( (this->Flags & 3) != 1 )
  {
    Stats = v14.Stats;
    if ( !v14.Stats )
      return;
    goto LABEL_12;
  }
  v5 = *(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                 + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                 + 20)
     & 0xFFFFFFFE;
  v6 = (_DWORD *)(v5 + 160);
  if ( *(_DWORD *)(v5 + 160) && *(_DWORD *)(v5 + 164) )
    Scaleform::Render::HAL::BeginDisplay(
      this->pRenderer2D->pHal.pObject,
      *(Scaleform::Render::Color *)(v5 + 204),
      (const Scaleform::Render::Viewport *)(v5 + 160));
  ((void (__thiscall *)(Scaleform::Render::HAL *, Scaleform::Render::BundleEntry *, Scaleform::Render::BundleEntry *, Scaleform::Render::Renderer2DImpl *))this->pRenderer2D->pHal.pObject->DrawBundleEntries)(
    this->pRenderer2D->pHal.pObject,
    this->CachedChildPattern.pFirst,
    this->CachedChildPattern.pLast,
    this->pRenderer2D);
  if ( *v6 && v6[1] )
  {
    v7 = Scaleform::AmpServer::GetInstance();
    v8 = v7->GetDisplayStats(v7);
    Scaleform::AmpFunctionTimer::AmpFunctionTimer(
      &v15,
      v8,
      "HAL::EndDisplay",
      Amp_Profile_Level_High,
      Amp_Native_Function_Id_Invalid);
    Scaleform::Render::HAL::EndDisplay(this->pRenderer2D->pHal.pObject);
    v9 = v15.Stats;
    if ( v15.Stats )
    {
      v10 = v15.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        v9,
        ProfileTicks - LODWORD(v15.StartTicks),
        (ProfileTicks - v15.StartTicks) >> 32);
    }
  }
  Stats = v14.Stats;
  if ( v14.Stats )
  {
LABEL_12:
    v12 = v14.Stats->__vftable;
    v13 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
      Stats,
      v13 - LODWORD(v14.StartTicks),
      (v13 - v14.StartTicks) >> 32);
  }
}
