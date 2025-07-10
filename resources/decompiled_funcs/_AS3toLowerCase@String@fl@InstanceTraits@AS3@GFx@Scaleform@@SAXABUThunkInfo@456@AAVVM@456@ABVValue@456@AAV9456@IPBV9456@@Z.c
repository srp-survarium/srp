void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toLowerCase(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASStringNode *v4; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Value *v6; // ecx
  Scaleform::GFx::AS3::VM *v7; // eax
  Scaleform::GFx::AS3::Value *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString thisStr; // [esp+0h] [ebp-4h] BYREF

  thisStr.pNode = v4;
  pStringManager = vm->StringManagerRef->pStringManager;
  v6 = _this;
  thisStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    v7 = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::ASConstString::ToLowerNode(&thisStr);
    v8 = result;
    vm = v7;
    ++v7->StringManagerRef;
    Scaleform::GFx::AS3::Value::Assign(v8, (const Scaleform::GFx::ASString *)&vm);
    v9 = (Scaleform::GFx::ASStringNode *)vm;
    --vm->StringManagerRef;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  pNode = thisStr.pNode;
  --thisStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
