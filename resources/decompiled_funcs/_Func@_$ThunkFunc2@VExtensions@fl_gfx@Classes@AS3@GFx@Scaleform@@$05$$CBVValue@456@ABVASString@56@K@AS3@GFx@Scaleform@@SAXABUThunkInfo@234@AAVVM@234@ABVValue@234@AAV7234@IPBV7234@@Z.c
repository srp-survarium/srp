void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>::Func(
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
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,unsigned long> def_ags; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,unsigned long> args; // [esp+14h] [ebp-10h] BYREF

  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  v7 = obj->value.VS._1;
  ++p_EmptyStringNode->RefCount;
  v8 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  def_ags._0.pNode = p_EmptyStringNode;
  def_ags._1 = 0;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *, unsigned int))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_gfx::Extensions,6,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,unsigned long>::Method)(
      (Scaleform::GFx::AS3::Classes::fl_gfx::Extensions *)(dword_AAED0C + v7.VInt),
      args.r,
      &args.a0,
      args.a1);
  pNode = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = p_EmptyStringNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
