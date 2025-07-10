void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringManager *pManager; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // edi
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *_this; // [esp+10h] [ebp-14h]
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-10h] BYREF

  _this = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)obj->value.VS._1.VInt;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      ",",
                      1u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = ++ConstStringNode->RefCount == 1;
  --ConstStringNode->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0.pNode = v7;
  ++v7->RefCount;
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
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *, Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double,6,Scaleform::GFx::ASString,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)_this + dword_AAEFBC),
      &args.r,
      &args.a0);
  v12 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v13 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
