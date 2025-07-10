char __thiscall Scaleform::GFx::AS2::Object::SetMemberRaw(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  bool v6; // zf
  Scaleform::GFx::AS2::Value *v7; // ebp
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::MovieImpl *v9; // ebx
  Scaleform::GFx::ASStringNode **v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Object_vtbl *v12; // ebx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::FunctionRef *v14; // eax
  int v15; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // ecx
  unsigned int v17; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // ecx
  unsigned int v19; // eax
  unsigned int *p_RefCount; // esi
  signed int Index; // eax
  unsigned int *pHash; // ecx
  Scaleform::GFx::MovieImpl *pMovieRoot; // ebp
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::GFx::AS2::Object_vtbl *v26; // ebx
  Scaleform::GFx::AS2::Object *v27; // eax
  Scaleform::GFx::AS2::FunctionRef *v28; // eax
  int v29; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v32; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *CaseInsensitive; // eax
  unsigned int v34; // ecx
  unsigned __int8 v36; // bl
  const Scaleform::GFx::AS2::Value *pval; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v38; // [esp+18h] [ebp-18h]
  char v39; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS2::Value v40; // [esp+20h] [ebp-10h] BYREF

  v6 = BYTE1(this->ResolveHandler.Function) == 0;
  v7 = val;
  pval = val;
  if ( v6
    && val->T.Type == 6
    && name->pNode == (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
    if ( v8 )
    {
      if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
        BYTE1(this->ResolveHandler.Function) = 1;
    }
  }
  if ( psc->SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    pMovieRoot = psc->pContext->pMovieRoot;
    pObject = pMovieRoot->pASMovieRoot.pObject;
    pLower = name->pNode->pLower;
    if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&pObject[23].AVMVersion + 8) == pLower )
    {
      if ( val->T.Type != 10 )
      {
        v26 = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
        v27 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v26[1].GetValue)(
          this,
          psc,
          v27);
        if ( psc->pContext )
          psc->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v7 = &notsetVal;
    }
    else if ( (Scaleform::GFx::ASStringNode *)pObject[24].pASSupport.pObject->SType == pLower )
    {
      if ( val->T.Type == 10 )
        goto LABEL_48;
      v28 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&pval, 0);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::ObjectInterface,
        v28);
      if ( (v39 & 2) == 0 )
      {
        if ( pval )
        {
          v29 = *((_DWORD *)&pval->NV + 3);
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v29) != 0 )
          {
            v30 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pval;
            *((_DWORD *)&pval->NV + 3) = v29 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
          }
        }
      }
      pval = 0;
      if ( (v39 & 1) != 0
        || !v38
        || (RefCount = v38->RefCount, ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) == 0) )
      {
LABEL_48:
        v7 = &notsetVal;
      }
      else
      {
        v32 = v38;
        v38->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v32);
        v7 = &notsetVal;
      }
    }
    else
    {
      if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[28].pASSupport.pObject && psc->pContext )
        pMovieRoot->Flags |= 0x80000u;
      v7 = (Scaleform::GFx::AS2::Value *)pval;
    }
    p_RefCount = &this->RefCount;
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseInsensitive(
                        (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->RefCount,
                        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&pval,
                        name);
    pHash = (unsigned int *)CaseInsensitive->pHash;
    Index = CaseInsensitive->Index;
  }
  else
  {
    v9 = psc->pContext->pMovieRoot;
    v10 = (Scaleform::GFx::ASStringNode **)v9->pASMovieRoot.pObject;
    pNode = name->pNode;
    if ( name->pNode == v10[119] )
    {
      if ( val->T.Type != 10 )
      {
        v12 = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
        v13 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
        ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v12[1].GetValue)(
          this,
          psc,
          v13);
        if ( psc->pContext )
          psc->pContext->pMovieRoot->Flags |= 0x80000u;
      }
      v7 = &notsetVal;
    }
    else if ( pNode == v10[123] )
    {
      if ( val->T.Type != 10 )
      {
        v14 = Scaleform::GFx::AS2::Value::ToFunction(val, (Scaleform::GFx::AS2::FunctionRef *)&pval, 0);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(
          (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::ObjectInterface,
          v14);
        if ( (v39 & 2) == 0 )
        {
          if ( pval )
          {
            v15 = *((_DWORD *)&pval->NV + 3);
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v15) != 0 )
            {
              v16 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pval;
              *((_DWORD *)&pval->NV + 3) = v15 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
            }
          }
        }
        pval = 0;
        if ( (v39 & 1) == 0 )
        {
          if ( v38 )
          {
            v17 = v38->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v17) != 0 )
            {
              v18 = v38;
              v38->RefCount = v17 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
            }
          }
        }
      }
      v7 = &notsetVal;
    }
    else if ( pNode == v10[143] && psc->pContext )
    {
      v9->Flags |= 0x80000u;
    }
    v19 = this->RefCount;
    p_RefCount = &this->RefCount;
    if ( v19
      && (Index = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->RefCount,
                    name,
                    *(_DWORD *)(v19 + 4) & name->pNode->HashFlags),
          Index >= 0) )
    {
      pHash = &this->RefCount;
    }
    else
    {
      pHash = 0;
      Index = 0;
    }
  }
  if ( val->T.Type == 9 )
    LOBYTE(this->ResolveHandler.Function) = 1;
  if ( pHash && (v34 = *pHash) != 0 && Index <= *(_DWORD *)(v34 + 4) )
  {
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)(v34 + 24 * Index + 16), v7);
    return 1;
  }
  else
  {
    v36 = flags->Flags;
    Scaleform::GFx::AS2::Value::Value(&v40, v7);
    v40.T.PropFlags = v36;
    pval = (const Scaleform::GFx::AS2::Value *)name;
    v38 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v40;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_RefCount,
      (Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_RefCount,
      (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&pval);
    if ( v40.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v40);
    return 1;
  }
}
