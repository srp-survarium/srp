void __thiscall Scaleform::Render::Renderer2DImpl::EndFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v3; // eax
  Scaleform::Render::GlyphCache *pObject; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v6; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v8; // [esp+4h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v3 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v8,
    v3,
    "Renderer2DImpl::EndFrame",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  this->pHal.pObject->EndFrame(this->pHal.pObject);
  Scaleform::Render::ContextImpl::RenderNotify::EndFrameContextNotify(this);
  pObject = this->pGlyphCache.pObject;
  if ( pObject )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pObject);
  Stats = v8.Stats;
  if ( v8.Stats )
  {
    v6 = v8.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v6->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v8.StartTicks),
      (ProfileTicks - v8.StartTicks) >> 32);
  }
}
