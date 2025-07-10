void __thiscall Scaleform::GFx::AS3::MovieRoot::ResolveStickyVariables(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::InteractiveObject *v2; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  const Scaleform::GFx::ASString *p_NamePath; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_StickyVariables; // ecx
  int v12; // eax
  unsigned int *v13; // eax
  Scaleform::GFx::InteractiveObject *v14; // ebp
  Scaleform::GFx::MovieImpl::StickyVarNode *v15; // esi
  Scaleform::GFx::AS3::Value::V1U pNode; // eax
  int v17; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // eax
  void *pWeakProxy; // eax
  Scaleform::GFx::MovieImpl::StickyVarNode *pNext; // edi
  Scaleform::GFx::MovieImpl *v22; // ecx
  int v24; // [esp+14h] [ebp-3Ch]
  Scaleform::GFx::AS3::MovieRoot::StickyVarNode *ppermanentTail; // [esp+18h] [ebp-38h]
  Scaleform::GFx::MovieImpl::StickyVarNode *path; // [esp+1Ch] [ebp-34h]
  Scaleform::GFx::MovieImpl::StickyVarNode *_pnode; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::InteractiveObject **p_pch; // [esp+24h] [ebp-2Ch]
  Scaleform::GFx::AS3::Value nameVal; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname propname; // [esp+38h] [ebp-18h] BYREF

  v2 = pch;
  pObject = pch->pNameHandle.pObject;
  if ( !pObject )
    pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pch);
  p_NamePath = &pObject->NamePath;
  path = (Scaleform::GFx::MovieImpl::StickyVarNode *)&pObject->NamePath;
  v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&v2->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                    + v2->AvmObjOffset)
                                  + 4))((int)v2 + 4 * v2->AvmObjOffset);
  if ( v6 )
    v7 = v6 - 28;
  else
    v7 = 0;
  if ( *(_DWORD *)(v7 + 8) )
    v8 = *(_DWORD *)(v7 + 8);
  else
    v8 = *(_DWORD *)(v7 + 4);
  v24 = v8;
  if ( (v8 & 1) != 0 )
    v24 = v8 - 1;
  pMovieImpl = this->pMovieImpl;
  pTable = pMovieImpl->StickyVariables.mHash.pTable;
  p_StickyVariables = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_net::SharedObject>,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pMovieImpl->StickyVariables;
  if ( pTable )
  {
    v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            p_StickyVariables,
            p_NamePath,
            p_NamePath->pNode->HashFlags & pTable->SizeMask);
    if ( v12 >= 0 )
    {
      v13 = &pTable[1].SizeMask + 3 * v12;
      if ( v13 )
      {
        v14 = 0;
        _pnode = (Scaleform::GFx::MovieImpl::StickyVarNode *)v13[1];
        ppermanentTail = 0;
        v15 = _pnode;
        if ( _pnode )
        {
          do
          {
            pNode = (Scaleform::GFx::AS3::Value::V1U)v15->Name.pNode;
            v17 = *(_DWORD *)(pNode.VInt + 4) + 56;
            nameVal.Flags = 10;
            nameVal.Bonus.pWeakProxy = 0;
            nameVal.value.VS._1 = pNode;
            if ( pNode.VInt == v17 )
            {
              nameVal.value.VS._1.VInt = 0;
              nameVal.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)p_pch;
              nameVal.Flags = 12;
            }
            else
            {
              ++*(_DWORD *)(pNode.VInt + 12);
            }
            v18 = this->pAVM.pObject->PublicNamespace.pObject;
            propname.Kind = MN_QName;
            propname.Obj.pObject = v18;
            if ( v18 )
              v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
            propname.Name.Flags = 0;
            propname.Name.Bonus.pWeakProxy = 0;
            Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&propname, &nameVal);
            if ( (nameVal.Flags & 0x1F) > 9 )
            {
              if ( (nameVal.Flags & 0x200) != 0 )
              {
                pWeakProxy = nameVal.Bonus.pWeakProxy;
                if ( nameVal.Bonus.pWeakProxy->RefCount-- == 1 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
                memset(&nameVal.Bonus, 0, 12);
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
              }
            }
            (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::MovieImpl::StickyVarNode *))(*(_DWORD *)v24 + 12))(
              v24,
              &pch,
              &propname,
              v15 + 1);
            pNext = v15->pNext;
            if ( v15->Permanent )
            {
              if ( v14 )
                ppermanentTail->pNext = v15;
              else
                v14 = (Scaleform::GFx::InteractiveObject *)v15;
              ppermanentTail = (Scaleform::GFx::AS3::MovieRoot::StickyVarNode *)v15;
              v15->pNext = 0;
            }
            else
            {
              ((void (__thiscall *)(Scaleform::GFx::MovieImpl::StickyVarNode *, int))v15->~Scaleform::GFx::MovieImpl::StickyVarNode)(
                v15,
                1);
            }
            v15 = pNext;
            Scaleform::GFx::AS3::Multiname::~Multiname(&propname);
          }
          while ( pNext );
          if ( v14 )
          {
            if ( v14 != (Scaleform::GFx::InteractiveObject *)_pnode )
            {
              v22 = this->pMovieImpl;
              _pnode = path;
              pch = v14;
              p_pch = &pch;
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
                &v22->StickyVariables.mHash,
                &v22->StickyVariables,
                (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&_pnode);
            }
            return;
          }
          p_NamePath = (const Scaleform::GFx::ASString *)path;
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
          &this->pMovieImpl->StickyVariables.mHash,
          p_NamePath);
      }
    }
  }
}
