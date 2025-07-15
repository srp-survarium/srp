Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
        Scaleform::GFx::AS3::InstanceTraits::MethodInd *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  void (__thiscall *Convert)(struct Scaleform::LongFormatter *); // eax
  Scaleform::LongFormatter f; // [esp+8h] [ebp-50h] BYREF

  Scaleform::LongFormatter::LongFormatter(&f, _this->value.VS._1.VUInt);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pVM->StringManagerRef->pStringManager,
                      "Function-",
                      9u,
                      0);
  result->pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  Convert = f.Convert;
  *((_DWORD *)&f + 7) = *((_DWORD *)&f + 7) & 0xFFFFFFE0 | 0x10;
  Convert(&f);
  Scaleform::GFx::ASString::Append(
    result,
    (const __m128i *)f.ValueStr,
    (Scaleform::GFx::ASStringNode *)strlen(f.ValueStr));
  f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::Formatter::~Formatter(&f);
  return result;
}
