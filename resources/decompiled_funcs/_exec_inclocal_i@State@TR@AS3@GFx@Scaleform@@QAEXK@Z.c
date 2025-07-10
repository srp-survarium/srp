void __thiscall Scaleform::GFx::AS3::TR::State::exec_inclocal_i(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
    op_inclocal_ti,
    v);
}
