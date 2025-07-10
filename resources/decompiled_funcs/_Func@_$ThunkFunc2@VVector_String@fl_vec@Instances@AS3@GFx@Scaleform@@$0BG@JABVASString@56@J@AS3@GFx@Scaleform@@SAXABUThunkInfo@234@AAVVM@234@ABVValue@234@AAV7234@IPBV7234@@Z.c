void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,22,long,Scaleform::GFx::ASString const &,long>::Func(
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
  Scaleform::GFx::AS3::Value *v10; // eax
  unsigned int v11; // edx
  int v12; // ecx
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,long> def_ags; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<long,Scaleform::GFx::ASString const &,long> args; // [esp+14h] [ebp-14h] BYREF

  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  v7 = obj->value.VS._1;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  def_ags._0.pNode = p_EmptyStringNode;
  def_ags._1 = 0x7FFFFFFF;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV2<long,Scaleform::GFx::ASString const &,long>::UnboxArgV2<long,Scaleform::GFx::ASString const &,long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, int *, const Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,22,long,Scaleform::GFx::ASString const &,long>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAF0F4 + v7.VInt),
      &args.r,
      &args.a0,
      args.a1);
  pNode = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !args.Vm->HandleException )
  {
    v10 = args.Result;
    v11 = args.Result->Flags & 0xFFFFFFE2;
    args.Result->value.VS._1.VInt = args.r;
    v12 = def_ags._1;
    v10->Flags = v11 | 2;
    v10->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v12;
  }
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
