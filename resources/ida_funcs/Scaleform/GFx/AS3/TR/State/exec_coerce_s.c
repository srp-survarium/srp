void __thiscall Scaleform::GFx::AS3::TR::State::exec_coerce_s(Scaleform::GFx::AS3::TR::State *this)
{
  if ( (this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags & 0x1F) != 0xA )
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
      NullOrNot);
}
