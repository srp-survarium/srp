void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,1,long,long,Scaleform::GFx::ASString const &,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebp
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v12; // eax
  unsigned int v13; // edx
  Scaleform::GFx::ASStringNode *v14; // ecx
  Scaleform::GFx::AS3::DefArgs3<long,Scaleform::GFx::ASString const &,bool> def_ags; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<long,long,Scaleform::GFx::ASString const &,bool> args; // [esp+18h] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  def_ags._0 = 0;
  def_ags._1.pNode = p_EmptyStringNode;
  def_ags._2 = 0;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>::UnboxArgV2<long,long,Scaleform::GFx::ASString const &>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  v8 = !vm->HandleException;
  args.a2 = 0;
  if ( v8 )
  {
    if ( argc > 2 )
      args.a2 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
    v8 = !vm->HandleException;
  }
  if ( v8 )
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, int *, int, const Scaleform::GFx::ASString *, bool))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,1,long,long,Scaleform::GFx::ASString const &,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(dword_AACF44 + v6.VInt),
      &args.r,
      args.a0,
      &args.a1,
      args.a2);
    pNode = args.a1.pNode;
    --args.a1.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v10 = !args.Vm->HandleException;
  }
  else
  {
    v9 = args.a1.pNode;
    --args.a1.pNode->RefCount;
    if ( !v9->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v10 = !args.Vm->HandleException;
  }
  if ( v10 )
  {
    v12 = args.Result;
    v13 = args.Result->Flags & 0xFFFFFFE2;
    args.Result->value.VS._1.VInt = args.r;
    v14 = def_ags._1.pNode;
    v12->Flags = v13 | 2;
    v12->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14;
  }
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
