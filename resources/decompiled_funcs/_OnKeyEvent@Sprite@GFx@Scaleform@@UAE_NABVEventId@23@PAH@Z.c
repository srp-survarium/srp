char __thiscall Scaleform::GFx::Sprite::OnKeyEvent(
        Scaleform::GFx::Sprite *this,
        const Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  unsigned __int8 AvmObjOffset; // al
  int v6; // edx
  Scaleform::GFx::Sprite_vtbl **v7; // ecx
  int (__thiscall *v8)(Scaleform::GFx::Sprite_vtbl **); // eax
  int v10; // eax
  int v11; // ebp
  int v12; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int KeyCode; // eax
  unsigned int v15; // eax
  unsigned int WcharCode; // edx
  unsigned int TouchID; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  Scaleform::GFx::Sprite_vtbl **v21; // ecx
  int v22; // eax
  int v23; // eax
  Scaleform::GFx::EventId e; // [esp+Ch] [ebp-14h] BYREF
  char rv; // [esp+24h] [ebp+4h]

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v6 = *((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + AvmObjOffset);
  v7 = &this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
     + AvmObjOffset;
  v8 = *(int (__thiscall **)(Scaleform::GFx::Sprite_vtbl **))(v6 + 8);
  if ( id->Id == 64 )
  {
    v10 = v8(v7);
    rv = (*(int (__thiscall **)(int, const Scaleform::GFx::EventId *))(*(_DWORD *)v10 + 32))(v10, id);
    if ( ((unsigned int)&_sbh_sizeHeaderList & *pkeyMask) == 0 )
    {
      v11 = Scaleform::GFx::EventId::ConvertToButtonKeyCode(id);
      if ( v11 )
      {
        v12 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + this->AvmObjOffset)
                                            + 8))(
                (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 4 * this->AvmObjOffset);
        e.KeyCode = (__int16)v11;
        e.Id = (unsigned int)&loc_20000;
        e.WcharCode = 0;
        e.AsciiCode = 0;
        e.RollOverCnt = 0;
        e.KeysState.States = 0;
        e.MouseWheelDelta = 0;
        e.ControllerIndex = 0;
        rv = (*(int (__thiscall **)(int, Scaleform::GFx::EventId *))(*(_DWORD *)v12 + 32))(v12, &e);
        if ( rv )
          *pkeyMask |= (unsigned int)&_sbh_sizeHeaderList;
      }
    }
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(pMovieImpl, this, id->ControllerIndex) )
    {
      KeyCode = id->KeyCode;
      if ( (KeyCode == 13 || KeyCode == 32) && (this->IsFocusRectEnabled(this) || ((pMovieImpl->Flags >> 26) & 3) == 1) )
      {
        v15 = id->KeyCode;
        WcharCode = id->WcharCode;
        e.Id = id->Id;
        TouchID = id->TouchID;
        e.KeyCode = v15;
        v18 = this->AvmObjOffset;
        e.WcharCode = WcharCode;
        v19 = *(_DWORD *)&id->RollOverCnt;
        e.TouchID = TouchID;
        *(_DWORD *)&e.RollOverCnt = v19;
        e.Id = 1024;
        v20 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + v18)
                                            + 8))(
                (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 4 * v18);
        (*(void (__thiscall **)(int, Scaleform::GFx::EventId *))(*(_DWORD *)v20 + 32))(v20, &e);
        v21 = &this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + this->AvmObjOffset;
        e.Id = 2048;
        v22 = (int)(*v21)->GetMatrix((Scaleform::GFx::DisplayObjectBase *)v21);
        (*(void (__thiscall **)(int, Scaleform::GFx::EventId *))(*(_DWORD *)v22 + 32))(v22, &e);
      }
    }
    return rv;
  }
  else
  {
    v23 = v8(v7);
    return (*(int (__thiscall **)(int, const Scaleform::GFx::EventId *))(*(_DWORD *)v23 + 32))(v23, id);
  }
}
