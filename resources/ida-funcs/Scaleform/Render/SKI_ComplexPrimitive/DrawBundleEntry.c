void __thiscall Scaleform::Render::SKI_ComplexPrimitive::DrawBundleEntry(
        Scaleform::Render::SKI_ComplexPrimitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *r)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v5; // eax
  Scaleform::Render::ComplexPrimitiveBundle *pObject; // ecx
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v10; // [esp+0h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v5 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v10,
    v5,
    "SKI_ComplexPrimitive::DrawBundleEntry",
    Amp_Profile_Level_High,
    Amp_Native_Function_Id_Invalid);
  pObject = (Scaleform::Render::ComplexPrimitiveBundle *)p->pBundle.pObject;
  if ( pObject )
    Scaleform::Render::ComplexPrimitiveBundle::Draw(pObject, r->pHal.pObject);
  Stats = v10.Stats;
  if ( v10.Stats )
  {
    v8 = v10.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v10.StartTicks),
      (ProfileTicks - v10.StartTicks) >> 32);
  }
}
