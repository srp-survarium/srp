bool __thiscall Scaleform::GFx::TextField::HasStyleSheet(Scaleform::GFx::TextField *this)
{
  unsigned __int8 AvmObjOffset; // al
  int v2; // eax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v2 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + AvmObjOffset)
                                     + 16))(
         (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * AvmObjOffset);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 96))(v2);
}
