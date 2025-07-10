void __thiscall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsGet(
        Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this,
        bool *result)
{
  Scaleform::GFx::LogState *pObject; // esi

  *result = 0;
  pObject = Scaleform::GFx::StateBag::GetLogState(
              (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 2,
              (Scaleform::Ptr<Scaleform::GFx::LogState> *)&result)->pObject;
  if ( result )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result);
  if ( pObject )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "ExternalInterface::marshallExceptions is not supported.");
}
