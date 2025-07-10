Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayList *p_LastHitTestY; // edi
  signed int DisplayIndex; // eax
  Scaleform::GFx::InteractiveObject *v5; // edi
  unsigned int v6; // ecx
  int v7; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v8; // ecx
  void (__thiscall *SetAcceptAnimMoves)(Scaleform::GFx::DisplayObjectBase *, bool); // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v10; // ecx

  if ( ch )
    ++ch->RefCount;
  if ( (ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 )
    Scaleform::GFx::DisplayObject::SetMask(ch, 0);
  if ( (ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(this->pDispObj->pASRoot->pMovieImpl, ch);
  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&this->pDispObj[1].LastHitTestY;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(p_LastHitTestY, ch);
  if ( DisplayIndex < 0 )
  {
    Scaleform::RefCountNTSImpl::Release(ch);
    return 0;
  }
  else
  {
    Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_LastHitTestY, this->pDispObj, DisplayIndex);
    p_LastHitTestY->Flags |= 3u;
    v5 = (unsigned __int8)ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags >> 7 != 0 ? ch : 0;
    if ( ((ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0
        ? (unsigned int)ch
        : 0) != 0 )
      v6 = ((ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0
          ? (unsigned int)ch
          : 0)
         + 4
         * *((ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0
           ? &ch->AvmObjOffset
           : (unsigned __int8 *)65);
    else
      v6 = 0;
    (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)v6 + 56))(v6, 0);
    ch->pParent = 0;
    if ( v5 && Scaleform::GFx::InteractiveObject::IsInPlayList(v5) )
    {
      v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + v5->AvmObjOffset)
                                      + 4))((int)v5 + 4 * v5->AvmObjOffset);
      if ( v7 )
        v8 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v7 - 28);
      else
        v8 = 0;
      Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v8);
    }
    if ( (ch->Scaleform::GFx::DisplayObject::Flags & 1) != 0 )
    {
      SetAcceptAnimMoves = ch->SetAcceptAnimMoves;
      ch->Scaleform::GFx::DisplayObject::Flags &= ~1u;
      SetAcceptAnimMoves(ch, 0);
      v10 = (Scaleform::GFx::AS3::AvmDisplayObj *)(&ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + ch->AvmObjOffset);
      ch->CreateFrame = 0;
      ch->Depth = -1;
      Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(v10);
    }
    Scaleform::RefCountNTSImpl::Release(ch);
    return ch;
  }
}
