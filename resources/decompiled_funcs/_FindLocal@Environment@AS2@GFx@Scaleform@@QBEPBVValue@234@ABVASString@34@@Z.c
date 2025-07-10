const Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Environment::FindLocal(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname)
{
  Scaleform::GFx::AS2::Environment *v2; // edx
  unsigned int Size; // eax
  Scaleform::GFx::AS2::LocalFrame *pObject; // eax
  Scaleform::GFx::AS2::LocalFrame *v5; // ebx
  const Scaleform::GFx::ASString *v6; // ebp
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *p_Variables; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // edi
  signed int v9; // eax
  int p_SizeMask; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  signed int v12; // eax
  int v13; // esi
  unsigned __int8 SWFVersion; // al
  int v15; // edi
  int p_AVMVersion; // esi
  bool v17; // zf
  int p_pASSupport; // esi
  bool v19; // zf
  Scaleform::GFx::AS2::LocalFrame *v20; // eax
  unsigned int v21; // eax
  unsigned int v23; // eax
  unsigned int RefCount; // eax

  v2 = this;
  Size = this->LocalFrames.Data.Size;
  if ( !Size )
    return 0;
  pObject = this->LocalFrames.Data.Data[Size - 1].pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v5 = pObject;
  if ( !pObject )
    return 0;
  v6 = varname;
  while ( 1 )
  {
    p_Variables = &v5->Variables;
    if ( v2->StringContext.SWFVersion > 6u )
      break;
    pNode = v6->pNode;
    v17 = v6->pNode->pLower == 0;
    varname = v6;
    if ( v17 )
    {
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
      v2 = this;
    }
    if ( p_Variables->mHash.pTable )
    {
      v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              &v5->Variables.mHash,
              (const Scaleform::GFx::ASString::NoCaseKey *)&varname,
              v6->pNode->HashFlags & p_Variables->mHash.pTable->SizeMask);
      if ( v12 >= 0 )
      {
        p_SizeMask = (int)&p_Variables->mHash.pTable[3 * v12 + 1].SizeMask;
        goto LABEL_15;
      }
LABEL_17:
      v2 = this;
    }
LABEL_18:
    SWFVersion = v2->StringContext.SWFVersion;
    v15 = SWFVersion;
    if ( SWFVersion >= 5u )
    {
      p_AVMVersion = (int)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].AVMVersion;
      if ( SWFVersion <= 6u )
      {
        if ( !v6->pNode->pLower )
        {
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
          v2 = this;
        }
        v17 = *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)p_AVMVersion + 8) == v6->pNode->pLower;
      }
      else
      {
        v17 = *(Scaleform::GFx::ASStringNode **)p_AVMVersion == v6->pNode;
      }
      if ( v17 )
        goto LABEL_48;
    }
    if ( v15 >= 6 )
    {
      p_pASSupport = (int)&v2->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport;
      if ( v2->StringContext.SWFVersion <= 6u )
      {
        if ( !v6->pNode->pLower )
        {
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v6->pNode);
          v2 = this;
        }
        v19 = *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)p_pASSupport + 8) == v6->pNode->pLower;
      }
      else
      {
        v19 = *(Scaleform::GFx::ASStringNode **)p_pASSupport == v6->pNode;
      }
      if ( v19 )
      {
LABEL_48:
        if ( v5 )
        {
          RefCount = v5->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v5->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
          }
        }
        return 0;
      }
    }
    v20 = v5->PrevFrame.pObject;
    if ( v20 )
      v20->RefCount = (v20->RefCount + 1) & 0x8FFFFFFF;
    v21 = v5->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v21) != 0 )
    {
      v5->RefCount = v21 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      v2 = this;
    }
    v5 = v5->PrevFrame.pObject;
    if ( !v5 )
      return 0;
  }
  pTable = p_Variables->mHash.pTable;
  if ( !p_Variables->mHash.pTable )
    goto LABEL_18;
  v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
         &v5->Variables.mHash,
         v6,
         v6->pNode->HashFlags & pTable->SizeMask);
  if ( v9 < 0 )
    goto LABEL_17;
  p_SizeMask = (int)&pTable[3 * v9 + 1].SizeMask;
LABEL_15:
  if ( !p_SizeMask )
    goto LABEL_17;
  v13 = p_SizeMask + 4;
  if ( p_SizeMask == -4 )
    goto LABEL_17;
  if ( v5 )
  {
    v23 = v5->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
    {
      v5->RefCount = v23 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  return (const Scaleform::GFx::AS2::Value *)v13;
}
