void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // edi
  unsigned int v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+14h] [ebp-18h] BYREF
  double num; // [esp+1Ch] [ebp-10h] BYREF
  double intp; // [esp+24h] [ebp-8h] BYREF

  v4 = argv;
  if ( argc == 1 && (v5 = argv->Flags & 0x1F, v5 - 2 <= 2) )
  {
    if ( v5 == 4 && modf(argv->value.VNumber, &intp) != 0.0 )
      goto LABEL_7;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(v4, (Scaleform::GFx::AS3::CheckResult *)&argc, &num)->Result )
      return;
    if ( num >= 0.0 )
    {
      argv = (Scaleform::GFx::AS3::Value *)((unsigned __int16)argc | 0xC00);
      v9 = (Scaleform::GFx::AS3::VM::Error)(__int64)num;
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, (__int64)num);
    }
    else
    {
LABEL_7:
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v9, eArrayIndexNotIntegerError, pVM);
      Scaleform::GFx::AS3::VM::ThrowRangeError(pVM, v7);
      pNode = v9.Message.pNode;
      --v9.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  }
}
