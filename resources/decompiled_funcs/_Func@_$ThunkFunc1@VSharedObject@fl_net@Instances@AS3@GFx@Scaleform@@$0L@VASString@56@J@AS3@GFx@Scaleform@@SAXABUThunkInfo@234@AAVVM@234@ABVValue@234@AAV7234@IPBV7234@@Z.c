void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,11,Scaleform::GFx::ASString,long>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,long> args; // [esp+8h] [ebp-10h] BYREF

  args.Result = result;
  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2Int32(argv, (Scaleform::GFx::AS3::CheckResult *)&obj, &args.a0);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::SharedObject *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::SharedObject,11,Scaleform::GFx::ASString,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)(dword_AAC40C + v6.VInt),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
