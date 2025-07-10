bool __thiscall Scaleform::GFx::DisplayObject::OnEvent(
        Scaleform::GFx::DisplayObject *this,
        const Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (*(int (__thiscall **)(char *, const Scaleform::GFx::EventId *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                            + AvmObjOffset)
                                                                          + 32))(
             (char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset,
             id);
  else
    return 0;
}
