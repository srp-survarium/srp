void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3slice(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // ecx
  unsigned int v9; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  int Length; // ebx
  int v12; // esi
  Scaleform::GFx::ASStringNode *v13; // eax
  bool v14; // zf
  const char *v15; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASString thisStr; // [esp+0h] [ebp-1Ch] BYREF
  int utf8Len; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS3::StringManager *sm; // [esp+8h] [ebp-14h]
  double startNumber; // [esp+Ch] [ebp-10h] BYREF
  double endNumber; // [esp+14h] [ebp-8h] BYREF

  sm = (Scaleform::GFx::AS3::StringManager *)vm->RefCount;
  v6 = _this;
  thisStr.pNode = &sm->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    v9 = argc;
    if ( !argc )
    {
      Scaleform::GFx::AS3::Value::Assign(result, &thisStr);
      pNode = thisStr.pNode;
      --thisStr.pNode->RefCount;
      v8 = pNode;
      if ( pNode->RefCount )
        return;
      goto LABEL_28;
    }
    Length = Scaleform::GFx::ASConstString::GetLength(&thisStr);
    utf8Len = Length;
    v12 = 0x7FFFFFFF;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &startNumber)->Result )
    {
      v13 = thisStr.pNode;
      --thisStr.pNode->RefCount;
      v8 = v13;
      v14 = v13->RefCount == 0;
      goto LABEL_27;
    }
    if ( startNumber <= (double)utf8Len )
      v15 = (const char *)(int)startNumber;
    else
      v15 = (const char *)Length;
    if ( (int)v15 < 0 )
      v15 += Length;
    if ( v9 < 2 )
      goto LABEL_23;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&vm, &endNumber)->Result )
    {
LABEL_26:
      v18 = thisStr.pNode;
      --thisStr.pNode->RefCount;
      v8 = v18;
      v14 = v18->RefCount == 0;
LABEL_27:
      if ( !v14 )
        return;
      goto LABEL_28;
    }
    v12 = endNumber <= (double)utf8Len ? (int)endNumber : Length;
    if ( v12 < 0 )
      v12 += Length;
    if ( v12 >= (int)v15 )
    {
LABEL_23:
      vm = Scaleform::GFx::ASConstString::SubstringNode(&thisStr, v15, (const char *)v12);
      ++vm->RefCount;
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&vm);
    }
    else
    {
      pStringManager = sm->pStringManager;
      vm = &pStringManager->EmptyStringNode;
      ++pStringManager->EmptyStringNode.RefCount;
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&vm);
    }
    v17 = vm;
    --vm->RefCount;
    if ( !v17->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_26;
  }
  v7 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  v8 = v7;
  if ( v7->RefCount )
    return;
LABEL_28:
  Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
