void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charCodeAt(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Value *v7; // ecx
  const char *v8; // esi
  double v; // st7
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString thisStr; // [esp+Ch] [ebp-Ch] BYREF
  double index; // [esp+10h] [ebp-8h] BYREF

  pStringManager = vm->StringManagerRef->pStringManager;
  v7 = _this;
  thisStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    index = 0.0;
    if ( !argc
      || Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &index)->Result )
    {
      v8 = (const char *)(int)index;
      if ( (int)index < 0 || (unsigned int)v8 >= Scaleform::GFx::ASConstString::GetLength(&thisStr) )
      {
        v = Scaleform::GFx::NumberUtil::NaN();
      }
      else
      {
        vm = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::ASConstString::GetCharAt(&thisStr, v8);
        v = (double)(unsigned int)vm;
      }
      Scaleform::GFx::AS3::Value::SetNumber(result, v);
    }
  }
  pNode = thisStr.pNode;
  --thisStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
