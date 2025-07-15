bool __thiscall Scaleform::GFx::Button::OnMouseEvent(Scaleform::GFx::Button *this, const Scaleform::GFx::EventId *evt)
{
  unsigned __int16 Flags; // ax
  unsigned int ControllerIndex; // eax
  Scaleform::GFx::MouseState *v5; // ecx
  HINSTANCE__ *Id; // eax
  Scaleform::GFx::ButtonDef *pDef; // ecx
  unsigned int v8; // eax
  int v9; // eax
  unsigned __int8 AvmObjOffset; // al
  int v12; // eax
  bool handlerFound; // [esp+Dh] [ebp-1h]

  Flags = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x1000) != 0 || this->Depth < -1 || (Flags & 0x10) != 0 )
    return 0;
  handlerFound = 0;
  if ( !evt->RollOverCnt )
  {
    ControllerIndex = evt->ControllerIndex;
    if ( ControllerIndex < 6 )
      v5 = &this->pASRoot->pMovieImpl->mMouseState[ControllerIndex];
    else
      v5 = 0;
    Id = (HINSTANCE__ *)evt->Id;
    if ( evt->Id <= 0x1000 )
    {
      if ( evt->Id != 4096 )
      {
        if ( (unsigned int)Id > 0x400 )
        {
          if ( Id != (HINSTANCE__ *)2048 )
            goto LABEL_29;
          goto LABEL_16;
        }
        if ( Id != (HINSTANCE__ *)1024 && Id != (HINSTANCE__ *)16 )
        {
          if ( Id != (HINSTANCE__ *)32 )
            goto LABEL_29;
LABEL_16:
          this->MouseState = MouseDown;
          goto LABEL_29;
        }
LABEL_24:
        this->MouseState = MouseMove;
        goto LABEL_29;
      }
LABEL_21:
      this->MouseState = Unknown;
      goto LABEL_29;
    }
    if ( (unsigned int)Id > 0x8000 )
    {
      if ( Id == &_sbh_sizeHeaderList )
        this->MouseState = 2 * ((this->Scaleform::GFx::InteractiveObject::Flags & 0x4000) == 0);
    }
    else
    {
      if ( Id == (HINSTANCE__ *)0x8000 )
        goto LABEL_24;
      if ( Id != (HINSTANCE__ *)0x2000 )
      {
        if ( Id != (HINSTANCE__ *)0x4000 )
          goto LABEL_29;
        goto LABEL_21;
      }
      if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x4000) != 0 && (v5->PrevButtonsState & 1) != 0 )
        goto LABEL_24;
      if ( (v5->CurButtonsState & 1) != 0 )
        return 0;
      this->MouseState = MouseDown;
    }
LABEL_29:
    pDef = this->pDef;
    if ( !pDef->pSound )
    {
LABEL_41:
      Scaleform::GFx::Button::SwitchState(this);
      goto LABEL_42;
    }
    v8 = evt->Id;
    if ( evt->Id > 0x2000 )
    {
      if ( v8 == 0x4000 )
      {
        v9 = 0;
        goto LABEL_40;
      }
    }
    else
    {
      if ( evt->Id == 0x2000 )
      {
        v9 = 1;
        goto LABEL_40;
      }
      if ( v8 == 1024 )
      {
        v9 = 2;
        goto LABEL_40;
      }
      if ( v8 == 2048 )
      {
        v9 = 3;
LABEL_40:
        pDef->pSound->Play(pDef->pSound, this, v9);
        goto LABEL_41;
      }
    }
    v9 = -1;
    goto LABEL_40;
  }
LABEL_42:
  if ( ((this->pASRoot->pMovieImpl->Flags >> 28) & 3) == 1 && (evt->Id == 0x2000 || evt->Id == 0x4000) && evt->KeyCode )
    return 0;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v12 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + AvmObjOffset)
                                        + 12))(
            (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * AvmObjOffset);
    return (*(int (__thiscall **)(int, const Scaleform::GFx::EventId *))(*(_DWORD *)v12 + 96))(v12, evt);
  }
  return handlerFound;
}
