void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_net::Socket,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value::V1U v6; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *v10; // esi
  bool v11; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &> def_ags; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &> args; // [esp+18h] [ebp-10h] BYREF

  v6 = obj->value.VS._1;
  StringManagerRef = vm->StringManagerRef;
  p_EmptyStringNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  pStringManager = StringManagerRef->pStringManager;
  ++pStringManager->EmptyStringNode.RefCount;
  ++pStringManager->EmptyStringNode.RefCount;
  ++p_EmptyStringNode->RefCount;
  v10 = &pStringManager->EmptyStringNode;
  v11 = v10->RefCount-- == 1;
  def_ags._0.pNode = v10;
  def_ags._1.pNode = p_EmptyStringNode;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = p_EmptyStringNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_net::Socket *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *, const Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_net::Socket,36,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::ASString const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_net::Socket *)(dword_AAC3EC + v6.VInt),
      args.r,
      &args.a0,
      &args.a1);
  pNode = args.a1.pNode;
  p_RefCount = &args.a1.pNode->RefCount;
  --args.a1.pNode->RefCount;
  if ( !*p_RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v14 = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v11 = p_EmptyStringNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  v11 = v10->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}
