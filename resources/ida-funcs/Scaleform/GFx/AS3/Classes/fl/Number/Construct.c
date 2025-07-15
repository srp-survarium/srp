void __thiscall Scaleform::GFx::AS3::Classes::fl::Number::Construct(
        Scaleform::GFx::AS3::Classes::fl::Number *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  unsigned int Flags; // edx
  Scaleform::GFx::ASStringNode *v7; // ecx
  unsigned __int64 v8; // rax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::StringDataPtr v11; // [esp-Ch] [ebp-20h]
  long double v; // [esp+Ch] [ebp-8h] BYREF

  if ( argc )
  {
    if ( argc == 1 )
    {
      if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v)->Result )
        Scaleform::GFx::AS3::Value::SetNumber(result, v);
    }
    else
    {
      v11.pStr = "Number::Construct";
      v11.Size = 17;
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&v,
        eWrongArgumentCountError,
        this->pTraits.pObject->pVM,
        v11,
        0,
        1,
        argc);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v9);
      v10 = (Scaleform::GFx::ASStringNode *)HIDWORD(v);
      --*(_DWORD *)(HIDWORD(v) + 12);
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    Flags = result->Flags;
    v = 0.0;
    v8 = __PAIR64__(Flags & 0xFFFFFFE4, LODWORD(v)) | 0x400000000LL;
    v7 = (Scaleform::GFx::ASStringNode *)HIDWORD(v);
    result->Flags = HIDWORD(v8);
    result->value.VS._1.VInt = v8;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v7;
  }
}
