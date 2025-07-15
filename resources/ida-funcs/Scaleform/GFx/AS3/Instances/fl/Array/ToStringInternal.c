Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *sep)
{
  unsigned int v4; // ebx
  int v5; // ebp
  Scaleform::GFx::AS3::Value *p_DefaultValue; // ecx
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v8; // eax
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS3::CheckResult v12; // [esp+Bh] [ebp-1Dh] BYREF
  unsigned int key; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::StringBuffer buff; // [esp+10h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&buff, this->pTraits.pObject->pVM->MHeap);
  v4 = 0;
  if ( this->SA.Length )
  {
    v5 = 0;
    do
    {
      if ( v4 )
        Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)sep->pNode->pData, 0xFFFFFFFF);
      key = v4;
      if ( v4 >= this->SA.ValueA.Data.Size )
      {
        if ( v4 < this->SA.ValueHLowInd
          || v4 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &this->SA.ValueH.mHash,
                        &key),
              Index < 0)
          || (v8 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v8[1],
              v8 == (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-8) )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v5];
      }
      if ( (p_DefaultValue->Flags & 0x1F) != 0
        && ((p_DefaultValue->Flags & 0x1F) - 12 > 3 || p_DefaultValue->value.VS._1.VInt)
        && !Scaleform::GFx::AS3::Value::Convert2String(p_DefaultValue, &v12, &buff)->Result )
      {
        break;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->SA.Length );
  }
  pData = (__m128i *)buff.pData;
  if ( !buff.pData )
    pData = (__m128i *)uri;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 pData,
                 buff.Size);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
  return result;
}
