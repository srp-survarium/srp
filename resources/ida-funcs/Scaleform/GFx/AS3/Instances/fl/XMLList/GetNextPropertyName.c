void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  __m128i *ValueStr; // esi
  unsigned int Size; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString v; // [esp+4h] [ebp-54h] BYREF
  Scaleform::LongFormatter f; // [esp+8h] [ebp-50h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  if ( ind.Index > this->List.Data.Size )
  {
    Scaleform::GFx::AS3::Value::Assign(name, (const Scaleform::GFx::ASString *)&StringManagerRef->Builtins[2]);
  }
  else
  {
    Scaleform::LongFormatter::LongFormatter(&f, ind.Index - 1);
    Scaleform::LongFormatter::Convert(&f);
    ValueStr = (__m128i *)f.ValueStr;
    Size = Scaleform::LongFormatter::GetSize(&f);
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, ValueStr, Size);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Assign(name, &v);
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&f);
  }
}
