bool __thiscall Scaleform::GFx::Sprite::OnEvent(Scaleform::GFx::Sprite *this, const Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al
  int v3; // eax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + AvmObjOffset)
                                     + 8))(
         (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * AvmObjOffset);
  return (*(int (__thiscall **)(int, const Scaleform::GFx::EventId *))(*(_DWORD *)v3 + 32))(v3, id);
}
