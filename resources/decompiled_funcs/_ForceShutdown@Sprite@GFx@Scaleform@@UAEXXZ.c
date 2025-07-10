void __thiscall Scaleform::GFx::Sprite::ForceShutdown(Scaleform::GFx::Sprite *this)
{
  unsigned __int8 AvmObjOffset; // al
  int v3; // eax

  Scaleform::GFx::DisplayObjContainer::ForceShutdown(this);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 116))(v3);
  }
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
}
