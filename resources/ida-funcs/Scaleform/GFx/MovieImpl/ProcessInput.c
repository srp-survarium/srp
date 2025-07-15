void __thiscall Scaleform::GFx::MovieImpl::ProcessInput(Scaleform::GFx::MovieImpl *this)
{
  bool v2; // zf
  unsigned int MouseCursorCount; // ecx
  int v4; // ebx
  const Scaleform::GFx::InputEventsQueueEntry *Entry; // eax
  float v6; // eax
  unsigned int *p_PrevButtonsState; // edi
  bool v8; // cl
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::InteractiveObject *v10; // ebx
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  Scaleform::AmpStats *Stats; // ebx
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  unsigned int mouseIdx; // [esp+18h] [ebp-58h]
  unsigned int miceProceededMask; // [esp+1Ch] [ebp-54h] BYREF
  int v17; // [esp+20h] [ebp-50h]
  bool avm2[4]; // [esp+24h] [ebp-4Ch]
  Scaleform::Render::Point<float> v19; // [esp+28h] [ebp-48h] BYREF
  Scaleform::AmpFunctionTimer v20; // [esp+30h] [ebp-40h] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo v21; // [esp+40h] [ebp-30h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v20,
    this->AdvanceStats.pObject,
    "MovieImpl::ProcessInput",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ProcessInput);
  if ( this->pMainMovie )
  {
    v2 = this->pASMovieRoot.pObject->AVMVersion == 2;
    v21.Prev_aRect.x1 = 0.0;
    MouseCursorCount = this->MouseCursorCount;
    v21.Prev_aRect.y1 = 0.0;
    v21.Prev_aRect.x2 = 0.0;
    v21.Prev_aRect.y2 = 0.0;
    v21.pFocusGroup = 0;
    v21.CurFocused.pObject = 0;
    memset(&v21.PrevKeyCode, 0, 13);
    miceProceededMask = 0;
    avm2[0] = v2;
    v21.CurFocusIdx = -1;
    v4 = (1 << MouseCursorCount) - 1;
    while ( this->InputEventsQueue.UsedEntries || this->InputEventsQueue.LastMousePosMask )
    {
      Entry = Scaleform::GFx::InputEventsQueue::GetEntry(&this->InputEventsQueue);
      if ( Entry->t == QE_Key )
      {
        Scaleform::GFx::MovieImpl::ProcessKeyboard(this, (Scaleform::Ptr<Scaleform::GFx::Sprite>)Entry, &v21);
      }
      else if ( Entry->t == QE_Mouse )
      {
        Scaleform::GFx::MovieImpl::ProcessMouse(this, Entry, &miceProceededMask, avm2[0]);
      }
    }
    if ( (this->Flags & 0x80) != 0 && (miceProceededMask & v4) != v4 )
    {
      v6 = 0.0;
      mouseIdx = 0;
      v17 = 1;
      if ( this->MouseCursorCount )
      {
        p_PrevButtonsState = &this->mMouseState[0].PrevButtonsState;
        do
        {
          if ( (miceProceededMask & v17) == 0 && (p_PrevButtonsState[6] & 0x10) != 0 )
          {
            v8 = avm2[0];
            *p_PrevButtonsState = *(p_PrevButtonsState - 1);
            v19.x = *((float *)p_PrevButtonsState + 1);
            v19.y = *((float *)p_PrevButtonsState + 2);
            TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &v19, v6, v8, 0);
            v10 = TopMostEntity;
            if ( TopMostEntity )
              ++TopMostEntity->RefCount;
            Scaleform::GFx::MouseState::SetTopmostEntity(
              (Scaleform::GFx::MouseState *)(p_PrevButtonsState - 7),
              TopMostEntity);
            Scaleform::GFx::MovieImpl::CheckMouseCursorType(this, mouseIdx, v10);
            this->pASMovieRoot.pObject->GenerateMouseEvents(this->pASMovieRoot.pObject, mouseIdx);
            if ( v10 )
              Scaleform::RefCountNTSImpl::Release(v10);
          }
          v17 *= 2;
          LODWORD(v6) = mouseIdx + 1;
          p_PrevButtonsState += 14;
          mouseIdx = LODWORD(v6);
        }
        while ( LODWORD(v6) < this->MouseCursorCount );
      }
    }
    Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(this, (Scaleform::Ptr<Scaleform::GFx::Sprite>)&v21);
    pObject = v21.CurFocused.pObject;
    this->Flags &= ~0x80u;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  Stats = v20.Stats;
  if ( v20.Stats )
  {
    p_NativePopCallstack = &v20.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v20.StartTicks),
      (ProfileTicks - v20.StartTicks) >> 32);
  }
}
