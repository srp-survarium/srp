void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v11; // eax
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // eax
  bool r; // cl
  Scaleform::GFx::AS3::Value::VU v15; // [esp+10h] [ebp-18h]
  Scaleform::GFx::AS3::UnboxArgV1<bool,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v12 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.Result = result;
  args.r = 0;
  args.a0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
    }
    else
    {
      pManager = args.a0.pNode->pManager;
      ++pManager->NullStringNode.RefCount;
      pNode = args.a0.pNode;
      --args.a0.pNode->RefCount;
      p_NullStringNode = &pManager->NullStringNode;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      args.a0.pNode = p_NullStringNode;
    }
  }
  if ( vm->HandleException )
  {
    v11 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = !vm->HandleException;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, bool *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::XML,3,bool,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::XML *)(dword_AAD19C + v6.VInt),
      &args.r,
      &args.a0);
    v13 = args.a0.pNode;
    --args.a0.pNode->RefCount;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v12 = !vm->HandleException;
  }
  if ( v12 )
  {
    r = args.r;
    args.Result->Flags = args.Result->Flags & 0xFFFFFFE0 | 1;
    v15.VS._1.VBool = r;
    args.Result->value = v15;
  }
  v12 = p_EmptyStringNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
