void __thiscall Scaleform::GFx::DisplayObject::OnEventLoad(Scaleform::GFx::DisplayObject *this)
{
  unsigned __int8 AvmObjOffset; // al

  this->Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    (*(void (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + AvmObjOffset)
                                   + 36))(
      (char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
    + 4 * AvmObjOffset);
}
