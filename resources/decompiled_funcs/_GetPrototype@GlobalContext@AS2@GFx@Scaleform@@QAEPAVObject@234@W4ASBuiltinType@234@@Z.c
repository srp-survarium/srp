Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::GlobalContext::GetPrototype(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASBuiltinType type)
{
  Scaleform::HashUncachedLH<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,2> *p_Prototypes; // esi
  signed int v4; // eax
  int v5; // eax
  int v6; // eax
  signed int v7; // eax
  int v8; // eax

  p_Prototypes = &this->Prototypes;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexAlt<enum Scaleform::GFx::AS2::ASBuiltinType>(
         &this->Prototypes.mHash,
         &type);
  if ( v4 >= 0 )
  {
    v5 = (int)(&p_Prototypes->mHash.pTable[1].SizeMask + 3 * v4);
    if ( v5 )
    {
      v6 = v5 + 4;
      if ( v6 )
        return *(Scaleform::GFx::AS2::Object **)v6;
    }
  }
  Scaleform::GFx::AS2::GlobalContext::ResolveFunctionName(
    this,
    (const Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[8].RefCount + type);
  v7 = Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::findIndexAlt<enum Scaleform::GFx::AS2::ASBuiltinType>(
         &p_Prototypes->mHash,
         &type);
  if ( v7 >= 0 && (v8 = (int)(&p_Prototypes->mHash.pTable[1].SizeMask + 3 * v7)) != 0 && (v6 = v8 + 4) != 0 )
    return *(Scaleform::GFx::AS2::Object **)v6;
  else
    return 0;
}
