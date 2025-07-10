void __thiscall Scaleform::GFx::AS2::MovieRoot::ResolveStickyVariables(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::InteractiveObject *v2; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::MovieRoot *v4; // ebx
  const Scaleform::GFx::ASString *p_NamePath; // edi
  int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pMovieImpl; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v9; // ecx
  _DWORD *v10; // ebp
  int v11; // eax
  unsigned int *v12; // esi
  Scaleform::GFx::MovieImpl::StickyVarNode *v13; // esi
  int v14; // edi
  int (__thiscall *v15)(_DWORD *, Scaleform::GFx::ASString *, Scaleform::GFx::MovieImpl::StickyVarNode *, Scaleform::GFx::InteractiveObject **); // edx
  int v16; // eax
  Scaleform::GFx::MovieImpl::StickyVarNode *pNext; // edi
  Scaleform::GFx::MovieImpl *v18; // ecx
  Scaleform::GFx::InteractiveObject *ppermanent; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS2::MovieRoot::StickyVarNode *ppermanentTail; // [esp+18h] [ebp-14h]
  Scaleform::GFx::MovieImpl::StickyVarNode *path; // [esp+1Ch] [ebp-10h]
  Scaleform::GFx::MovieImpl::StickyVarNode *_pnode[2]; // [esp+24h] [ebp-8h] BYREF

  v2 = pch;
  pObject = pch->pNameHandle.pObject;
  v4 = this;
  if ( !pObject )
    pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pch);
  p_NamePath = &pObject->NamePath;
  path = (Scaleform::GFx::MovieImpl::StickyVarNode *)&pObject->NamePath;
  v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&v2->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + v2->AvmObjOffset)
                                  + 4))((int)v2 + 4 * v2->AvmObjOffset);
  pMovieImpl = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v4->pMovieImpl;
  pTable = pMovieImpl[3780].pTable;
  v9 = pMovieImpl + 3780;
  v10 = (_DWORD *)v6;
  if ( pTable )
  {
    v11 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            v9,
            p_NamePath,
            pTable->SizeMask & p_NamePath->pNode->HashFlags);
    if ( v11 >= 0 )
    {
      v12 = &pTable[1].SizeMask + 3 * v11;
      if ( v12 )
      {
        v13 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v12[1];
        _pnode[0] = v13;
        ppermanent = 0;
        ppermanentTail = 0;
        if ( v13 )
        {
          do
          {
            v14 = v10[1];
            v15 = *(int (__thiscall **)(_DWORD *, Scaleform::GFx::ASString *, Scaleform::GFx::MovieImpl::StickyVarNode *, Scaleform::GFx::InteractiveObject **))(*v10 + 124);
            LOBYTE(pch) = 0;
            v16 = v15(v10, &v13->Name, v13 + 1, &pch);
            (*(void (__thiscall **)(_DWORD *, int))(v14 + 12))(v10 + 1, v16);
            pNext = v13->pNext;
            if ( v13->Permanent )
            {
              if ( ppermanent )
                ppermanentTail->pNext = v13;
              else
                ppermanent = (Scaleform::GFx::InteractiveObject *)v13;
              ppermanentTail = (Scaleform::GFx::AS2::MovieRoot::StickyVarNode *)v13;
              v13->pNext = 0;
            }
            else
            {
              ((void (__thiscall *)(Scaleform::GFx::MovieImpl::StickyVarNode *, int))v13->~Scaleform::GFx::MovieImpl::StickyVarNode)(
                v13,
                1);
            }
            v13 = pNext;
          }
          while ( pNext );
          if ( ppermanent )
          {
            if ( ppermanent != (Scaleform::GFx::InteractiveObject *)_pnode[0] )
            {
              v18 = this->pMovieImpl;
              _pnode[0] = path;
              pch = ppermanent;
              _pnode[1] = (Scaleform::GFx::MovieImpl::StickyVarNode *)&pch;
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
                &v18->StickyVariables.mHash,
                &v18->StickyVariables,
                (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)_pnode);
            }
            return;
          }
          p_NamePath = (const Scaleform::GFx::ASString *)path;
          v4 = this;
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
          &v4->pMovieImpl->StickyVariables.mHash,
          p_NamePath);
      }
    }
  }
}
