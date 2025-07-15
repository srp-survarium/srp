char __thiscall Scaleform::GFx::AS2::Object::SetMemberRaw(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::ASStringContext *v5; // ebp
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::MovieImpl *v8; // esi
  Scaleform::GFx::ASStringNode **v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Object_vtbl *v11; // esi
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::FunctionRef *v13; // eax
  unsigned int v14; // edx
  Scaleform::GFx::AS2::FunctionObject *v15; // ecx
  unsigned int v16; // edx
  Scaleform::GFx::AS2::LocalFrame *v17; // ecx
  unsigned int v18; // eax
  unsigned int *p_RefCount; // edi
  const Scaleform::GFx::AS2::Member *v20; // eax
  unsigned int *pHash; // ecx
  Scaleform::GFx::MovieImpl *pMovieRoot; // edi
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::GFx::AS2::Object_vtbl *v25; // esi
  Scaleform::GFx::AS2::Object *v26; // eax
  Scaleform::GFx::AS2::FunctionRef *v27; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v30; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *CaseInsensitive; // eax
  bool v33; // zf
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v35; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v36; // esi
  unsigned int v37; // ecx
  char v38; // bl
  unsigned int v39; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  unsigned __int8 v44; // bl
  Scaleform::GFx::AS2::Value *v; // [esp+Ch] [ebp-28h]
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef v46; // [esp+10h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+18h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v48; // [esp+24h] [ebp-10h] BYREF

  v5 = psc;
  v = val;
  if ( !BYTE1(this->ResolveHandler.Function)
    && val->T.Type == 6
    && name->pNode == (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl )
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
    if ( v7 )
    {
      if ( v7->GetObjectType(&v7->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
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
    if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&pObject[23].AVMVersion + 8) != pLower )
    {
      if ( (Scaleform::GFx::ASStringNode *)pObject[24].pASSupport.pObject->SType == pLower )
      {
        if ( val->T.Type != 10 )
        {
          v27 = Scaleform::GFx::AS2::Value::ToFunction(val, &result, 0);
          Scaleform::GFx::AS2::FunctionRefBase::Assign(
            (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::ObjectInterface,
            v27);
          if ( (result.Flags & 2) == 0 )
          {
            if ( result.Function )
            {
              RefCount = result.Function->RefCount;
              Function = result.Function;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                result.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          result.Function = 0;
          if ( (result.Flags & 1) == 0 )
          {
            if ( result.pLocalFrame )
            {
              v30 = result.pLocalFrame->RefCount;
              pLocalFrame = result.pLocalFrame;
              if ( (v30 & 0x3FFFFFF) != 0 )
              {
                result.pLocalFrame->RefCount = v30 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
        }
        v = &notsetVal;
      }
      else if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[28].pASSupport.pObject && psc->pContext )
      {
        pMovieRoot->Flags |= 0x80000u;
      }
      v5 = psc;
      goto LABEL_54;
    }
    if ( val->T.Type == 10 )
    {
      v5 = psc;
    }
    else
    {
      v25 = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
      v26 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
      v5 = psc;
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v25[1].GetValue)(
        this,
        psc,
        v26);
      if ( psc->pContext )
      {
        psc->pContext->pMovieRoot->Flags |= 0x80000u;
        v = &notsetVal;
LABEL_54:
        p_RefCount = &this->RefCount;
        CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseInsensitive(
                            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->RefCount,
                            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&result,
                            name);
        pHash = (unsigned int *)CaseInsensitive->pHash;
        v46.pSecond = (const Scaleform::GFx::AS2::Member *)CaseInsensitive->Index;
        goto LABEL_55;
      }
    }
    v = &notsetVal;
    goto LABEL_54;
  }
  v8 = psc->pContext->pMovieRoot;
  v9 = (Scaleform::GFx::ASStringNode **)v8->pASMovieRoot.pObject;
  pNode = name->pNode;
  if ( name->pNode == v9[119] )
  {
    if ( val->T.Type != 10 )
    {
      v11 = this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
      v12 = Scaleform::GFx::AS2::Value::ToObject(val, 0);
      ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v11[1].GetValue)(
        this,
        psc,
        v12);
      if ( psc->pContext )
        psc->pContext->pMovieRoot->Flags |= 0x80000u;
    }
    v = &notsetVal;
  }
  else if ( pNode == v9[123] )
  {
    if ( val->T.Type != 10 )
    {
      v13 = Scaleform::GFx::AS2::Value::ToFunction(val, &result, 0);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::ObjectInterface,
        v13);
      if ( (result.Flags & 2) == 0 )
      {
        if ( result.Function )
        {
          v14 = result.Function->RefCount;
          v15 = result.Function;
          if ( (v14 & 0x3FFFFFF) != 0 )
          {
            result.Function->RefCount = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
          }
        }
      }
      result.Function = 0;
      if ( (result.Flags & 1) == 0 )
      {
        if ( result.pLocalFrame )
        {
          v16 = result.pLocalFrame->RefCount;
          v17 = result.pLocalFrame;
          if ( (v16 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v16 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
          }
        }
      }
    }
    v = &notsetVal;
  }
  else if ( pNode == v9[143] && psc->pContext )
  {
    v8->Flags |= 0x80000u;
  }
  v18 = this->RefCount;
  p_RefCount = &this->RefCount;
  if ( v18
    && (v20 = (const Scaleform::GFx::AS2::Member *)Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                                                     (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->RefCount,
                                                     name,
                                                     *(_DWORD *)(v18 + 4) & name->pNode->HashFlags),
        (int)v20 >= 0) )
  {
    pHash = &this->RefCount;
    v46.pSecond = v20;
  }
  else
  {
    pHash = 0;
    v46.pSecond = 0;
  }
LABEL_55:
  v33 = val->T.Type == 9;
  v46.pFirst = (const Scaleform::GFx::ASString *)pHash;
  if ( v33 )
    LOBYTE(this->ResolveHandler.Function) = 1;
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsEnabled(Instance) )
  {
    if ( name->pNode->Size )
    {
      v35 = Scaleform::AmpServer::GetInstance();
      if ( v35->GetProfileLevel(v35) >= Amp_Profile_Level_Medium )
      {
        Scaleform::GFx::AS2::Value::ToFunction(v, (Scaleform::GFx::AS2::FunctionRef *)&v48, 0);
        v36 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v48.T.Type;
        if ( *(_DWORD *)&v48.T.Type )
        {
          if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&v48.T.Type + 56))(*(_DWORD *)&v48.T.Type) )
          {
            v37 = (unsigned int)v36[5].__vftable;
            if ( v37 )
              Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
                v5->pContext->pMovieRoot->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject,
                *(Scaleform::RefCountVImpl **)(*(_DWORD *)(v36[3].RefCount + 8) + 16),
                *(_DWORD *)(*(_DWORD *)(v36[3].RefCount + 8) + 20) + v36[4].RefCount,
                (const __m128i *)name->pNode->pData,
                v37,
                2u,
                0);
          }
        }
        v38 = BYTE4(v48.NV.NumberValue);
        if ( (BYTE4(v48.NV.NumberValue) & 2) == 0 )
        {
          if ( v36 )
          {
            v39 = v36->RefCount;
            if ( (v39 & 0x3FFFFFF) != 0 )
            {
              v36->RefCount = v39 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
            }
          }
        }
        if ( (v38 & 1) == 0 )
        {
          pStringNode = v48.V.pStringNode;
          if ( v48.NV.Int32Value )
          {
            v41 = *(_DWORD *)(v48.NV.Int32Value + 12);
            if ( (v41 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(v48.NV.Int32Value + 12) = v41 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
      }
    }
  }
  if ( v46.pFirst && (v42 = v46.pFirst->pNode) != 0 && (int)v46.pSecond <= (int)v42->pManager )
  {
    Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&v42[(int)v46.pSecond].HashFlags, v);
    return 1;
  }
  else
  {
    v44 = flags->Flags;
    Scaleform::GFx::AS2::Value::Value(&v48, v);
    v46.pFirst = name;
    v48.T.PropFlags = v44;
    v46.pSecond = (const Scaleform::GFx::AS2::Member *)&v48;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_RefCount,
      (Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> *)p_RefCount,
      &v46);
    if ( v48.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v48);
    return 1;
  }
}
