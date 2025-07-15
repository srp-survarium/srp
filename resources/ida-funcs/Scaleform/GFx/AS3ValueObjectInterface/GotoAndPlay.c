char __userpurge Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay@<al>(
        Scaleform::GFx::AS3ValueObjectInterface *this@<ecx>,
        int a2@<ebp>,
        _DWORD *pdata,
        unsigned int frame,
        bool stop)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  int v8; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  _WORD *v13; // esi
  Scaleform::AmpStats *v14; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 v16; // rax
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay; // [esp+8h] [ebp-10h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay,
    v6,
    "ObjectInterface::GotoAndPlay",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GotoAndPlay);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v8 + 60) - 17) >= 0xC
    || (*(_DWORD *)(v8 + 56) & 0x20) != 0
    || (v13 = (_WORD *)pdata[12], (v13[31] & 0x400) == 0) )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats )
    {
      v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks) >> 32);
    }
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(_WORD *, unsigned int))(*(_DWORD *)v13 + 432))(v13, frame - 1);
    (*(void (__thiscall **)(_WORD *, bool))(*(_DWORD *)v13 + 448))(v13, stop);
    Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)pObject->pStage.pObject->FrameCounterObj.pObject);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_High);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Frame);
    v14 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats )
    {
      v15 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats->__vftable;
      v16 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
        v14,
        v16 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks),
        (v16 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks) >> 32);
    }
    return 1;
  }
}


char __userpurge Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay@<al>(
        Scaleform::GFx::AS3ValueObjectInterface *this@<ecx>,
        int a2@<ebp>,
        _DWORD *pdata,
        const char *frame,
        bool stop)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS3::MovieRoot *pObject; // edi
  int v8; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v10; // edi
  unsigned __int64 ProfileTicks; // rax
  _WORD *v13; // esi
  Scaleform::AmpStats *v14; // esi
  Scaleform::AmpStats_vtbl *v15; // edi
  unsigned __int64 v16; // rax
  Scaleform::AmpStats *v17; // esi
  Scaleform::AmpStats_vtbl *v18; // edi
  unsigned __int64 v19; // rax
  unsigned int frameNum; // [esp+10h] [ebp-14h] BYREF
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay; // [esp+14h] [ebp-10h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay,
    v6,
    "ObjectInterface::GotoAndPlay",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_GotoAndPlay);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v8 + 60) - 17) >= 0xC
    || (*(_DWORD *)(v8 + 56) & 0x20) != 0
    || (v13 = (_WORD *)pdata[12], (v13[31] & 0x400) == 0) )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats )
    {
      v10 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v10->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks),
        (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks) >> 32);
      return 0;
    }
    return 0;
  }
  if ( !(*(unsigned __int8 (__thiscall **)(_WORD *, const char *, unsigned int *, int))(*(_DWORD *)v13 + 424))(
          v13,
          frame,
          &frameNum,
          1) )
  {
    v17 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats;
    if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats )
    {
      v18 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats->__vftable;
      v19 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v18->NativePopCallstack)(
        v17,
        v19 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks),
        (v19 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks) >> 32);
    }
    return 0;
  }
  (*(void (__thiscall **)(_WORD *, unsigned int))(*(_DWORD *)v13 + 432))(v13, frameNum);
  (*(void (__thiscall **)(_WORD *, bool))(*(_DWORD *)v13 + 448))(v13, stop);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)pObject->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Highest);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Frame);
  v14 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats )
  {
    v15 = _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.Stats->__vftable;
    v16 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v15->NativePopCallstack)(
      v14,
      v16 - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks),
      (v16 - _amp_timer_Amp_Native_Function_Id_ObjectInterface_GotoAndPlay.StartTicks) >> 32);
  }
  return 1;
}
