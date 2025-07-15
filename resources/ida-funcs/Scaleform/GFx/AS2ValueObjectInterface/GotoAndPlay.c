char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        unsigned int frame,
        bool stop)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v11; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 v13; // rax
  Scaleform::AmpFunctionTimer v14; // [esp+8h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v14,
    v5,
    "ObjectInterface::GotoAndPlay",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GotoAndPlay);
  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( v6 && (v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    v6->GotoFrame(v6, frame - 1);
    v6->SetPlayState(v6, (Scaleform::GFx::PlayState)stop);
    Stats = v14.Stats;
    if ( v14.Stats )
    {
      v8 = v14.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v14.StartTicks),
        (ProfileTicks - v14.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v11 = v14.Stats;
    if ( v14.Stats )
    {
      v12 = v14.Stats->__vftable;
      v13 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
        v11,
        v13 - LODWORD(v14.StartTicks),
        (v13 - v14.StartTicks) >> 32);
    }
    return 0;
  }
}


char __thiscall Scaleform::GFx::AS2ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::CharacterHandle *pdata,
        const char *frame,
        bool stop)
{
  Scaleform::GFx::AMP::ViewStats *v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // esi
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  Scaleform::AmpStats *v11; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 v13; // rax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 ProfileTicks; // rax
  unsigned int v17; // [esp+10h] [ebp-14h] BYREF
  Scaleform::AmpFunctionTimer v18; // [esp+14h] [ebp-10h] BYREF

  v5 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v18,
    v5,
    "ObjectInterface::GotoAndPlay",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GotoAndPlay);
  v6 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pdata, this->pMovieRoot);
  if ( !v6 || (v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    Stats = v18.Stats;
    if ( v18.Stats )
    {
      v15 = v18.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v18.StartTicks),
        (ProfileTicks - v18.StartTicks) >> 32);
    }
    return 0;
  }
  if ( !v6->GetLabeledFrame(v6, frame, &v17, 1) )
  {
    v11 = v18.Stats;
    if ( v18.Stats )
    {
      v12 = v18.Stats->__vftable;
      v13 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
        v11,
        v13 - LODWORD(v18.StartTicks),
        (v13 - v18.StartTicks) >> 32);
      return 0;
    }
    return 0;
  }
  v6->GotoFrame(v6, v17);
  v6->SetPlayState(v6, (Scaleform::GFx::PlayState)stop);
  v7 = v18.Stats;
  if ( v18.Stats )
  {
    v8 = v18.Stats->__vftable;
    v9 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
      v7,
      v9 - LODWORD(v18.StartTicks),
      (v9 - v18.StartTicks) >> 32);
  }
  return 1;
}
