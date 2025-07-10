void __cdecl Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,17,Scaleform::GFx::ASString>::Func(
        const Scaleform::GFx::AS3::ThunkInfo *__formal,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *obj,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::UnboxArgV0<Scaleform::GFx::ASString> args; // [esp+0h] [ebp-Ch] BYREF

  v4 = obj->value.VS._1;
  args.r.pNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  ++args.r.pNode->RefCount;
  ((void (__thiscall *)(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String,17,Scaleform::GFx::ASString>::Method)(
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)(dword_AAEE3C + v4.VInt),
    &args.r);
  if ( !vm->HandleException )
    Scaleform::GFx::AS3::Value::AssignUnsafe(result, &args.r);
  pNode = args.r.pNode;
  --args.r.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
