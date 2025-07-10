void __cdecl Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,7,Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>::Func(
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
  Scaleform::GFx::AS3::DefArgs3<bool,unsigned long,Scaleform::GFx::ASString const &> def_ags; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const ,bool,unsigned long,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-14h] BYREF

  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  v7 = obj->value.VS._1;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  def_ags._0 = 0;
  def_ags._1 = 0;
  def_ags._2.pNode = p_EmptyStringNode;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV3<Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>::UnboxArgV3<Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *, const Scaleform::GFx::AS3::Value *, bool, unsigned int, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc3<Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx,7,Scaleform::GFx::AS3::Value const,bool,unsigned long,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *)(v7.VInt + dword_AAECCC),
      args.r,
      args.a0,
      args.a1,
      &args.a2);
  pNode = args.a2.pNode;
  --args.a2.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
