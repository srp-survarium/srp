void __thiscall Scaleform::GFx::AS3::TR::State::exec_convert_d(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v1; // edx
  Scaleform::GFx::AS3::CheckResult result; // [esp+1h] [ebp-1h] BYREF

  result.Result = HIBYTE(this);
  v1 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( (v1->Flags & 0x1F) < 5 || (v1->Flags & 0x1F) == 0xA )
    Scaleform::GFx::AS3::Value::ToNumberValue(v1, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
      NotNull);
}
