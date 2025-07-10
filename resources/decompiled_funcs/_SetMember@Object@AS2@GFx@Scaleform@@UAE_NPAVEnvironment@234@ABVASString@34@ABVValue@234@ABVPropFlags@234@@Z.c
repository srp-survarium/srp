char __thiscall Scaleform::GFx::AS2::Object::SetMember(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *pHash; // eax
  unsigned int i; // ebp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // eax
  const Scaleform::GFx::AS2::Value *v10; // ecx
  int v12; // eax
  Scaleform::RefCountNTSImpl *v13; // ebp
  int v14; // eax
  Scaleform::GFx::AS2::ObjectInterface *v15; // eax
  bool v16; // zf
  Scaleform::GFx::AS2::Value *v17; // ebp
  char v18; // bl
  Scaleform::GFx::ASMovieRootBase *v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::Value *(__thiscall **v21)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Value *); // ebx
  Scaleform::GFx::AS2::Object *v22; // eax
  Scaleform::GFx::InteractiveObject *v23; // esi
  unsigned int *v24; // eax
  Scaleform::GFx::InteractiveObject *v25; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // eax
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::GFx::AS2::Value *(__thiscall **p_GetValue)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Value *); // ebx
  Scaleform::GFx::AS2::Object *v30; // eax
  Scaleform::GFx::InteractiveObject *Target; // esi
  unsigned int *p_Flags; // eax
  Scaleform::GFx::AS2::FunctionRef *v33; // eax
  int v34; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v35; // ecx
  int v36; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::InteractiveObject *v38; // esi
  bool v39; // [esp-4h] [ebp-40h]
  Scaleform::GFx::AS2::PropFlags _flags; // [esp+13h] [ebp-29h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator it; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value propVal; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value newVal; // [esp+2Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS2::Member *pmember; // [esp+40h] [ebp+4h]

  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    notsetVal_0.T.Type = 10;
    atexit(Scaleform::GFx::AS2::Object::SetMember_::_2_::_dynamic_atexit_destructor_for__notsetVal__);
  }
  v39 = penv->StringContext.SWFVersion > 6u;
  _flags.Flags = 0;
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
    (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)&this->RefCount,
    &it,
    name,
    v39);
  pHash = it.pHash;
  if ( !it.pHash || !it.pHash->pTable || it.Index > (signed int)it.pHash->pTable->SizeMask )
  {
    for ( i = this->RootIndex; i; i = *(_DWORD *)(i + 24) )
    {
      if ( *(_BYTE *)(i + 48) )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(i + 28),
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&propVal,
          name,
          penv->StringContext.SWFVersion > 6u);
        if ( *(_DWORD *)&propVal.T.Type
          && **(_DWORD **)&propVal.T.Type
          && propVal.NV.Int32Value <= *(_DWORD *)(**(_DWORD **)&propVal.T.Type + 4) )
        {
          if ( *(_BYTE *)(**(_DWORD **)&propVal.T.Type + 24 * propVal.NV.Int32Value + 16) == 9 )
            it = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&propVal.T.Type;
          pHash = it.pHash;
          break;
        }
        pHash = it.pHash;
      }
    }
  }
  if ( pHash && pHash->pTable && (pTable = pHash->pTable, it.Index <= (signed int)pTable->SizeMask) )
  {
    v10 = (const Scaleform::GFx::AS2::Value *)&pTable[3 * it.Index + 2];
    pmember = (Scaleform::GFx::AS2::Member *)v10;
    _flags.Flags = BYTE1(pTable[3 * it.Index + 2].EntryCount);
    if ( (_flags.Flags & 4) != 0 )
      return 0;
    if ( v10->T.Type == 9 )
    {
      Scaleform::GFx::AS2::Value::Value(&propVal, v10);
      v12 = ((int (__thiscall *)(Scaleform::GFx::AS2::LocalFrame **))this[-1].ResolveHandler.pLocalFrame->Env)(&this[-1].ResolveHandler.pLocalFrame);
      v13 = (Scaleform::RefCountNTSImpl *)v12;
      if ( v12 )
      {
        ++*(_DWORD *)(v12 + 4);
        v14 = (*(int (__thiscall **)(int))(*(_DWORD *)(v12 + 4 * *(unsigned __int8 *)(v12 + 65)) + 4))(v12 + 4 * *(unsigned __int8 *)(v12 + 65));
        if ( v14 )
          v15 = (Scaleform::GFx::AS2::ObjectInterface *)(v14 + 4);
        else
          v15 = 0;
        Scaleform::GFx::AS2::Value::SetPropertyValue(&propVal, penv, v15, val);
        Scaleform::RefCountNTSImpl::Release(v13);
      }
      else
      {
        Scaleform::GFx::AS2::Value::SetPropertyValue(
          &propVal,
          penv,
          this != (Scaleform::GFx::AS2::Object *)16 ? (Scaleform::GFx::AS2::ObjectInterface *)this : 0,
          val);
      }
      if ( propVal.T.Type >= 5u )
      {
        Scaleform::GFx::AS2::Value::DropRefs(&propVal);
        return 1;
      }
      return 1;
    }
  }
  else
  {
    _flags.Flags = flags->Flags;
    pmember = 0;
  }
  v16 = this->Members.mHash.pTable == 0;
  v17 = val;
  newVal.T.Type = 0;
  if ( !v16
    && Scaleform::GFx::AS2::Object::InvokeWatchpoint(
         (Scaleform::GFx::AS2::Object *)((char *)this - 16),
         penv,
         name,
         val,
         &newVal) )
  {
    val = &newVal;
  }
  if ( pmember )
  {
    if ( v17->T.Type == 9 )
      LOBYTE(this->ResolveHandler.Function) = 1;
    if ( penv->StringContext.SWFVersion <= 6u )
    {
      if ( !name->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
      pObject = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      pLower = name->pNode->pLower;
      if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&pObject[23].AVMVersion + 8) == pLower )
      {
        if ( v17->T.Type != 10 )
        {
          p_GetValue = &this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue;
          v30 = Scaleform::GFx::AS2::Value::ToObject(v17, penv);
          ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))*p_GetValue)(
            this,
            &penv->StringContext,
            v30);
          Target = penv->Target;
          if ( Target )
          {
            p_Flags = &Target->pASRoot->pMovieImpl->Flags;
            *p_Flags |= 0x80000u;
          }
        }
        val = &notsetVal_0;
        goto LABEL_74;
      }
      if ( (Scaleform::GFx::ASStringNode *)pObject[24].pASSupport.pObject->SType == pLower )
      {
        if ( v17->T.Type != 10 )
          goto LABEL_61;
        goto LABEL_69;
      }
      if ( name->pNode == (Scaleform::GFx::ASStringNode *)pObject[28].pASSupport.pObject )
      {
        v38 = penv->Target;
        if ( v38 )
        {
          pMovieImpl = v38->pASRoot->pMovieImpl;
          goto LABEL_73;
        }
      }
    }
    else
    {
      v19 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      pNode = name->pNode;
      if ( name->pNode == *(Scaleform::GFx::ASStringNode **)&v19[23].AVMVersion )
      {
        if ( v17->T.Type != 10 )
        {
          v21 = &this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetValue;
          v22 = Scaleform::GFx::AS2::Value::ToObject(v17, penv);
          ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))*v21)(
            this,
            &penv->StringContext,
            v22);
          v23 = penv->Target;
          if ( v23 )
          {
            v24 = &v23->pASRoot->pMovieImpl->Flags;
            *v24 |= 0x80000u;
            val = &notsetVal_0;
            goto LABEL_74;
          }
        }
        goto LABEL_69;
      }
      if ( pNode == (Scaleform::GFx::ASStringNode *)v19[24].pASSupport.pObject )
      {
        if ( v17->T.Type != 10 )
        {
LABEL_61:
          v33 = Scaleform::GFx::AS2::Value::ToFunction(v17, (Scaleform::GFx::AS2::FunctionRef *)&propVal, penv);
          Scaleform::GFx::AS2::FunctionRefBase::Assign(
            (Scaleform::GFx::AS2::FunctionRefBase *)&this->Scaleform::GFx::AS2::ObjectInterface,
            v33);
          if ( (BYTE4(propVal.NV.NumberValue) & 2) == 0 )
          {
            if ( *(_DWORD *)&propVal.T.Type )
            {
              v34 = *(_DWORD *)(*(_DWORD *)&propVal.T.Type + 12);
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v34) != 0 )
              {
                v35 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&propVal.T.Type;
                *(_DWORD *)(*(_DWORD *)&propVal.T.Type + 12) = v34 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v35);
              }
            }
          }
          *(_DWORD *)&propVal.T.Type = 0;
          if ( (BYTE4(propVal.NV.NumberValue) & 1) == 0 )
          {
            if ( propVal.NV.Int32Value )
            {
              v36 = *(_DWORD *)(propVal.NV.Int32Value + 12);
              pStringNode = propVal.V.pStringNode;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v36) != 0 )
              {
                *(_DWORD *)(propVal.NV.Int32Value + 12) = v36 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
              }
            }
          }
        }
LABEL_69:
        val = &notsetVal_0;
        goto LABEL_74;
      }
      if ( pNode == (Scaleform::GFx::ASStringNode *)v19[28].pASSupport.pObject )
      {
        v25 = penv->Target;
        if ( v25 )
        {
          pMovieImpl = v25->pASRoot->pMovieImpl;
LABEL_73:
          pMovieImpl->Flags |= 0x80000u;
        }
      }
    }
LABEL_74:
    Scaleform::GFx::AS2::Value::operator=(&pmember->mValue, val);
    if ( newVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&newVal);
    return 1;
  }
  v18 = ((int (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].Finalize_GC)(
          this,
          &penv->StringContext,
          name,
          val,
          &_flags);
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v18;
}
