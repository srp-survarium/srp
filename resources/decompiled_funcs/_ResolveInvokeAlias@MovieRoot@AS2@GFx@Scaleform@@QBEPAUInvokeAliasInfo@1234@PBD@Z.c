Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__thiscall Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        char *pstr)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // edx
  unsigned int Size; // ecx
  int v5; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // esi
  Scaleform::GFx::MovieImpl::LevelInfo *i; // edx
  unsigned int v9; // eax
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // edx
  Scaleform::GFx::InteractiveObject *pObject; // eax
  int v12; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *pInvokeAliases; // ecx
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v15; // eax
  bool v16; // zf
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v17; // edi

  if ( !this->pInvokeAliases )
    return 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v5 = 0;
  if ( !Size )
    return 0;
  Data = pMovieImpl->MovieLevels.Data.Data;
  for ( i = Data; i->Level; ++i )
  {
    if ( ++v5 >= Size )
      return 0;
  }
  if ( !Data[v5].pSprite.pObject )
    return 0;
  v9 = 0;
  v10 = Data;
  while ( v10->Level )
  {
    ++v9;
    ++v10;
    if ( v9 >= Size )
    {
      pObject = 0;
      goto LABEL_13;
    }
  }
  pObject = Data[v9].pSprite.pObject;
LABEL_13:
  v12 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + pObject->AvmObjOffset)
                                   + 124))((int)pObject + 4 * pObject->AvmObjOffset);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 *(Scaleform::GFx::ASStringManager **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v12 + 116) + 20) + 12) + 788),
                 pstr);
  ++StringNode->RefCount;
  pInvokeAliases = this->pInvokeAliases;
  pstr = (char *)StringNode;
  v15 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Get(
          pInvokeAliases,
          (const Scaleform::GFx::ASString *)&pstr);
  v16 = StringNode->RefCount-- == 1;
  v17 = v15;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  return v17;
}
