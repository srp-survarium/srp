char __thiscall Scaleform::GFx::AS3::MovieRoot::RemoveLoadedMovieDef(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *pTable; // esi
  Scaleform::HashIdentityLH<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,2,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> > *p_LoadedMovieDefs; // edi
  signed int Index; // eax
  int p_SizeMask; // eax
  int v6; // eax

  pTable = this->LoadedMovieDefs.mHash.pTable;
  p_LoadedMovieDefs = &this->LoadedMovieDefs;
  if ( !pTable )
    return 0;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::findIndexCore<int>(
            &this->LoadedMovieDefs.mHash,
            &defImpl,
            (unsigned int)defImpl & pTable->SizeMask);
  if ( Index < 0 )
    return 0;
  p_SizeMask = (int)&pTable[2 * Index + 1].SizeMask;
  if ( !p_SizeMask )
    return 0;
  v6 = p_SizeMask + 4;
  if ( !v6 )
    return 0;
  if ( (*(_DWORD *)(v6 + 4))-- != 1 )
    return 0;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::MovieDefImpl *>(
    &p_LoadedMovieDefs->mHash,
    &defImpl);
  return 1;
}
