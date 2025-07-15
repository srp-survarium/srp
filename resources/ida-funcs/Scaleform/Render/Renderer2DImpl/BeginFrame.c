bool __thiscall Scaleform::Render::Renderer2DImpl::BeginFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v3; // eax
  Scaleform::Render::GlyphCache *pObject; // ecx
  bool v5; // al
  Scaleform::AmpStats *Stats; // esi
  bool v7; // bl
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v11; // [esp+8h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v3 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v11,
    v3,
    "Renderer2DImpl::BeginFrame",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  Scaleform::Render::MeshKeyManager::ProcessKillList(this->pMeshKeyManager.pObject);
  pObject = this->pGlyphCache.pObject;
  if ( pObject )
    Scaleform::Render::GlyphCache::OnBeginFrame(pObject);
  v5 = this->pHal.pObject->BeginFrame(this->pHal.pObject);
  Stats = v11.Stats;
  v7 = v5;
  if ( v11.Stats )
  {
    v8 = v11.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v11.StartTicks),
      (ProfileTicks - v11.StartTicks) >> 32);
  }
  return v7;
}
