void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3setLocalName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *name)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::ASStringNode *v7; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::VM::Error v12; // [esp+4h] [ebp-8h] BYREF

  v4 = this->GetKind(this);
  if ( v4 != kText && v4 != kComment )
  {
    pVM = this->pTraits.pObject->pVM;
    v6 = name;
    if ( Scaleform::GFx::AS3::IsQNameObject(name) )
    {
      v7 = *(Scaleform::GFx::ASStringNode **)(v6->value.VS._1.VInt + 32);
      ++v7->RefCount;
      pNode = this->Text.pNode;
      if ( pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      this->Text.pNode = v7;
    }
    else if ( (v6->Flags & 0x1F) != 0 )
    {
      Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&name, &this->Text);
    }
    if ( !Scaleform::GFx::AS3::IsValidName((Scaleform::GFx::AS3::CheckResult *)&name, &this->Text)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eXMLInvalidName, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v10);
      v11 = v12.Message.pNode;
      --v12.Message.pNode->RefCount;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
  }
}
