char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        Scaleform::Render::Cxform *pcx)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::DisplayObjectBase *v6; // esi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::AmpStats *v11; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 v13; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v17; // [esp+8h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v17,
    v4,
    "ObjectInterface::GetCxform",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GetCxform);
  v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  v6 = v5;
  if ( v5 )
  {
    if ( v5->GetType(v5) == MouseWheel || (v6->Flags & 0x400) != 0 )
    {
      qmemcpy(pcx, Scaleform::GFx::DisplayObjectBase::GetCxform(v6), sizeof(Scaleform::Render::Cxform));
      Stats = v17.Stats;
      if ( v17.Stats )
      {
        v15 = v17.Stats->__vftable;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v17.StartTicks),
          (ProfileTicks - v17.StartTicks) >> 32);
      }
      return 1;
    }
    else
    {
      v11 = v17.Stats;
      if ( v17.Stats )
      {
        v12 = v17.Stats->__vftable;
        v13 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
          v11,
          v13 - LODWORD(v17.StartTicks),
          (v13 - v17.StartTicks) >> 32);
      }
      return 0;
    }
  }
  else
  {
    v7 = v17.Stats;
    if ( v17.Stats )
    {
      v8 = v17.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v17.StartTicks),
        (v9 - v17.StartTicks) >> 32);
    }
    return 0;
  }
}
