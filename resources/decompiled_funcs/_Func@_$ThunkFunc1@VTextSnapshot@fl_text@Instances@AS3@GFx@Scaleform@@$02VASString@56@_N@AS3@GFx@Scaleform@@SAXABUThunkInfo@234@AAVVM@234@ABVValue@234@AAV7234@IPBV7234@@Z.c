void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,3,Scaleform::GFx::ASString,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,bool> args; // [esp+8h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  args.a0 = 0;
  if ( argc )
    args.a0 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
  if ( !vm->HandleException )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, Scaleform::GFx::ASString *, bool))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,3,Scaleform::GFx::ASString,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(v6.VInt + dword_AACE5C),
      &args.r,
      args.a0);
    if ( !vm->HandleException )
      Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  }
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
