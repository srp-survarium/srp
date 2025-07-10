void __thiscall Scaleform::GFx::AS3::EventChains::RemoveFromChain(
        Scaleform::GFx::AS3::EventChains *this,
        Scaleform::GFx::EventId::IdCode evtId,
        Scaleform::GFx::DisplayObject *obj)
{
  Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::TableType *pTable; // esi
  signed int Index; // eax
  int p_SizeMask; // eax
  Scaleform::GFx::DisplayObject ****v6; // eax
  Scaleform::GFx::DisplayObject ***v7; // eax
  Scaleform::GFx::DisplayObject **v8; // ecx
  int v9; // esi
  Scaleform::GFx::DisplayObject **v10; // edi
  Scaleform::GFx::DisplayObject **i; // eax
  Scaleform::RefCountNTSImpl *v12; // ecx

  pTable = this->Chains.mHash.pTable;
  if ( this->Chains.mHash.pTable )
  {
    Index = Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>,Scaleform::IdentityHash<int>>::NodeHashF>>::findIndexCore<int>(
              (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::MovieDefImpl *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >,Scaleform::HashNode<Scaleform::GFx::MovieDefImpl *,Scaleform::GFx::AS3::MovieRoot::LoadedMovieDefInfo,Scaleform::IdentityHash<Scaleform::GFx::MovieDefImpl *> >::NodeHashF> > *)this,
              (Scaleform::GFx::MovieDefImpl *const *)&evtId,
              evtId & pTable->SizeMask);
    if ( Index >= 0 )
    {
      p_SizeMask = (int)&pTable[2 * Index + 1].SizeMask;
      if ( p_SizeMask )
      {
        v6 = (Scaleform::GFx::DisplayObject ****)(p_SizeMask + 4);
        if ( v6 )
        {
          v7 = *v6;
          v8 = v7[1];
          v9 = 0;
          if ( v8 )
          {
            v10 = *v7;
            for ( i = *v7; *i != obj; ++i )
            {
              if ( ++v9 >= (unsigned int)v8 )
                return;
            }
            if ( v9 != -1 )
            {
              v12 = v10[v9];
              if ( v12 )
                Scaleform::RefCountNTSImpl::Release(v12);
              v10[v9] = 0;
            }
          }
        }
      }
    }
  }
}
