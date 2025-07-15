void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUTFBytes(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // ecx
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-18h]
  Scaleform::GFx::ASString str; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  v4 = value;
  if ( (value->Flags & 0x1F) != 0 && ((value->Flags & 0x1F) - 12 > 3 || value->value.VS._1.VInt) )
  {
    pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
    str.pNode = &pStringManager->EmptyStringNode;
    ++pStringManager->EmptyStringNode.RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&value, &str)->Result )
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Write(
        this,
        (const __m128i *)str.pNode->pData,
        str.pNode->Size);
    pNode = str.pNode;
  }
  else
  {
    v8.pStr = "value";
    v8.Size = 5;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eNullArgumentError, this->pTraits.pObject->pVM, v8);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v5);
    pNode = v10.Message.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
