void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,4,Scaleform::GFx::ASString,long,long,bool>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::DefArgs3<long,long,bool> def_ags; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::ASString,long,long,bool> args; // [esp+1Ch] [ebp-18h] BYREF

  v6 = obj->value.VS._1;
  memset(&def_ags, 0, 9);
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::ASString,long,long>::UnboxArgV2<Scaleform::GFx::ASString,long,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  args.a2 = 0;
  if ( vm->HandleException )
    goto LABEL_13;
  if ( argc > 2 )
    args.a2 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv + 2);
  if ( vm->HandleException )
  {
LABEL_13:
    if ( args.Vm->HandleException )
      goto LABEL_9;
  }
  else
  {
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *, Scaleform::GFx::ASString *, int, int, bool))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot,4,Scaleform::GFx::ASString,long,long,bool>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::TextSnapshot *)(v6.VInt + dword_AACDDC),
      &args.r,
      args.a0,
      args.a1,
      args.a2);
    if ( args.Vm->HandleException )
      goto LABEL_9;
  }
  Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
LABEL_9:
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
