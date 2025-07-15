void __thiscall Scaleform::Render::SKI_TextPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_TextPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v5; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::Render::HAL *v7; // ecx
  void (__thiscall *Draw)(Scaleform::Render::HAL *, const Scaleform::Render::RenderQueueItem *); // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  _DWORD v12[2]; // [esp+0h] [ebp-18h] BYREF
  Scaleform::AmpFunctionTimer v13; // [esp+8h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v5 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v13,
    v5,
    "SKI_TextPrimitive::DrawBundleEntry",
    Amp_Profile_Level_High,
    Amp_Native_Function_Id_Invalid);
  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    v7 = r->pHal.pObject;
    v12[0] = pObject + 1;
    Draw = v7->Draw;
    v12[1] = 0;
    Draw(v7, (const Scaleform::Render::RenderQueueItem *)v12);
  }
  Stats = v13.Stats;
  if ( v13.Stats )
  {
    v10 = v13.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v13.StartTicks),
      (ProfileTicks - v13.StartTicks) >> 32);
  }
}
