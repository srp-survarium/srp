void __thiscall Scaleform::GFx::AS3::TR::State::exec_1OpNumber(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    NotNull);
}
