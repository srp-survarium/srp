char __thiscall Scaleform::GFx::Button::OnKeyEvent(
        Scaleform::GFx::Button *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  unsigned __int8 AvmObjOffset; // al
  int v5; // eax
  char AsciiCode; // al
  unsigned int WcharCode; // ecx
  unsigned int KeyCode; // ecx
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebp
  unsigned int v11; // eax
  bool (__thiscall *v12)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  bool (__thiscall *v13)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  int v15; // [esp+2Ch] [ebp-14h] BYREF
  int v16; // [esp+30h] [ebp-10h]
  int v17; // [esp+34h] [ebp-Ch]
  char v18; // [esp+38h] [ebp-8h]
  char v19; // [esp+3Ch] [ebp-4h]
  char ControllerIndex; // [esp+3Dh] [ebp-3h]
  char v21; // [esp+3Eh] [ebp-2h]
  char v22; // [esp+3Fh] [ebp-1h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 12))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, const Scaleform::GFx::EventId *, int *))(*(_DWORD *)v5 + 100))(v5, id, pkeyMask);
  }
  if ( id->Id == 64 )
  {
    if ( ((unsigned int)&_sbh_sizeHeaderList & *pkeyMask) == 0 )
    {
      AsciiCode = id->AsciiCode;
      if ( !AsciiCode )
      {
        WcharCode = id->WcharCode;
        if ( WcharCode < 0x20 || WcharCode >= 0x80 )
        {
          if ( id->KeyCode >= 0x20 )
            AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(id);
        }
        else
        {
          AsciiCode = id->WcharCode;
        }
      }
      KeyCode = id->KeyCode;
      OnMouseEvent = this->OnMouseEvent;
      v18 = AsciiCode;
      v17 = KeyCode;
      v15 = (int)&loc_20000;
      v16 = 0;
      v19 = 0;
      v21 = 0;
      v22 = 0;
      ControllerIndex = 0;
      if ( OnMouseEvent(this, (const Scaleform::GFx::EventId *)&v15) )
        *pkeyMask |= (unsigned int)&_sbh_sizeHeaderList;
    }
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(
           pMovieImpl,
           (Scaleform::GFx::Sprite *)this,
           (Scaleform::Ptr<Scaleform::GFx::Sprite>)id->ControllerIndex) )
    {
      v11 = id->KeyCode;
      if ( (v11 == 13 || v11 == 32) && (this->IsFocusRectEnabled(this) || ((pMovieImpl->Flags >> 26) & 3) == 1) )
      {
        v12 = this->OnMouseEvent;
        ControllerIndex = id->ControllerIndex;
        v15 = 1024;
        v16 = 0;
        v17 = 13;
        v18 = 0;
        v19 = 0;
        v21 = 0;
        v22 = 0;
        v12(this, (const Scaleform::GFx::EventId *)&v15);
        ++this->RefCount;
        ((void (__thiscall *)(Scaleform::GFx::MovieImpl *, _DWORD, _DWORD, int))pMovieImpl->Advance)(
          pMovieImpl,
          0.0,
          0,
          1);
        v13 = this->OnMouseEvent;
        ControllerIndex = id->ControllerIndex;
        v15 = 2048;
        v16 = 0;
        v17 = 13;
        v18 = 0;
        v19 = 0;
        v21 = 0;
        v22 = 0;
        v13(this, (const Scaleform::GFx::EventId *)&v15);
        Scaleform::RefCountNTSImpl::Release(this);
      }
    }
  }
  return 1;
}
