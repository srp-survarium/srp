char __thiscall Scaleform::GFx::InteractiveObject::IsFocusEnabled(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  int v3; // eax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 1;
  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + AvmObjOffset)
                                     + 4))(
         (char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * AvmObjOffset);
  return (*(int (__thiscall **)(int, Scaleform::GFx::FocusMovedType))(*(_DWORD *)v3 + 84))(v3, fmt);
}
