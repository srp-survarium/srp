void __cdecl Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,84,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  unsigned int Flags; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value v12; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::UnboxArgV1<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &> args; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::DefArgs1<Scaleform::GFx::AS3::Value const &> def_ags; // [esp+28h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  Flags = Undefined->Flags;
  v12 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
    Flags = v12.Flags;
  }
  def_ags._0.value.VNumber = v12.value.VNumber;
  def_ags._0.Bonus.pWeakProxy = v12.Bonus.pWeakProxy;
  def_ags._0.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v12);
    LOWORD(Flags) = v12.Flags;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v12);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
  }
  args.Vm = vm;
  args.Result = result;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  if ( !argc )
    argv = &def_ags;
  v10 = !vm->HandleException;
  args.a0 = &argv->_0;
  if ( v10 )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, Scaleform::GFx::ASString *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP,84,Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)(dword_AAD63C + v6.VInt),
      &args.r,
      &argv->_0);
  if ( !args.Vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(args.Result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (def_ags._0.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._0.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._0);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._0);
  }
}
