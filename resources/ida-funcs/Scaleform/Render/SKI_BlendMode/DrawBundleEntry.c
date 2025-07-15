void __userpurge Scaleform::Render::SKI_BlendMode::DrawBundleEntry(
        Scaleform::Render::SKI_BlendMode *this@<ecx>,
        void *data,
        Scaleform::Render::BundleEntry *__formal,
        Scaleform::Render::Renderer2DImpl *r2d,
        int a5)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v6; // eax
  int v7; // ecx
  _DWORD *v8; // esi
  int v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpNativeFunctionId v11; // [esp+0h] [ebp-1Ch]
  Scaleform::Render::SKI_BlendMode::RQII_BlendMode *v12; // [esp+8h] [ebp-14h] BYREF
  __int64 v13; // [esp+Ch] [ebp-10h] BYREF
  _DWORD *v14; // [esp+14h] [ebp-8h]

  Instance = Scaleform::AmpServer::GetInstance();
  v6 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::AmpServer *, const char *))Instance->GetDisplayStats)(
                                Instance,
                                "SKI_BlendMode::DrawBundleEntry");
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    (Scaleform::AmpFunctionTimer *)((char *)&v13 + 4),
    v6,
    (const char *)2,
    Amp_Profile_Level_Null,
    v11);
  LODWORD(v13) = __formal;
  v7 = *(_DWORD *)(a5 + 40);
  v12 = &Scaleform::Render::SKI_BlendMode::RQII_Instance;
  (*(void (__thiscall **)(int, Scaleform::Render::SKI_BlendMode::RQII_BlendMode **))(*(_DWORD *)v7 + 124))(v7, &v12);
  v8 = v14;
  if ( v14 )
  {
    v9 = *v14;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(v9 + 8))(v8, ProfileTicks - v13, (ProfileTicks - v13) >> 32);
  }
}
