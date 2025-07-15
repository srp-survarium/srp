char __thiscall Scaleform::GFx::TextField::OnKeyEvent(
        Scaleform::GFx::TextField *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  const Scaleform::GFx::EventId *v6; // ebx
  unsigned int ControllerIndex; // edx
  int *v8; // ebp
  int v9; // edi
  unsigned __int8 AvmObjOffset; // al
  int v11; // eax
  int KeyCode; // ecx
  bool IsOverwriteMode; // al
  int v14; // ecx

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  pMovieImpl = this->pASRoot->pMovieImpl;
  v6 = id;
  ControllerIndex = id->ControllerIndex;
  v8 = pkeyMask;
  v9 = 1 << pMovieImpl->FocusGroupIndexes[ControllerIndex];
  if ( (*(_WORD *)pkeyMask & (unsigned __int16)v9) != 0
    || !pMovieImpl
    || !Scaleform::GFx::MovieImpl::IsFocused(pMovieImpl, this, ControllerIndex) )
  {
    return 0;
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v11 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + AvmObjOffset)
                                        + 16))(
            (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, const Scaleform::GFx::EventId *, int *))(*(_DWORD *)v11 + 76))(v11, v6, v8);
  }
  if ( this->pDocument.pObject->pEditorKit.pObject
    && (!(unsigned __int8)Scaleform::GFx::TextField::IsReadOnly(this) || Scaleform::GFx::TextField::IsSelectable(this)) )
  {
    if ( v6->Id == 64 )
    {
      KeyCode = v6->KeyCode;
      LOBYTE(id) = v6->KeysState.States | 0x80;
      Scaleform::GFx::Text::EditorKit::OnKeyDown(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        KeyCode,
        (const Scaleform::KeyModifiers *)&id);
      if ( v6->KeyCode == 45 )
      {
        IsOverwriteMode = Scaleform::GFx::TextField::IsOverwriteMode(this);
        Scaleform::GFx::TextField::SetOverwriteMode(this, !IsOverwriteMode);
        *v8 |= (unsigned __int16)v9;
        return 1;
      }
    }
    else if ( v6->Id == 128 )
    {
      v14 = v6->KeyCode;
      LOBYTE(id) = v6->KeysState.States | 0x80;
      Scaleform::GFx::Text::EditorKit::OnKeyUp(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        v14,
        (const Scaleform::KeyModifiers *)&id);
    }
  }
  *v8 |= (unsigned __int16)v9;
  return 1;
}
