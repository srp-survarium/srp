void __thiscall Scaleform::GFx::AS3::TR::State::exec_declocal_i(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
    op_declocal_ti,
    v);
}
