void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::writeUTFBytes(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
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
        (unsigned __int8 *)str.pNode->pData,
        str.pNode->Size);
    pNode = str.pNode;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eNullArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v10.Message.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
