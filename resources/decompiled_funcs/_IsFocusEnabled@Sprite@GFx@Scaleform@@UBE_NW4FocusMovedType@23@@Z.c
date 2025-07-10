char __thiscall Scaleform::GFx::Sprite::IsFocusEnabled(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 Value; // dl
  unsigned __int8 v4; // al
  int v5; // eax
  unsigned __int8 AvmObjOffset; // al
  int v7; // eax

  if ( fmt == GFx_FocusMovedByMouse )
    return Scaleform::GFx::InteractiveObject::IsFocusEnabled(this, GFx_FocusMovedByMouse);
  Value = this->FocusEnabled.Value;
  if ( Value || (v4 = this->AvmObjOffset) == 0 )
  {
    if ( Value == 2 )
    {
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + AvmObjOffset)
                                           + 4))(
               (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + 4 * AvmObjOffset);
        return (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 52))(v7);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return Value == 1;
    }
  }
  else
  {
    v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v4)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * v4);
    return (*(int (__thiscall **)(int, Scaleform::GFx::FocusMovedType))(*(_DWORD *)v5 + 84))(v5, fmt);
  }
}
