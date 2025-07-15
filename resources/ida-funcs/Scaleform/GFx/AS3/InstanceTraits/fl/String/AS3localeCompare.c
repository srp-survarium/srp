void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3localeCompare(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        int vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v6; // edi
  Scaleform::GFx::AS3::StringManager *v7; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASString thisStr; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASString str; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [esp+18h] [ebp-8h] BYREF

  v6 = (Scaleform::GFx::AS3::VM *)vm;
  v7 = *(Scaleform::GFx::AS3::StringManager **)(vm + 12);
  pStringManager = v7->pStringManager;
  thisStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    if ( argc )
    {
      if ( argc <= 1 )
      {
        v11 = argv;
        str.pNode = &v7->pStringManager->EmptyStringNode;
        ++str.pNode->RefCount;
        if ( Scaleform::GFx::AS3::Value::Convert2String(v11, (Scaleform::GFx::AS3::CheckResult *)&vm, &str)->Result )
        {
          vm = Scaleform::GFx::AS3::InstanceTraits::fl::String::Compare(&str, &thisStr);
          Scaleform::GFx::AS3::Value::SetNumber(result, (double)vm);
        }
        pNode = str.pNode;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v15, eWrongArgumentCountError, v6);
        Scaleform::GFx::AS3::VM::ThrowArgumentError(v6, v9);
        pNode = v15.Message.pNode;
      }
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      vm = thisStr.pNode->Size == 0;
      Scaleform::GFx::AS3::Value::SetNumber(result, (double)vm);
    }
  }
  v12 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
