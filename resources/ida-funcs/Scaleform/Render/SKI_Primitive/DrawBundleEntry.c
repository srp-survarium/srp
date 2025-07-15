void __thiscall Scaleform::Render::SKI_Primitive::DrawBundleEntry(
        Scaleform::Render::SKI_Primitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *a4)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v5; // eax
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::ArrayDefaultPolicy *p_Policy; // edx
  int v8; // ecx
  void (__thiscall *v9)(int, _DWORD *); // edx
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
    "SKI_Primitive::DrawBundleEntry",
    Amp_Profile_Level_High,
    Amp_Native_Function_Id_Invalid);
  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    if ( pObject == (Scaleform::Render::Bundle *)-40 )
      p_Policy = 0;
    else
      p_Policy = &pObject[1].Entries.Data.Policy;
    v8 = *(_DWORD *)(pObject[1].RefCount + 40);
    v13[0] = p_Policy;
    v9 = *(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v8 + 124);
    v13[1] = 0;
    v9(v8, v13);
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
