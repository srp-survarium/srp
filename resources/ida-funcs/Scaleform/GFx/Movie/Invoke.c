bool Scaleform::GFx::Movie::Invoke(Scaleform::GFx::Movie *this, char *ppathToMethod, const char *pargFmt, ...)
{
  Scaleform::GFx::Movie *v3; // ecx

  return Scaleform::GFx::Movie::InvokeArgs(v3, (const char *)this, 0, ppathToMethod, (char *)&pargFmt);
}


bool __thiscall Scaleform::GFx::Movie::Invoke(
        Scaleform::GFx::Movie *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  bool v6; // al
  Scaleform::AmpStats *Stats; // esi
  bool v8; // bl
  Scaleform::AmpStats_vtbl *v9; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v12; // [esp+10h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v12,
    this->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject,
    "Movie::Invoke",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Invoke);
  v6 = this->pASMovieRoot.pObject->Invoke(this->pASMovieRoot.pObject, pmethodName, presult, pargs, numArgs);
  Stats = v12.Stats;
  v8 = v6;
  if ( v12.Stats )
  {
    v9 = v12.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v9->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v12.StartTicks),
      (ProfileTicks - v12.StartTicks) >> 32);
  }
  return v8;
}
