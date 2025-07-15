void __thiscall Scaleform::GFx::LoadProcess::Execute(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v3; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v5; // [esp+4h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v5,
    this->LoadProcessStats.pObject,
    "LoadProcess::Execute",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Invalid);
  Scaleform::GFx::MovieDataDef::LoadTaskData::Read(this->pLoadData.pObject, this, this->pBindProcess.pObject);
  Stats = v5.Stats;
  if ( v5.Stats )
  {
    v3 = v5.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v3->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v5.StartTicks),
      (ProfileTicks - v5.StartTicks) >> 32);
  }
}
