void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::Instances::fl_net::NetConnection *_this; // [esp+10h] [ebp-10h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-Ch] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  _this = (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)v6.VInt;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  args.r = result;
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
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::NetConnection *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::NetConnection,8,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::NetConnection *)((char *)_this + dword_AAC6CC),
      args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
