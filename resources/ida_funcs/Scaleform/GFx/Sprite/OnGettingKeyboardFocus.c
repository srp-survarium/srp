void __thiscall Scaleform::GFx::Sprite::OnGettingKeyboardFocus(
        Scaleform::GFx::Sprite *this,
        char controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  int v5; // eax
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  _DWORD v7[3]; // [esp+4h] [ebp-14h] BYREF
  char v8; // [esp+10h] [ebp-8h]
  char v9; // [esp+14h] [ebp-4h]
  char v10; // [esp+15h] [ebp-3h]
  char v11; // [esp+16h] [ebp-2h]
  char v12; // [esp+17h] [ebp-1h]

  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + AvmObjOffset)
                                         + 4))(
             (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 52))(v5) )
      {
        if ( ((this->pASRoot->pMovieImpl->Flags >> 28) & 3) != 1 )
        {
          OnMouseEvent = this->OnMouseEvent;
          v10 = controllerIdx;
          v7[0] = 0x2000;
          v7[1] = 0;
          v7[2] = 0;
          v8 = 0;
          v9 = 0;
          v11 = 0;
          v12 = 0;
          OnMouseEvent(this, (const Scaleform::GFx::EventId *)v7);
        }
      }
    }
  }
}
