void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charAt(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::AS3::Value *v7; // ecx
  char *v8; // esi
  unsigned int CharAt; // eax
  Scaleform::GFx::ASStringNode *appended; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASString thisStr; // [esp+4h] [ebp-10h] BYREF
  Scaleform::GFx::ASString retVal; // [esp+8h] [ebp-Ch] BYREF
  double index; // [esp+Ch] [ebp-8h] BYREF

  StringManagerRef = vm->StringManagerRef;
  v7 = _this;
  thisStr.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    index = 0.0;
    if ( !argc
      || Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &index)->Result )
    {
      v8 = (char *)(int)index;
      retVal.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
      ++retVal.pNode->RefCount;
      if ( (int)v8 >= 0 && (unsigned int)v8 < Scaleform::GFx::ASConstString::GetLength(&thisStr) )
      {
        CharAt = Scaleform::GFx::ASConstString::GetCharAt(&thisStr, v8);
        appended = Scaleform::GFx::ASConstString::AppendCharNode(&retVal, CharAt);
        appended->RefCount += 2;
        pNode = retVal.pNode;
        --retVal.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        retVal.pNode = appended;
        if ( appended->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(appended);
      }
      Scaleform::GFx::AS3::Value::Assign(result, &retVal);
      v13 = retVal.pNode;
      --retVal.pNode->RefCount;
      if ( !v13->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
  }
  v14 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}
