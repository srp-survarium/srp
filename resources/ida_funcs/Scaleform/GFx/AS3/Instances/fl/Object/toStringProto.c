void __cdecl Scaleform::GFx::AS3::Instances::fl::Object::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::ASStringNode *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *v4; // esi
  Scaleform::GFx::AS3::VM *v5; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  _DWORD *v7; // edx
  Scaleform::GFx::ASString *MethodIndName; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASString v11; // [esp+8h] [ebp-4h] BYREF

  v4 = _this;
  v5 = (Scaleform::GFx::AS3::VM *)vm;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits((Scaleform::GFx::AS3::VM *)vm, _this);
  v7 = &v5->TraitsFunction.pObject->__vftable;
  vm = v5->StringManagerRef->Builtins[19].pNode;
  ++vm->RefCount;
  if ( ValueTraits->TraitsType != Traits_Function || (ValueTraits->Flags & 0x20) != 0 )
  {
    MethodIndName = ValueTraits->GetName(ValueTraits, &v11);
  }
  else
  {
    if ( ValueTraits == (Scaleform::GFx::AS3::Traits *)v7[26] )
    {
LABEL_4:
      MethodIndName = Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
                        (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)ValueTraits,
                        &v11,
                        v4);
      goto LABEL_10;
    }
    if ( ValueTraits == (Scaleform::GFx::AS3::Traits *)v7[27] )
    {
      MethodIndName = Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::GetThunkName(
                        (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)ValueTraits,
                        &v11,
                        v4);
    }
    else
    {
      if ( ValueTraits == (Scaleform::GFx::AS3::Traits *)v7[28] )
        goto LABEL_4;
      MethodIndName = Scaleform::GFx::AS3::InstanceTraits::Function::GetFunctionName(
                        (Scaleform::GFx::AS3::InstanceTraits::Function *)ValueTraits,
                        &v11,
                        v4);
    }
  }
LABEL_10:
  Scaleform::GFx::ASString::Append((Scaleform::GFx::ASString *)&vm, (Scaleform::GFx::ASStringNode *)MethodIndName);
  pNode = v11.pNode;
  --v11.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::ASString::Append(
    (Scaleform::GFx::ASString *)&vm,
    (Scaleform::GFx::ASStringNode *)&v5->StringManagerRef->Builtins[20]);
  Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&vm);
  v10 = vm;
  --vm->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}
