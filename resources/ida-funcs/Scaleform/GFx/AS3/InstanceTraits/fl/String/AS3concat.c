void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3concat(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::Value *v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  unsigned int v10; // ebx
  unsigned int v11; // esi
  Scaleform::GFx::AS3::Value *v12; // edi
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString thisStr; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString value; // [esp+8h] [ebp-4h] BYREF

  StringManagerRef = vm->StringManagerRef;
  v7 = _this;
  thisStr.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    pNode = thisStr.pNode;
    --thisStr.pNode->RefCount;
    v9 = pNode;
    if ( pNode->RefCount )
      return;
    goto LABEL_12;
  }
  v10 = argc;
  value.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++value.pNode->RefCount;
  v11 = 0;
  if ( v10 )
  {
    v12 = argv;
    while ( Scaleform::GFx::AS3::Value::Convert2String(v12, (Scaleform::GFx::AS3::CheckResult *)&vm, &value)->Result )
    {
      Scaleform::GFx::ASString::Append(&thisStr, (Scaleform::GFx::ASStringNode *)&value);
      ++v11;
      ++v12;
      if ( v11 >= v10 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    Scaleform::GFx::AS3::Value::Assign(result, &thisStr);
  }
  v13 = value.pNode;
  --value.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  v9 = v14;
  if ( !v14->RefCount )
LABEL_12:
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
