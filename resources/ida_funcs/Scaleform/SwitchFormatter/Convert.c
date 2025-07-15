void __thiscall Scaleform::SwitchFormatter::Convert(Scaleform::SwitchFormatter *this)
{
  Scaleform::Hash<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>,Scaleform::AllocatorGH<int,2>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int> >::NodeHashF> > > *p_StringSet; // edi
  Scaleform::StringDataPtr *p_StrValue; // ebx
  int Index; // eax
  int v5; // eax
  unsigned int Size; // ecx

  if ( !this->IsConverted )
  {
    p_StringSet = &this->StringSet;
    p_StrValue = &this->StrValue;
    Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeAltHashF,Scaleform::AllocatorGH<int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>,Scaleform::HashNode<int,Scaleform::StringDataPtr,Scaleform::FixedSizeHash<int>>::NodeHashF>>::findIndexAlt<int>(
              &this->StringSet.mHash,
              &this->Value);
    if ( Index >= 0 && (v5 = (int)&p_StringSet->mHash.pTable[2] + 20 * Index) != 0 )
    {
      if ( this != (Scaleform::SwitchFormatter *)-20 )
      {
        p_StrValue->pStr = *(const char **)(v5 + 4);
        this->StrValue.Size = *(_DWORD *)(v5 + 8);
        this->IsConverted = 1;
        return;
      }
    }
    else
    {
      Size = this->DefaultStrValue.Size;
      p_StrValue->pStr = this->DefaultStrValue.pStr;
      this->StrValue.Size = Size;
    }
    this->IsConverted = 1;
  }
}
