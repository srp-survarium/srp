void __thiscall Scaleform::GFx::AS3::TR::State::exec_convert_u(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v1; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-5h] BYREF
  unsigned int v; // [esp+8h] [ebp-4h] BYREF

  v1 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( (v1->Flags & 0x1F) < 5 || (v1->Flags & 0x1F) == 0xA )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(v1, &result, (Scaleform::GFx::AS3::Value::V1U *)&v)->Result )
      Scaleform::GFx::AS3::Value::SetUInt32(v1, v);
  }
  else
  {
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject,
      NotNull);
  }
}
