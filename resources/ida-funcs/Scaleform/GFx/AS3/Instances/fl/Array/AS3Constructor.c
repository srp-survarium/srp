void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // edi
  unsigned int v5; // eax
  double v6; // st7
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v10; // [esp+14h] [ebp-18h] BYREF
  double num; // [esp+1Ch] [ebp-10h] BYREF
  double intp; // [esp+24h] [ebp-8h] BYREF

  v4 = argv;
  if ( argc == 1 && (v5 = argv->Flags & 0x1F, v5 - 2 <= 2) )
  {
    if ( v5 == 4 )
    {
      v6 = modf(argv->value.VNumber, &intp);
      if ( 0.0 != v6 )
        goto LABEL_5;
    }
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(v4, (Scaleform::GFx::AS3::CheckResult *)&argc, &num)->Result )
      return;
    v6 = num;
    if ( num < 0.0 )
    {
LABEL_5:
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v10, eArrayIndexNotIntegerError, pVM, (int)v6);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v8);
      pNode = v10.Message.pNode;
      --v10.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      argv = (Scaleform::GFx::AS3::Value *)((unsigned __int16)argc | 0xC00);
      v10 = (Scaleform::GFx::AS3::VM::Error)(__int64)num;
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, (__int64)num);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  }
}
