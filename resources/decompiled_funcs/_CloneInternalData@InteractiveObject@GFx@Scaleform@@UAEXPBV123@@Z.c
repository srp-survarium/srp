void __thiscall Scaleform::GFx::InteractiveObject::CloneInternalData(
        Scaleform::GFx::InteractiveObject *this,
        const Scaleform::GFx::InteractiveObject *src)
{
  unsigned __int8 AvmObjOffset; // al
  int v4; // eax

  if ( src->pGeomData )
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, src->pGeomData);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v4 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 4))(
           (char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, const Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v4 + 60))(v4, src);
  }
}
