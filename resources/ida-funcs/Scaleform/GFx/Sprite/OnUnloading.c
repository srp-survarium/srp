char __thiscall Scaleform::GFx::Sprite::OnUnloading(Scaleform::GFx::Sprite *this)
{
  char result; // al
  unsigned __int8 AvmObjOffset; // cl
  char v4; // [esp+4h] [ebp-4h]

  result = Scaleform::GFx::DisplayList::UnloadAll(&this->mDisplayList, this);
  AvmObjOffset = this->AvmObjOffset;
  v4 = result;
  if ( AvmObjOffset )
    return (*(int (__thiscall **)(char *, char))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + AvmObjOffset)
                                               + 44))(
             (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * AvmObjOffset,
             v4);
  return result;
}
