Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::Environment::GetAvmTarget(
        Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::InteractiveObject *result; // eax

  result = this->Target;
  if ( result )
    return (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(char *))(*((_DWORD *)&result->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                + result->AvmObjOffset)
                                                                              + 4))(
                                                  (char *)&result->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                + 4 * result->AvmObjOffset);
  return result;
}
