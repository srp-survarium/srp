void __thiscall Scaleform::GFx::Sprite::CloneInternalData(
        Scaleform::GFx::Sprite *this,
        const Scaleform::GFx::InteractiveObject *src)
{
  unsigned __int8 AvmObjOffset; // al
  int v4; // eax

  Scaleform::GFx::InteractiveObject::CloneInternalData(this, src);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, const Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v4 + 60))(v4, src);
  }
}
