void __thiscall Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::RemoveValue(
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *const *v)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // edx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v3; // edi
  unsigned int v4; // eax
  unsigned int SizeMask; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v6; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v7; // edx
  unsigned int v8; // esi
  unsigned int *v9; // edx

  pTable = this->Entries.mHash.pTable;
  if ( this->Entries.mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v4 = 0;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2 )
        break;
      ++v4;
      v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)v6 + 20);
    }
    while ( v4 <= SizeMask );
    v3 = this;
  }
  else
  {
    v3 = 0;
    v4 = 0;
  }
  while ( v3 )
  {
    v7 = v3->Entries.mHash.pTable;
    if ( !v3->Entries.mHash.pTable )
      break;
    v8 = v7->SizeMask;
    if ( (int)v4 > (int)v8 )
      break;
    if ( (Scaleform::GFx::AS3::ClassTraits::Traits *const)*(&v7[3].EntryCount + 5 * v4) == *v )
    {
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
        &this->Entries.mHash,
        (const Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)((char *)&v7[2] + 20 * v4));
      return;
    }
    if ( ++v4 <= v8 )
    {
      v9 = &v7[1].EntryCount + 5 * v4;
      do
      {
        if ( *v9 != -2 )
          break;
        ++v4;
        v9 += 5;
      }
      while ( v4 <= v8 );
    }
  }
}
