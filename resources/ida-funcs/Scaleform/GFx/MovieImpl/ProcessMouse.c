void __thiscall Scaleform::GFx::MovieImpl::ProcessMouse(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InputEventsQueueEntry *qe,
        unsigned int *miceProceededMask,
        bool avm2)
{
  float v6; // ebx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::AS3::Value *v8; // ebx
  Scaleform::GFx::State *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v10; // edi
  int v11; // ebx
  bool v12; // al
  unsigned int Size; // eax
  Scaleform::GFx::InteractiveObject *pObject; // edi
  Scaleform::GFx::InteractiveObject_vtbl *v15; // eax
  void (__thiscall *PropagateMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::InteractiveObject_vtbl *v17; // eax
  void (__thiscall *v18)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned int v19; // ebx
  unsigned int v20; // ebx
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // ebp
  Scaleform::WeakPtrProxy *v22; // eax
  Scaleform::RefCountNTSImpl *v23; // edi
  Scaleform::RefCountNTSImpl *v25; // ebp
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  int buttonsState; // [esp+20h] [ebp-30h]
  int buttonsStatea; // [esp+20h] [ebp-30h]
  Scaleform::Render::Point<float> v32; // [esp+24h] [ebp-2Ch] BYREF
  Scaleform::AmpFunctionTimer v33; // [esp+2Ch] [ebp-24h] BYREF
  int v34; // [esp+3Ch] [ebp-14h] BYREF
  int v35; // [esp+40h] [ebp-10h]
  int v36; // [esp+44h] [ebp-Ch]
  int v37; // [esp+48h] [ebp-8h]
  char v38; // [esp+4Ch] [ebp-4h]
  __int16 v39; // [esp+4Dh] [ebp-3h]
  char v40; // [esp+4Fh] [ebp-1h]
  Scaleform::GFx::InputEventsQueueEntry *qea; // [esp+54h] [ebp+4h]
  char *v42; // [esp+58h] [ebp+8h]
  Scaleform::GFx::Sprite *v43; // [esp+5Ch] [ebp+Ch]

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v33,
    this->AdvanceStats.pObject,
    "MovieImpl::ProcessMouse",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ProcessMouse);
  *miceProceededMask |= 1 << qe->u.mouseEntry.MouseIndex;
  LODWORD(v6) = qe->u.mouseEntry.MouseIndex;
  v42 = (char *)this + 56 * LODWORD(v6);
  qea = (Scaleform::GFx::InputEventsQueueEntry *)LODWORD(v6);
  Scaleform::GFx::MouseState::UpdateState((Scaleform::GFx::MouseState *)(v42 + 4588), qe);
  v32.x = qe->u.mouseEntry.PosX;
  v32.y = qe->u.mouseEntry.PosY;
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &v32, v6, avm2, 0);
  v8 = (Scaleform::GFx::AS3::Value *)TopMostEntity;
  v43 = (Scaleform::GFx::Sprite *)TopMostEntity;
  if ( TopMostEntity )
    ++TopMostEntity->RefCount;
  Scaleform::GFx::MouseState::SetTopmostEntity((Scaleform::GFx::MouseState *)(v42 + 4588), TopMostEntity);
  buttonsState = *((_DWORD *)v42 + 1153);
  if ( qe->u.mouseEntry.ButtonsState )
  {
    v9 = this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 24);
    v10 = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)v9;
    if ( v9 )
    {
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::State *, Scaleform::GFx::MovieImpl *))v9->__vftable[30].~Scaleform::GFx::State)(
             v9,
             this) )
      {
        if ( (qe->u.mouseEntry.Flags & 0xC0) != 0 || !qe->u.mouseEntry.ButtonsState )
          Scaleform::DefaultAmpServer::AddSourceFile(v10, (Scaleform::GFx::AS3::Value *)this, buttonsState, v8);
        else
          Scaleform::GFx::IMEManagerBase::OnMouseDown(
            (Scaleform::GFx::IMEManagerBase *)v10,
            this,
            buttonsState,
            (Scaleform::GFx::TextField *)v8);
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    }
  }
  v11 = 0;
  if ( qe->u.mouseEntry.ButtonsState && (qe->u.keyEntry.AsciiCode & 1) != 0 )
  {
    v12 = (qe->u.mouseEntry.Flags & 0xC0) == 0 && qe->u.mouseEntry.ButtonsState;
    v11 = v12 ? 16 : 32;
  }
  Size = this->MovieLevels.Data.Size;
  buttonsStatea = Size;
  if ( Size )
  {
    do
    {
      pObject = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
      if ( v11 )
      {
        v35 = 0;
        v36 = 0;
        v40 = 0;
        LOBYTE(v37) = 0;
        v38 = 0;
        v15 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
        v39 = (unsigned __int8)qea;
        PropagateMouseEvent = v15->PropagateMouseEvent;
        v34 = v11;
        PropagateMouseEvent(pObject, (const Scaleform::GFx::EventId *)&v34);
      }
      if ( (v42[4640] & 8) != 0 )
      {
        v35 = 0;
        v36 = 0;
        v17 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
        v39 = (unsigned __int8)qea;
        v18 = v17->PropagateMouseEvent;
        v34 = 8;
        v40 = 0;
        LOBYTE(v37) = 0;
        v38 = 0;
        v18(pObject, (const Scaleform::GFx::EventId *)&v34);
      }
      Size = --buttonsStatea;
    }
    while ( buttonsStatea );
  }
  if ( ((this->Flags & 0x10000) != 0 || !qe->u.mouseEntry.ButtonsState)
    && (((this->Flags >> 22) & 3) == 1 || (v42[4640] & 8) == 0) )
  {
    v19 = (unsigned int)qea;
  }
  else
  {
    v19 = (unsigned int)qea;
    Scaleform::GFx::MovieImpl::HideFocusRect(this, (Scaleform::Ptr<Scaleform::GFx::Sprite>)qea);
  }
  if ( (qe->u.mouseEntry.Flags & 0x20) != 0 && v43 )
    v43->OnMouseWheelEvent(v43, qe->u.mouseEntry.WheelScrollDelta);
  this->pASMovieRoot.pObject->NotifyMouseEvent(
    this->pASMovieRoot.pObject,
    qe,
    (const Scaleform::GFx::MouseState *)(v42 + 4588),
    v19);
  if ( Scaleform::GFx::MouseState::IsTopmostEntityChanged((Scaleform::GFx::MouseState *)(v42 + 4588)) )
  {
    v20 = 0;
    if ( v43 )
      v20 = v43->GetCursorType(v43);
    if ( *((_DWORD *)v42 + 1158) != v20 )
      this->pASMovieRoot.pObject->ChangeMouseCursorType(this->pASMovieRoot.pObject, (unsigned int)qea, v20);
    if ( *((_DWORD *)v42 + 1157) != -1 )
      v20 = *((_DWORD *)v42 + 1157);
    *((_DWORD *)v42 + 1158) = v20;
    v19 = (unsigned int)qea;
  }
  if ( (qe->u.mouseEntry.Flags & 0xC0) == 0 && qe->u.mouseEntry.ButtonsState && (qe->u.keyEntry.AsciiCode & 1) != 0 )
  {
    p_LastFocused = &this->FocusGroups[this->FocusGroupIndexes[v19]].LastFocused;
    v22 = p_LastFocused->pProxy.pObject;
    v23 = 0;
    if ( p_LastFocused->pProxy.pObject )
    {
      if ( v22->pObject )
      {
        v23 = v22->pObject;
        if ( v23->RefCount )
        {
          ++v23->RefCount;
          ++v23->RefCount;
          Scaleform::RefCountNTSImpl::Release(v23);
        }
        else
        {
          v23 = 0;
        }
      }
      else
      {
        if ( v22->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
        p_LastFocused->pProxy.pObject = 0;
      }
    }
    v25 = v43;
    if ( v43 != v23 )
      Scaleform::GFx::MovieImpl::QueueSetFocusTo(this, v43, v43, v19, GFx_FocusMovedByMouse, 0);
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
  else
  {
    v25 = v43;
  }
  this->pASMovieRoot.pObject->GenerateMouseEvents(this->pASMovieRoot.pObject, v19);
  if ( v25 )
    Scaleform::RefCountNTSImpl::Release(v25);
  Stats = v33.Stats;
  if ( v33.Stats )
  {
    p_NativePopCallstack = &v33.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v33.StartTicks),
      (ProfileTicks - v33.StartTicks) >> 32);
  }
}
