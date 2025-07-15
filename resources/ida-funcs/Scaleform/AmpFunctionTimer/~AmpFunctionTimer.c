void __thiscall Scaleform::AmpFunctionTimer::~AmpFunctionTimer(Scaleform::AmpFunctionTimer *this)
{
  Scaleform::AmpStats_vtbl *v2; // edi
  unsigned __int64 ProfileTicks; // rax

  if ( this->Stats )
  {
    v2 = this->Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v2->NativePopCallstack)(
      this->Stats,
      ProfileTicks - LODWORD(this->StartTicks),
      (ProfileTicks - this->StartTicks) >> 32);
  }
}
