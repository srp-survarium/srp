const char *__thiscall Scaleform::GFx::DisplayObject::GetAbsolutePath(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::String *ppath)
{
  unsigned __int8 AvmObjOffset; // al

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (const char *)(*(int (__thiscall **)(char *, Scaleform::String *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                              + AvmObjOffset)
                                                                            + 24))(
                           (char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                         + 4 * AvmObjOffset,
                           ppath);
  else
    return uri;
}
