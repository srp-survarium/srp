void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_net::Socket,22,Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::AS3::Value::V1U v7; // edi
  bool v8; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::DefArgs2<unsigned long,Scaleform::GFx::ASString const &> def_ags; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &> args; // [esp+14h] [ebp-14h] BYREF

  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  v7 = obj->value.VS._1;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  def_ags._0 = 0;
  def_ags._1.pNode = p_EmptyStringNode;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>::UnboxArgV2<Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, Scaleform::GFx::ASString *, unsigned int, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_net::Socket,22,Scaleform::GFx::ASString,unsigned long,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC58C + v7.VInt),
      &args.r,
      args.a0,
      &args.a1);
  pNode = args.a1.pNode;
  --args.a1.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !args.Vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  v10 = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
