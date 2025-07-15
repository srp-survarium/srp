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
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::ConstIterator it; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FunctionRef v38; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRef f; // [esp+2Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value protoVal; // [esp+38h] [ebp-10h] BYREF
  Scaleform::GFx::ASString *nm; // [esp+50h] [ebp+8h]
  Scaleform::GFx::AS2::Object *obj; // [esp+54h] [ebp+Ch]

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
      obj = (Scaleform::GFx::AS2::Object *)(*(int (**)(void))(MEMORY[0] + 104))();
    else
      obj = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))iobj[-1].pProto.pObject[2].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable)(&iobj[-1].pProto);
  }
  else if ( (unsigned int)(GetObjectType(iobj) - 6) > 0x26 )
  {
    obj = 0;
  }
  else
  {
    obj = (Scaleform::GFx::AS2::Object *)&iobj[-2].pProto;
  }
  v7 = Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Begin(
         &v4->pGlobal.pObject->Members,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&v38);
  pHash = v7->pHash;
  Index = v7->Index;
  Function = v38.Function;
  it.pHash = pHash;
  it.Index = Index;
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
    nm = (Scaleform::GFx::ASString *)&v13[1].SizeMask;
    if ( obj->GetObjectType(&obj->Scaleform::GFx::AS2::ObjectInterface) == Object_Function )
    {
      v17 = 0;
      if ( v15->T.Type == 8 || v15->T.Type == 11 )
      {
        v35 |= 1u;
        v16 = Scaleform::GFx::AS2::Value::ToFunction(v15, &v38, penv);
        Function = v38.Function;
        if ( v16->Function == obj )
          v17 = 1;
      }
      if ( (v35 & 1) != 0 )
      {
        v35 &= ~1u;
        if ( (v38.Flags & 2) == 0 )
        {
          if ( Function )
          {
            RefCount = Function->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
            {
              Function->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            }
          }
        }
        Function = 0;
        v38.Function = 0;
        if ( (v38.Flags & 1) == 0 )
        {
          pLocalFrame = v38.pLocalFrame;
          if ( v38.pLocalFrame )
          {
            v20 = v38.pLocalFrame->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v20) != 0 )
            {
              v38.pLocalFrame->RefCount = v20 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              Function = v38.Function;
            }
          }
        }
        v38.pLocalFrame = 0;
      }
      if ( v17 )
      {
        pNode = nm->pNode;
        v22 = result;
        result->pNode = nm->pNode;
        ++pNode->RefCount;
        return v22;
      }
      goto LABEL_48;
    }
    if ( v15->T.Type == 6 && Scaleform::GFx::AS2::Value::ToObject(v15, penv) == obj )
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
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::ConstIterator::operator++(&it);
    Index = it.Index;
    pHash = it.pHash;
  }
  Scaleform::GFx::AS2::Value::ToFunction(v15, &f, penv);
  pMovieRoot = this->pMovieRoot;
  v24 = f.Function;
  protoVal.T.Type = 0;
  if ( !f.Function->GetMemberRaw(
          &f.Function->Scaleform::GFx::AS2::ObjectInterface,
          &penv->StringContext,
          (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
          &protoVal)
    || protoVal.T.Type != 6
    || Scaleform::GFx::AS2::Value::ToObject(&protoVal, penv) != obj )
  {
    if ( protoVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&protoVal);
    Flags = f.Flags;
    if ( (f.Flags & 2) == 0 )
    {
      v26 = v24->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v26) != 0 )
      {
        v24->RefCount = v26 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
    f.Function = 0;
    if ( (Flags & 1) == 0 )
    {
      v27 = f.pLocalFrame;
      if ( f.pLocalFrame )
      {
        v28 = f.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v28) != 0 )
        {
          f.pLocalFrame->RefCount = v28 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
        }
      }
    }
    f.pLocalFrame = 0;
    goto LABEL_48;
  }
  Scaleform::GFx::ASString::operator+(nm, result, ".prototype");
  if ( protoVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&protoVal);
  v30 = f.Flags;
  if ( (f.Flags & 2) == 0 )
  {
    if ( v24 )
    {
      v31 = v24->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v31) != 0 )
      {
        v24->RefCount = v31 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
  }
  if ( (v30 & 1) == 0 )
  {
    v32 = f.pLocalFrame;
    if ( f.pLocalFrame )
    {
      v33 = f.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v33) != 0 )
      {
        f.pLocalFrame->RefCount = v33 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
      }
    }
  }
  return result;
}
