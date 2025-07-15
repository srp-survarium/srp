bool __thiscall Scaleform::GFx::Sprite::OnUnloading(Scaleform::GFx::Sprite *this)
{
  bool result; // al
  unsigned __int8 AvmObjOffset; // cl
  bool mayRemove; // [esp+4h] [ebp-4h]

  result = Scaleform::GFx::DisplayList::UnloadAll(&this->mDisplayList, this);
  AvmObjOffset = this->AvmObjOffset;
  mayRemove = result;
  if ( AvmObjOffset )
    return (*(int (__thiscall **)(char *, bool))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + AvmObjOffset)
                                               + 44))(
             (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset,
             mayRemove);
  return result;
}
