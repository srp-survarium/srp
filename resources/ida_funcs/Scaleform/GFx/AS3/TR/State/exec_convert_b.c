void __thiscall Scaleform::GFx::AS3::TR::State::exec_convert_b(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *Data; // edx
  Scaleform::GFx::AS3::Value *v2; // esi
  bool v3; // al

  Data = this->OpStack.Data.Data;
  v2 = &Data[this->OpStack.Data.Size - 1];
  if ( (v2->Flags & 0x1F) < 5 || (v2->Flags & 0x1F) == 0xA )
  {
    v3 = Scaleform::GFx::AS3::Value::Convert2Boolean(&Data[this->OpStack.Data.Size - 1]);
    Scaleform::GFx::AS3::Value::SetBool(v2, v3);
  }
  else
  {
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
      NotNull);
  }
}
