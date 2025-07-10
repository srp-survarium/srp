void __thiscall Scaleform::GFx::AS3::Classes::fl::Number::Construct(
        Scaleform::GFx::AS3::Classes::fl::Number *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  unsigned int Flags; // edx
  Scaleform::GFx::ASStringNode *v6; // ecx
  unsigned __int64 v7; // rax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
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
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v, eWrongArgumentCountError, pVM);
      Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v9);
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
    v7 = __PAIR64__(Flags & 0xFFFFFFE4, LODWORD(v)) | 0x400000000LL;
    v6 = (Scaleform::GFx::ASStringNode *)HIDWORD(v);
    result->Flags = HIDWORD(v7);
    result->value.VS._1.VInt = v7;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v6;
  }
}
