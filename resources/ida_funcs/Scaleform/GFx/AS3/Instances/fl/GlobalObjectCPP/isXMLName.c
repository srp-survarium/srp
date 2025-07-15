void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::isXMLName(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        bool *result,
        Scaleform::GFx::AS3::Value *str)
{
  Scaleform::GFx::AS3::Value *v4; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  wchar_t CharAt; // si
  int v11; // edi
  wchar_t v12; // ax
  wchar_t v13; // si
  int v14; // ecx
  int v15; // edx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASString name; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [esp+8h] [ebp-8h] BYREF

  v4 = str;
  if ( (str->Flags & 0x1F) == 0 || (str->Flags & 0x1F) - 12 <= 3 && !str->value.VS._1.VInt )
  {
    *result = 0;
    return;
  }
  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  name.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v4, (Scaleform::GFx::AS3::CheckResult *)&str, &name)->Result )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eConvertToPrimitiveError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v7);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v9 = name.pNode;
  if ( !name.pNode->Size )
  {
    *result = 0;
    goto LABEL_10;
  }
  CharAt = Scaleform::GFx::ASConstString::GetCharAt(&name, 0);
  if ( !Scaleform::SFiswalpha(CharAt) && CharAt != 95 )
  {
    *result = 0;
    v9 = name.pNode;
LABEL_10:
    if ( !--v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    return;
  }
  v11 = 1;
  if ( Scaleform::GFx::ASConstString::GetLength(&name) <= 1 )
  {
LABEL_24:
    *result = 1;
  }
  else
  {
    while ( 1 )
    {
      v12 = Scaleform::GFx::ASConstString::GetCharAt(&name, (const char *)v11);
      v13 = v12;
      v14 = HIBYTE(v12);
      v15 = Scaleform::UnicodeDigitBits[v14];
      if ( (!Scaleform::UnicodeDigitBits[v14]
         || v15 != 1 && (Scaleform::UnicodeDigitBits[v15 + ((unsigned __int8)v12 >> 4)] & (1 << (v12 & 0xF))) == 0)
        && !Scaleform::SFiswalpha(v12)
        && v13 != 46
        && v13 != 45
        && v13 != 95 )
      {
        break;
      }
      if ( ++v11 >= Scaleform::GFx::ASConstString::GetLength(&name) )
        goto LABEL_24;
    }
    *result = 0;
  }
  v16 = name.pNode;
  --name.pNode->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
}
