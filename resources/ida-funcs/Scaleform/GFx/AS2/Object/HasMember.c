char __thiscall Scaleform::GFx::AS2::Object::HasMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        bool inclPrototypes)
{
  unsigned int RefCount; // esi
  unsigned int *p_RefCount; // ecx
  signed int v7; // eax
  int v8; // eax
  int v9; // esi
  unsigned int RootIndex; // eax
  Scaleform::GFx::AS2::Member member; // [esp+Ch] [ebp-10h] BYREF

  RefCount = this->RefCount;
  p_RefCount = &this->RefCount;
  member.mValue.T = 0;
  if ( RefCount
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_RefCount,
               name,
               *(_DWORD *)(RefCount + 4) & name->pNode->HashFlags),
        v7 >= 0)
    && (v8 = RefCount + 24 * v7 + 12) != 0 )
  {
    v9 = v8 + 4;
    Scaleform::GFx::AS2::Value::operator=(&member.mValue, (const Scaleform::GFx::AS2::Value *)(v8 + 4));
    member.mValue.T.PropFlags = *(_BYTE *)(v9 + 1);
    if ( member.mValue.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&member.mValue);
    return 1;
  }
  else if ( inclPrototypes && (RootIndex = this->RootIndex) != 0 )
  {
    return (*(int (__thiscall **)(unsigned int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, int))(*(_DWORD *)(RootIndex + 16) + 36))(
             RootIndex + 16,
             psc,
             name,
             1);
  }
  else
  {
    return 0;
  }
}
