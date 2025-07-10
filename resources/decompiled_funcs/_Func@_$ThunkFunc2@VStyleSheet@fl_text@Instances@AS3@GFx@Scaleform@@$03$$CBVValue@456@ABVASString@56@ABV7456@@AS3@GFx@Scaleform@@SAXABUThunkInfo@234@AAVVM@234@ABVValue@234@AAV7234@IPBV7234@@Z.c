void __cdecl Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::Value::V1U v7; // edi
  Scaleform::GFx::AS3::Value *Undefined; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS3::Value v14; // [esp+Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const ,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &> args; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::DefArgs2<Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &> def_ags; // [esp+2Ch] [ebp-18h] BYREF

  StringManagerRef = vm->StringManagerRef;
  v7 = obj->value.VS._1;
  Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
  v14 = *Undefined;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
  }
  pStringManager = StringManagerRef->pStringManager;
  ++pStringManager->EmptyStringNode.RefCount;
  p_EmptyStringNode = &pStringManager->EmptyStringNode;
  def_ags._0.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  def_ags._1 = v14;
  if ( (v14.Flags & 0x1F) > 9 )
  {
    if ( (v14.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&v14);
  }
  if ( p_EmptyStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  if ( (v14.Flags & 0x1F) > 9 )
  {
    if ( (v14.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v14);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
  }
  Scaleform::GFx::AS3::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::UnboxArgV2<Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>(
    &args,
    vm,
    result,
    argc,
    argv,
    &def_ags);
  if ( !vm->HandleException )
    ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *, const Scaleform::GFx::AS3::Value *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::Method)(
      (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)(dword_AACC44 + v7.VInt),
      args.r,
      &args.a0,
      args.a1);
  pNode = args.a0.pNode;
  --args.a0.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (def_ags._1.Flags & 0x1F) > 9 )
  {
    if ( (def_ags._1.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&def_ags._1);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&def_ags._1);
  }
  v13 = def_ags._0.pNode;
  --def_ags._0.pNode->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}
