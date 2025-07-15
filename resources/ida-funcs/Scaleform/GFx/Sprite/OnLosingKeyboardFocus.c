char __thiscall Scaleform::GFx::Sprite::OnLosingKeyboardFocus(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::InteractiveObject *__formal,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  _DWORD v10[3]; // [esp+4h] [ebp-14h] BYREF
  char v11; // [esp+10h] [ebp-8h]
  char v12; // [esp+14h] [ebp-4h]
  char v13; // [esp+15h] [ebp-3h]
  char v14; // [esp+16h] [ebp-2h]
  char v15; // [esp+17h] [ebp-1h]

  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + AvmObjOffset)
                                         + 4))(
             (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 52))(v6) )
      {
        pMovieImpl = this->pASRoot->pMovieImpl;
        if ( pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[controllerIdx]].FocusRectShown
          && ((pMovieImpl->Flags >> 28) & 3) != 1 )
        {
          OnMouseEvent = this->OnMouseEvent;
          v13 = controllerIdx;
          v10[0] = 0x4000;
          v10[1] = 0;
          v10[2] = 0;
          v11 = 0;
          v12 = 0;
          v14 = 0;
          v15 = 0;
          OnMouseEvent(this, (const Scaleform::GFx::EventId *)v10);
        }
      }
    }
  }
  return 1;
}
