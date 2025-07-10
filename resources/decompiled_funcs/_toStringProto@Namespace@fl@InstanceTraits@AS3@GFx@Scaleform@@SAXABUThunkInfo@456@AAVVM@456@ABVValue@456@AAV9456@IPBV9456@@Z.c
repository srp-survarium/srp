void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Object *VObj; // edi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+8h] [ebp-8h] BYREF

  v4 = _this->Flags & 0x1F;
  if ( v4 - 12 <= 3 && (VObj = _this->value.VS._1.VObj) != 0 )
  {
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(vm->TraitsNamespace.pObject->ITraits.pObject);
    if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(Constructor) )
    {
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)vm->StringManagerRef);
      return;
    }
  }
  else if ( v4 == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)(_this->value.VS._1.VInt + 28));
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v9, eUndefinedVarError, vm);
  Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v7);
  pNode = v9.Message.pNode;
  --v9.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
