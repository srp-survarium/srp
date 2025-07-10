void __thiscall Scaleform::GFx::DisplayObjContainer::FillTabableArray(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  unsigned __int8 AvmObjOffset; // al
  int v3; // eax

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 20))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject::FillTabableParams *))(*(_DWORD *)v3 + 92))(
      v3,
      params);
  }
}
