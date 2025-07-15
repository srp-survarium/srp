Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::GlobalContext::FindClassName(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *iobj)
{
  Scaleform::GFx::AS2::GlobalContext *v4; // edi
  bool v5; // cc
  Scaleform::GFx::AS2::ObjectInterface::ObjectType (__thiscall *GetObjectType)(Scaleform::GFx::AS2::ObjectInterface *); // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *v7; // eax
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pHash; // ecx
  int Index; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v12; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v13; // eax
  Scaleform::GFx::ASStringNode **p_SizeMask; // ebx
  Scaleform::GFx::AS2::Value *v15; // esi
  Scaleform::GFx::AS2::FunctionRef *v16; // eax
  bool v17; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v20; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASString *v22; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::AS2::FunctionObject *v24; // esi
  unsigned __int8 Flags; // bl
  unsigned int v26; // eax
  Scaleform::GFx::AS2::LocalFrame *v27; // ecx
  unsigned int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // ecx
  unsigned __int8 v30; // bl
  unsigned int v31; // eax
  Scaleform::GFx::AS2::LocalFrame *v32; // ecx
  unsigned int v33; // eax
  Scaleform::GFx::ASStringNode *pMovieImpl; // ecx
  int v35; // [esp+10h] [ebp-38h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::ConstIterator v37; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FunctionRef resulta; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRef v39; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v40; // [esp+38h] [ebp-10h] BYREF
  Scaleform::GFx::ASString *penva; // [esp+50h] [ebp+8h]
  Scaleform::GFx::AS2::Object *p_pProto; // [esp+54h] [ebp+Ch]

  v4 = this;
  v35 = 0;
  if ( !iobj )
  {
LABEL_62:
    pMovieImpl = (Scaleform::GFx::ASStringNode *)v4->pMovieRoot->pASMovieRoot.pObject[17].pMovieImpl;
    v22 = result;
    result->pNode = pMovieImpl;
    ++pMovieImpl->RefCount;
    return v22;
  }
  v5 = (unsigned int)(iobj->GetObjectType(iobj) - 2) <= 3;
  GetObjectType = iobj->GetObjectType;
  if ( v5 )
  {
    if ( (unsigned int)(GetObjectType(iobj) - 2) > 3 )
      p_pProto = (Scaleform::GFx::AS2::Object *)(*(int (**)(void))(MEMORY[0] + 104))();
    else
      p_pProto = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))iobj[-1].pProto.pObject[2].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable)(&iobj[-1].pProto);
  }
  else if ( (unsigned int)(GetObjectType(iobj) - 6) > 0x26 )
  {
    p_pProto = 0;
  }
  else
  {
    p_pProto = (Scaleform::GFx::AS2::Object *)&iobj[-2].pProto;
  }
  v7 = Scaleform::Hash<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::ViewStats::BufferInstructionTimes>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>>::Begin(
         &v4->pGlobal.pObject->Members,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&resulta);
  pHash = v7->pHash;
  Index = v7->Index;
  Function = resulta.Function;
  v37.pHash = pHash;
  v37.Index = Index;
  while ( 1 )
  {
    if ( !pHash || !pHash->pTable || (v12.pTable = pHash->pTable, Index > (signed int)v12.pTable->SizeMask) )
    {
      v4 = this;
      goto LABEL_62;
    }
    v13 = &v12.pTable[3 * Index];
    p_SizeMask = (Scaleform::GFx::ASStringNode **)&v13[1].SizeMask;
    v15 = (Scaleform::GFx::AS2::Value *)&v13[2];
    penva = (Scaleform::GFx::ASString *)&v13[1].SizeMask;
    if ( p_pProto->GetObjectType(&p_pProto->Scaleform::GFx::AS2::ObjectInterface) == Object_Function )
    {
      v17 = 0;
      if ( v15->T.Type == 8 || v15->T.Type == 11 )
      {
        v35 |= 1u;
        v16 = Scaleform::GFx::AS2::Value::ToFunction(v15, &resulta, penv);
        Function = resulta.Function;
        if ( v16->Function == p_pProto )
          v17 = 1;
      }
      if ( (v35 & 1) != 0 )
      {
        v35 &= ~1u;
        if ( (resulta.Flags & 2) == 0 )
        {
          if ( Function )
          {
            RefCount = Function->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              Function->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            }
          }
        }
        Function = 0;
        resulta.Function = 0;
        if ( (resulta.Flags & 1) == 0 )
        {
          pLocalFrame = resulta.pLocalFrame;
          if ( resulta.pLocalFrame )
          {
            v20 = resulta.pLocalFrame->RefCount;
            if ( (v20 & 0x3FFFFFF) != 0 )
            {
              resulta.pLocalFrame->RefCount = v20 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              Function = resulta.Function;
            }
          }
        }
        resulta.pLocalFrame = 0;
      }
      if ( v17 )
      {
        pNode = penva->pNode;
        v22 = result;
        result->pNode = penva->pNode;
        ++pNode->RefCount;
        return v22;
      }
      goto LABEL_48;
    }
    if ( v15->T.Type == 6 && Scaleform::GFx::AS2::Value::ToObject(v15, penv) == p_pProto )
    {
      v29 = *p_SizeMask;
      v22 = result;
      result->pNode = *p_SizeMask;
      ++v29->RefCount;
      return v22;
    }
    if ( v15->T.Type == 8 || v15->T.Type == 11 )
      break;
LABEL_48:
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::ConstIterator::operator++(&v37);
    Index = v37.Index;
    pHash = v37.pHash;
  }
  Scaleform::GFx::AS2::Value::ToFunction(v15, &v39, penv);
  pMovieRoot = this->pMovieRoot;
  v24 = v39.Function;
  v40.T.Type = 0;
  if ( !v39.Function->GetMemberRaw(
          &v39.Function->Scaleform::GFx::AS2::ObjectInterface,
          &penv->StringContext,
          (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
          &v40)
    || v40.T.Type != 6
    || Scaleform::GFx::AS2::Value::ToObject(&v40, penv) != p_pProto )
  {
    if ( v40.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v40);
    Flags = v39.Flags;
    if ( (v39.Flags & 2) == 0 )
    {
      v26 = v24->RefCount;
      if ( (v26 & 0x3FFFFFF) != 0 )
      {
        v24->RefCount = v26 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
    v39.Function = 0;
    if ( (Flags & 1) == 0 )
    {
      v27 = v39.pLocalFrame;
      if ( v39.pLocalFrame )
      {
        v28 = v39.pLocalFrame->RefCount;
        if ( (v28 & 0x3FFFFFF) != 0 )
        {
          v39.pLocalFrame->RefCount = v28 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
        }
      }
    }
    v39.pLocalFrame = 0;
    goto LABEL_48;
  }
  Scaleform::GFx::ASString::operator+(penva, result, (const __m128i *)".prototype");
  if ( v40.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v40);
  v30 = v39.Flags;
  if ( (v39.Flags & 2) == 0 )
  {
    if ( v24 )
    {
      v31 = v24->RefCount;
      if ( (v31 & 0x3FFFFFF) != 0 )
      {
        v24->RefCount = v31 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
  }
  if ( (v30 & 1) == 0 )
  {
    v32 = v39.pLocalFrame;
    if ( v39.pLocalFrame )
    {
      v33 = v39.pLocalFrame->RefCount;
      if ( (v33 & 0x3FFFFFF) != 0 )
      {
        v39.pLocalFrame->RefCount = v33 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
      }
    }
  }
  return result;
}
