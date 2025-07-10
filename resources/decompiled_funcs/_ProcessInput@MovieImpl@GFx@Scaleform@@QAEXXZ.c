void __thiscall Scaleform::GFx::MovieImpl::ProcessInput(Scaleform::GFx::MovieImpl *this)
{
  bool v2; // zf
  unsigned int MouseCursorCount; // ecx
  int v4; // ebx
  const Scaleform::GFx::InputEventsQueueEntry *Entry; // eax
  unsigned int v6; // eax
  unsigned int *p_PrevButtonsState; // edi
  bool v8; // cl
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::InteractiveObject *v10; // ebx
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  unsigned int mouseIdx; // [esp+150h] [ebp-48h]
  unsigned int v13; // [esp+154h] [ebp-44h] BYREF
  int v14; // [esp+158h] [ebp-40h]
  bool testAll[4]; // [esp+15Ch] [ebp-3Ch]
  Scaleform::Render::Point<float> mousePos; // [esp+160h] [ebp-38h] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [esp+168h] [ebp-30h] BYREF

  if ( this->pMainMovie )
  {
    v2 = this->pASMovieRoot.pObject->AVMVersion == 2;
    pfocusInfo.Prev_aRect.x1 = 0.0;
    MouseCursorCount = this->MouseCursorCount;
    pfocusInfo.Prev_aRect.y1 = 0.0;
    pfocusInfo.Prev_aRect.x2 = 0.0;
    pfocusInfo.Prev_aRect.y2 = 0.0;
    testAll[0] = v2;
    pfocusInfo.pFocusGroup = 0;
    pfocusInfo.CurFocused.pObject = 0;
    pfocusInfo.CurFocusIdx = -1;
    memset(&pfocusInfo.PrevKeyCode, 0, 13);
    v13 = 0;
    v4 = (1 << MouseCursorCount) - 1;
    while ( this->InputEventsQueue.UsedEntries || this->InputEventsQueue.LastMousePosMask )
    {
      Entry = Scaleform::GFx::InputEventsQueue::GetEntry(&this->InputEventsQueue);
      if ( Entry->t == QE_Key )
      {
        Scaleform::GFx::MovieImpl::ProcessKeyboard(this, (Scaleform::GFx::Event::EventType)Entry, &pfocusInfo);
      }
      else if ( Entry->t == QE_Mouse )
      {
        Scaleform::GFx::MovieImpl::ProcessMouse(this, Entry, &v13, testAll[0]);
      }
    }
    if ( (this->Flags & 0x80) != 0 && (v13 & v4) != v4 )
    {
      v6 = 0;
      mouseIdx = 0;
      v14 = 1;
      if ( this->MouseCursorCount )
      {
        p_PrevButtonsState = &this->mMouseState[0].PrevButtonsState;
        do
        {
          if ( (v13 & v14) == 0 && (p_PrevButtonsState[6] & 0x10) != 0 )
          {
            v8 = testAll[0];
            *p_PrevButtonsState = *(p_PrevButtonsState - 1);
            mousePos.x = *((float *)p_PrevButtonsState + 1);
            mousePos.y = *((float *)p_PrevButtonsState + 2);
            TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &mousePos, v6, v8, 0);
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
          v14 *= 2;
          v6 = mouseIdx + 1;
          p_PrevButtonsState += 14;
          mouseIdx = v6;
        }
        while ( v6 < this->MouseCursorCount );
      }
    }
    Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(this, &pfocusInfo);
    pObject = pfocusInfo.CurFocused.pObject;
    this->Flags &= ~0x80u;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
}
