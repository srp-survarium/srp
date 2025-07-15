Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::Array::ToLocaleStringInternal(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int v3; // ebx
  const Scaleform::GFx::AS3::Value *p_DefaultValue; // esi
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::Value::V1U v9; // ebp
  Scaleform::GFx::ASStringNode *VInt; // ecx
  const __m128i ***v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // ecx
  unsigned int v16; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v17; // ecx
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS3::CheckResult v21; // [esp+13h] [ebp-61h] BYREF
  unsigned int v22; // [esp+14h] [ebp-60h]
  Scaleform::GFx::ASString v; // [esp+18h] [ebp-5Ch] BYREF
  unsigned int key; // [esp+1Ch] [ebp-58h] BYREF
  Scaleform::GFx::ASString v25; // [esp+20h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+34h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+44h] [ebp-30h] BYREF
  Scaleform::StringBuffer buff; // [esp+5Ch] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&buff, this->pTraits.pObject->pVM->MHeap);
  v3 = 0;
  if ( !this->SA.Length )
    goto LABEL_54;
  v22 = 0;
  while ( 1 )
  {
    if ( v3 )
      Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)",", 0xFFFFFFFF);
    key = v3;
    if ( v3 >= this->SA.ValueA.Data.Size )
    {
      if ( v3 < this->SA.ValueHLowInd
        || v3 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                      &this->SA.ValueH.mHash,
                      &key),
            Index < 0)
        || (v6 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
        || (p_DefaultValue = (const Scaleform::GFx::AS3::Value *)&v6[1],
            v6 == (Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *)-8) )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v22 / 0x10];
    }
    if ( (p_DefaultValue->Flags & 0x1F) == 0
      || (p_DefaultValue->Flags & 0x1F) - 12 <= 3 && !p_DefaultValue->value.VS._1.VInt )
    {
      goto LABEL_40;
    }
    v.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                "toLocaleString",
                0xEu,
                0);
    ++v.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&name, &v);
    Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject, &name);
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    pNode = v.pNode;
    --v.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pObject = this->pTraits.pObject;
    r.Flags = 0;
    r.Bonus.pWeakProxy = 0;
    if ( !Scaleform::GFx::AS3::ExecutePropertyUnsafe(&v21, pObject->pVM, &prop_name, p_DefaultValue, &r, 0, 0)->Result )
      break;
    if ( (r.Flags & 0x1F) == 0xA )
    {
      v9 = r.value.VS._1;
      ++*(_DWORD *)(r.value.VS._1.VInt + 12);
      Scaleform::StringBuffer::AppendString(&buff, *(const __m128i **)v9.VInt, 0xFFFFFFFF);
      if ( (*(_DWORD *)(v9.VInt + 12))-- == 1 )
      {
        VInt = (Scaleform::GFx::ASStringNode *)v9.VInt;
LABEL_27:
        Scaleform::GFx::ASStringNode::ReleaseNode(VInt);
      }
    }
    else
    {
      v12 = (const __m128i ***)Scaleform::GFx::AS3::AsString(&v25, &r, this->pTraits.pObject->pVM->StringManagerRef);
      Scaleform::StringBuffer::AppendString(&buff, **v12, 0xFFFFFFFF);
      v13 = v25.pNode;
      --v25.pNode->RefCount;
      VInt = v13;
      if ( !v13->RefCount )
        goto LABEL_27;
    }
    if ( (r.Flags & 0x1F) > 9 )
    {
      if ( (r.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
    if ( (prop_name.Name.Flags & 0x1F) > 9 )
    {
      if ( (prop_name.Name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_name.Name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
    }
    if ( prop_name.Obj.pObject )
    {
      if ( ((int)prop_name.Obj.pObject & 1) == 0 )
      {
        RefCount = prop_name.Obj.pObject->RefCount;
        v15 = prop_name.Obj.pObject;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          prop_name.Obj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
        }
      }
    }
LABEL_40:
    v22 += 16;
    if ( ++v3 >= this->SA.Length )
      goto LABEL_54;
  }
  if ( (r.Flags & 0x1F) > 9 )
  {
    if ( (r.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
  }
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop_name.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
  }
  if ( prop_name.Obj.pObject )
  {
    if ( ((int)prop_name.Obj.pObject & 1) == 0 )
    {
      v16 = prop_name.Obj.pObject->RefCount;
      v17 = prop_name.Obj.pObject;
      if ( (v16 & 0x3FFFFF) != 0 )
      {
        prop_name.Obj.pObject->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
LABEL_54:
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
