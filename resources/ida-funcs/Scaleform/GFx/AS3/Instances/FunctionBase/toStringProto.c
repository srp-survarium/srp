void __cdecl Scaleform::GFx::AS3::Instances::FunctionBase::toStringProto(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const Scaleform::GFx::AS3::Value *ConstStringNode; // eax
  Scaleform::GFx::AS3::Value *v5; // ecx
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::LongFormatter f; // [esp+0h] [ebp-50h] BYREF

  if ( ((int)_this->pData & 0x1F) == 5 )
  {
    Scaleform::LongFormatter::LongFormatter(&f, (unsigned int)_this->pLower);
    _this = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              vm->StringManagerRef->pStringManager,
              "[object Function-",
              0x11u,
              0);
    ++_this->RefCount;
    *((_DWORD *)&f + 7) = *((_DWORD *)&f + 7) & 0xFFFFFFE0 | 0x10;
    f.Convert(&f);
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&_this,
      f.ValueStr,
      (Scaleform::GFx::ASStringNode *)strlen(f.ValueStr));
    Scaleform::GFx::ASString::Append((Scaleform::GFx::ASString *)&_this, "]", (Scaleform::GFx::ASStringNode *)1);
    Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&_this);
    v7 = _this;
    --_this->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&f);
  }
  else
  {
    ConstStringNode = (const Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                            vm->StringManagerRef->pStringManager,
                                                            "function Function() {}",
                                                            0x16u,
                                                            0);
    v5 = result;
    _this = (Scaleform::GFx::ASStringNode *)ConstStringNode;
    ++ConstStringNode->value.VS._2.VObj;
    Scaleform::GFx::AS3::Value::Assign(v5, (const Scaleform::GFx::ASString *)&_this);
    v6 = _this;
    --_this->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}
