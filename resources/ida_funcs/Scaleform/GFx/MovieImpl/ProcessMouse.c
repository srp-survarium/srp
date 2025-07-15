void __thiscall Scaleform::GFx::MovieImpl::ProcessMouse(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InputEventsQueueEntry *qe,
        unsigned int *miceProceededMask,
        bool avm2)
{
  unsigned int MouseIndex; // ebx
  Scaleform::GFx::InteractiveObject *TopMostEntity; // eax
  Scaleform::GFx::AS3::Value *v8; // ebx
  Scaleform::GFx::State *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *v10; // esi
  int v11; // ebx
  bool v12; // al
  unsigned int Size; // eax
  Scaleform::GFx::InteractiveObject *pObject; // esi
  Scaleform::GFx::InteractiveObject_vtbl *v15; // eax
  void (__thiscall *PropagateMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::InteractiveObject_vtbl *v17; // eax
  void (__thiscall *v18)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  unsigned int v19; // ebx
  unsigned int v20; // ebx
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_LastFocused; // ebp
  Scaleform::WeakPtrProxy *v22; // eax
  Scaleform::RefCountNTSImpl *v23; // esi
  Scaleform::RefCountNTSImpl *v25; // ebp
  unsigned int movieIndex; // [esp+10h] [ebp-20h]
  unsigned int movieIndexa; // [esp+10h] [ebp-20h]
  Scaleform::Render::Point<float> mousePos; // [esp+14h] [ebp-1Ch] BYREF
  int v30; // [esp+1Ch] [ebp-14h] BYREF
  int v31; // [esp+20h] [ebp-10h]
  int v32; // [esp+24h] [ebp-Ch]
  int v33; // [esp+28h] [ebp-8h]
  char v34; // [esp+2Ch] [ebp-4h]
  __int16 v35; // [esp+2Dh] [ebp-3h]
  char v36; // [esp+2Fh] [ebp-1h]
  unsigned int mi; // [esp+34h] [ebp+4h]
  unsigned int *miceProceededMaska; // [esp+38h] [ebp+8h]
  Scaleform::GFx::Sprite *avm2a; // [esp+3Ch] [ebp+Ch]

  *miceProceededMask |= 1 << qe->u.mouseEntry.MouseIndex;
  MouseIndex = qe->u.mouseEntry.MouseIndex;
  miceProceededMaska = (unsigned int *)((char *)this + 56 * MouseIndex);
  mi = MouseIndex;
  Scaleform::GFx::MouseState::UpdateState((Scaleform::GFx::MouseState *)(miceProceededMaska + 1147), qe);
  mousePos.x = qe->u.mouseEntry.PosX;
  mousePos.y = qe->u.mouseEntry.PosY;
  TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this, &mousePos, MouseIndex, avm2, 0);
  v8 = (Scaleform::GFx::AS3::Value *)TopMostEntity;
  avm2a = (Scaleform::GFx::Sprite *)TopMostEntity;
  if ( TopMostEntity )
    ++TopMostEntity->RefCount;
  Scaleform::GFx::MouseState::SetTopmostEntity((Scaleform::GFx::MouseState *)(miceProceededMaska + 1147), TopMostEntity);
  movieIndex = miceProceededMaska[1153];
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
          Scaleform::GFx::AS3::MovieRoot::PrintObjectsReport(v10, (Scaleform::GFx::AS3::Value *)this, movieIndex, v8);
        else
          Scaleform::GFx::IMEManagerBase::OnMouseDown(
            (Scaleform::GFx::IMEManagerBase *)v10,
            this,
            movieIndex,
            (Scaleform::GFx::InteractiveObject *)v8);
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
  for ( movieIndexa = Size; movieIndexa; --movieIndexa )
  {
    pObject = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
    if ( v11 )
    {
      v31 = 0;
      v32 = 0;
      v36 = 0;
      LOBYTE(v33) = 0;
      v34 = 0;
      v15 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
      v35 = (unsigned __int8)mi;
      PropagateMouseEvent = v15->PropagateMouseEvent;
      v30 = v11;
      PropagateMouseEvent(pObject, (const Scaleform::GFx::EventId *)&v30);
    }
    if ( (miceProceededMaska[1160] & 8) != 0 )
    {
      v31 = 0;
      v32 = 0;
      v17 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
      v35 = (unsigned __int8)mi;
      v18 = v17->PropagateMouseEvent;
      v30 = 8;
      v36 = 0;
      LOBYTE(v33) = 0;
      v34 = 0;
      v18(pObject, (const Scaleform::GFx::EventId *)&v30);
    }
    Size = movieIndexa - 1;
  }
  if ( ((this->Flags & 0x10000) != 0 || !qe->u.mouseEntry.ButtonsState)
    && (((this->Flags >> 22) & 3) == 1 || (miceProceededMaska[1160] & 8) == 0) )
  {
    v19 = mi;
  }
  else
  {
    v19 = mi;
    Scaleform::GFx::MovieImpl::HideFocusRect(this, mi);
  }
  if ( (qe->u.mouseEntry.Flags & 0x20) != 0 && avm2a )
    avm2a->OnMouseWheelEvent(avm2a, qe->u.mouseEntry.WheelScrollDelta);
  this->pASMovieRoot.pObject->NotifyMouseEvent(
    this->pASMovieRoot.pObject,
    qe,
    (const Scaleform::GFx::MouseState *)(miceProceededMaska + 1147),
    v19);
  if ( Scaleform::GFx::MouseState::IsTopmostEntityChanged((Scaleform::GFx::MouseState *)(miceProceededMaska + 1147)) )
  {
    v20 = 0;
    if ( avm2a )
      v20 = avm2a->GetCursorType(avm2a);
    if ( miceProceededMaska[1158] != v20 )
      this->pASMovieRoot.pObject->ChangeMouseCursorType(this->pASMovieRoot.pObject, mi, v20);
    if ( miceProceededMaska[1157] != -1 )
      v20 = miceProceededMaska[1157];
    miceProceededMaska[1158] = v20;
    v19 = mi;
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
    v25 = avm2a;
    if ( avm2a != v23 )
      Scaleform::GFx::MovieImpl::QueueSetFocusTo(this, avm2a, avm2a, v19, GFx_FocusMovedByMouse, 0);
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
  else
  {
    v25 = avm2a;
  }
  this->pASMovieRoot.pObject->GenerateMouseEvents(this->pASMovieRoot.pObject, v19);
  if ( v25 )
    Scaleform::RefCountNTSImpl::Release(v25);
}
