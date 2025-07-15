void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substr(
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
  char *v9; // edi
  int v10; // esi
  unsigned int Length; // eax
  unsigned int v12; // ebp
  unsigned int v13; // ebx
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v15; // zf
  Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASString thisStr; // [esp+0h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+4h] [ebp-14h]
  double startNumber; // [esp+8h] [ebp-10h] BYREF
  double lengthNumber; // [esp+10h] [ebp-8h] BYREF

  sm = (Scaleform::GFx::AS3::StringManager *)vm->RefCount;
  v6 = _this;
  thisStr.pNode = &sm->pStringManager->EmptyStringNode;
  ++thisStr.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v6, (Scaleform::GFx::AS3::CheckResult *)&vm, &thisStr)->Result )
  {
    v9 = 0;
    v10 = -1;
    Length = Scaleform::GFx::ASConstString::GetLength(&thisStr);
    v12 = argc;
    v13 = Length;
    if ( argc )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&vm, &startNumber)->Result )
      {
        pNode = thisStr.pNode;
        --thisStr.pNode->RefCount;
        v8 = pNode;
        v15 = pNode->RefCount == 0;
        goto LABEL_22;
      }
      vm = (Scaleform::GFx::ASStringNode *)v13;
      if ( startNumber <= (double)v13 )
        v9 = (char *)(int)startNumber;
      else
        v9 = (char *)v13;
      if ( (int)v9 < 0 )
        v9 += v13;
    }
    if ( v12 >= 2 )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, (Scaleform::GFx::AS3::CheckResult *)&vm, &lengthNumber)->Result )
      {
LABEL_21:
        v18 = thisStr.pNode;
        --thisStr.pNode->RefCount;
        v8 = v18;
        v15 = v18->RefCount == 0;
LABEL_22:
        if ( !v15 )
          return;
        goto LABEL_23;
      }
      vm = (Scaleform::GFx::ASStringNode *)v13;
      if ( lengthNumber <= (double)v13 )
        v10 = (int)lengthNumber;
      else
        v10 = v13;
      if ( v10 < 0 )
        v10 = 0;
    }
    v16 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
            (Scaleform::GFx::ASString *)&vm,
            sm,
            &thisStr,
            v9,
            v10);
    Scaleform::GFx::AS3::Value::Assign(result, v16);
    v17 = vm;
    --vm->RefCount;
    if ( !v17->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_21;
  }
  v7 = thisStr.pNode;
  --thisStr.pNode->RefCount;
  v8 = v7;
  if ( v7->RefCount )
    return;
LABEL_23:
  Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}
