void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsSet(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::LogState *pObject; // esi
  Scaleform::Ptr<Scaleform::GFx::LogState> v4; // [esp+0h] [ebp-4h] BYREF

  v4.pObject = (Scaleform::GFx::LogState *)this;
  pObject = Scaleform::GFx::StateBag::GetLogState(
              (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 2,
              &v4)->pObject;
  if ( v4.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4.pObject);
  if ( pObject )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "ExternalInterface::marshallExceptions is not supported.");
}
