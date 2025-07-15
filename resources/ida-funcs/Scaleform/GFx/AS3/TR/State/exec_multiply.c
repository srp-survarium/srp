void __thiscall Scaleform::GFx::AS3::TR::State::exec_multiply(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_multiply_td);
}
