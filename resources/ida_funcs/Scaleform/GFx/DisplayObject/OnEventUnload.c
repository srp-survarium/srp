void __thiscall Scaleform::GFx::DisplayObject::OnEventUnload(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  unsigned __int8 AvmObjOffset; // al

  Scaleform::GFx::DisplayObjectBase::OnEventUnload(this);
  pObject = this->pNameHandle.pObject;
  if ( pObject )
    pObject->pCharacter = 0;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    (*(void (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + AvmObjOffset)
                                   + 40))(
      (char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
    + 4 * AvmObjOffset);
}
