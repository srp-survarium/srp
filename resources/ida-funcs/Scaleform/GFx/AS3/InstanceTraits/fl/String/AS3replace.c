void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3replace(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v6; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::AS3::Value *v10; // ebp
  unsigned int v11; // eax
  Scaleform::GFx::AS3::Instances::fl::RegExp *VInt; // esi
  Scaleform::GFx::AS3::Instances::fl::RegExp *pObject; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS3::Instances::fl::RegExp *v16; // ecx
  Scaleform::GFx::AS3::VM *v17; // esi
  char *MatchOffset; // esi
  int MatchLength; // edi
  char *Length; // eax
  Scaleform::GFx::ASString *v21; // eax
  const Scaleform::GFx::ASString *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString str; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::RegExp> pre; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::ASString repl; // [esp+14h] [ebp-24h] BYREF
  Scaleform::GFx::ASString v32; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::ASString v33; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString v34; // [esp+20h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v35; // [esp+24h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value args[1]; // [esp+28h] [ebp-10h] BYREF

  v6 = vm;
  StringManagerRef = vm->StringManagerRef;
  str.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++str.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&vm, &str)->Result )
  {
    if ( !argc || (v10 = argv, (v11 = argv->Flags & 0x1F) == 0) || v11 - 12 <= 3 && !argv->value.VS._1.VInt )
    {
LABEL_41:
      pNode = str.pNode;
      --str.pNode->RefCount;
      v9 = pNode;
      if ( pNode->RefCount )
        return;
      goto LABEL_42;
    }
    pre.pObject = 0;
    if ( v11 - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(v6, argv, "RegExp", v6->CurrentDomain) )
    {
      VInt = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v10->value.VS._1.VInt;
      pObject = pre.pObject;
      if ( VInt != pre.pObject )
      {
        if ( VInt )
        {
          VInt->RefCount = (VInt->RefCount + 1) & 0x8FBFFFFF;
          pObject = pre.pObject;
        }
        if ( pObject )
        {
          if ( ((unsigned __int8)pObject & 1) == 0 )
          {
            RefCount = pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
          }
        }
        pre.pObject = VInt;
      }
    }
    else
    {
      repl.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
      ++repl.pNode->RefCount;
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v10, (Scaleform::GFx::AS3::CheckResult *)&vm, &repl)->Result )
        goto LABEL_38;
      Scaleform::GFx::AS3::Value::Value(args, &repl);
      Scaleform::GFx::AS3::VM::constructBuiltinObject(
        v6,
        (Scaleform::GFx::AS3::CheckResult *)&vm,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pre,
        "RegExp",
        1u,
        args);
      if ( !(_BYTE)vm )
      {
        `vector destructor iterator'(
          (char *)args,
          0x10u,
          1,
          (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        goto LABEL_38;
      }
      `vector destructor iterator'(
        (char *)args,
        0x10u,
        1,
        (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      v15 = repl.pNode;
      --repl.pNode->RefCount;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    if ( argc < 2 || Scaleform::GFx::AS3::Value::IsNullOrUndefined(v10 + 1) )
      goto LABEL_40;
    repl.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
    ++repl.pNode->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(v10 + 1, (Scaleform::GFx::AS3::CheckResult *)&vm, &repl)->Result )
    {
      v16 = pre.pObject;
      do
      {
        vm = 0;
        Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
          v16,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&vm,
          &str);
        v17 = vm;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&vm);
        if ( !v17 )
          break;
        MatchOffset = (char *)pre.pObject->MatchOffset;
        MatchLength = pre.pObject->MatchLength;
        Length = (char *)Scaleform::GFx::ASConstString::GetLength(&str);
        v33.pNode = Scaleform::GFx::ASConstString::SubstringNode(&str, &MatchOffset[MatchLength], Length);
        ++v33.pNode->RefCount;
        v32.pNode = Scaleform::GFx::ASConstString::SubstringNode(&str, 0, MatchOffset);
        ++v32.pNode->RefCount;
        v21 = Scaleform::GFx::ASString::operator+(&v32, &v35, &repl);
        v22 = Scaleform::GFx::ASString::operator+(v21, &v34, &v33);
        Scaleform::GFx::ASString::operator=(&str, v22);
        v23 = v34.pNode;
        --v34.pNode->RefCount;
        if ( !v23->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        v24 = v35.pNode;
        --v35.pNode->RefCount;
        if ( !v24->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v25 = v32.pNode;
        --v32.pNode->RefCount;
        if ( !v25->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        v26 = v33.pNode;
        --v33.pNode->RefCount;
        if ( !v26->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        v16 = pre.pObject;
      }
      while ( pre.pObject->IsGlobal );
      Scaleform::GFx::AS3::Value::Assign(result, &str);
    }
LABEL_38:
    v27 = repl.pNode;
    --repl.pNode->RefCount;
    if ( !v27->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_40:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
    goto LABEL_41;
  }
  v8 = str.pNode;
  --str.pNode->RefCount;
  v9 = v8;
  if ( v8->RefCount )
    return;
LABEL_42:
  Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}
