void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3setName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *name)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebx
  Scaleform::GFx::AS3::Value *v6; // edi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // ebp
  Scaleform::GFx::AS3::Value::V1U v8; // ebp
  Scaleform::GFx::ASStringNode *v9; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // ecx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v21; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebx
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASString localName; // [esp+8h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML::Kind kind; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v26; // [esp+10h] [ebp-4h]

  v4 = this->GetKind(this);
  kind = v4;
  if ( v4 != kText && v4 != kComment )
  {
    pVM = this->pTraits.pObject->pVM;
    v6 = name;
    localName.pNode = &pVM->StringManagerRef->pStringManager->EmptyStringNode;
    ++localName.pNode->RefCount;
    v7 = 0;
    if ( Scaleform::GFx::AS3::IsQNameObject(v6) )
    {
      v8 = v6->value.VS._1;
      if ( *(_DWORD *)(v8.VInt + 36) )
        this->SetNamespace(this, *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(v8.VInt + 36));
      v9 = *(Scaleform::GFx::ASStringNode **)(v8.VInt + 32);
      ++v9->RefCount;
      pNode = localName.pNode;
      --localName.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      localName.pNode = v9;
      v7 = *(const Scaleform::GFx::AS3::Instances::fl::Namespace **)(v8.VInt + 36);
    }
    else if ( (v6->Flags & 0x1F) != 0
           && !Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&name, &localName)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&kind, eXMLInvalidName, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v13);
      v14 = v26;
      --v26->RefCount;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v15 = localName.pNode;
      --localName.pNode->RefCount;
      v16 = v15;
      v17 = v15->RefCount == 0;
      goto LABEL_29;
    }
    if ( !Scaleform::GFx::AS3::IsValidName((Scaleform::GFx::AS3::CheckResult *)&name, &localName)->Result )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&kind, eXMLInvalidName, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v11);
      v12 = v26;
      --v26->RefCount;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      goto LABEL_28;
    }
    v18 = localName.pNode;
    ++localName.pNode->RefCount;
    v19 = this->Text.pNode;
    v17 = v19->RefCount-- == 1;
    v20 = v18;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    this->Text.pNode = v20;
    if ( !v7 )
    {
      pObject = pVM->PublicNamespace.pObject;
      goto LABEL_27;
    }
    if ( kind == kAttr )
    {
      v21 = this->Parent.pObject;
      if ( v21 )
      {
        v21->AddInScopeNamespace(v21, v7);
        pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v7;
LABEL_27:
        this->SetNamespace(this, pObject);
LABEL_28:
        v23 = localName.pNode;
        --localName.pNode->RefCount;
        v16 = v23;
        v17 = v23->RefCount == 0;
LABEL_29:
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        return;
      }
    }
    else if ( kind == kElement )
    {
      this->AddInScopeNamespace(this, v7);
    }
    pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v7;
    goto LABEL_27;
  }
}


void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3setName(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *name)
{
  const Scaleform::GFx::AS3::Value *Undefined; // eax

  Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::Instances::fl::XML::AS3setName(this, Undefined, name);
}
