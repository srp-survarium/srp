void __thiscall Scaleform::GFx::AS3::MovieRoot::AddLoadedMovieDef(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *defImpl)
{
  Scaleform::GFx::MovieDefImpl *v2; // ebx
  Scaleform::HashIdentityLH<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,2,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> > *p_LoadedMovieDefs; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> >::TableType *pTable; // edi
  signed int Index; // eax
  int p_SizeMask; // eax
  int v7; // eax
  Scaleform::GFx::Resource *v8; // edi
  Scaleform::GFx::Resource *v9[2]; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  v2 = defImpl;
  p_LoadedMovieDefs = &this->LoadedMovieDefs;
  pTable = this->LoadedMovieDefs.mHash.pTable;
  if ( pTable
    && (Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::findIndexCore<int>(
                  &this->LoadedMovieDefs.mHash,
                  &defImpl,
                  (unsigned int)defImpl & pTable->SizeMask),
        Index >= 0)
    && (p_SizeMask = (int)&pTable[2 * Index + 1].SizeMask) != 0
    && (v7 = p_SizeMask + 4) != 0 )
  {
    ++*(_DWORD *)(v7 + 4);
  }
  else
  {
    v8 = v2;
    if ( v2 )
    {
      Scaleform::RefCountImpl::AddRef(v2);
      v2 = defImpl;
    }
    v9[0] = v8;
    v9[1] = (Scaleform::GFx::Resource *)1;
    key.pFirst = &defImpl;
    key.pSecond = (const Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo *)v9;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *>>::NodeRef>(
      &p_LoadedMovieDefs->mHash,
      p_LoadedMovieDefs,
      &key,
      (unsigned int)v2);
    if ( v9[0] )
      Scaleform::GFx::Resource::Release(v9[0]);
  }
}
