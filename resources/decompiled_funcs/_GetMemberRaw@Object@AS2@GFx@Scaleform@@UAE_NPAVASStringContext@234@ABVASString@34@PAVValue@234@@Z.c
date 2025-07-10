char __thiscall Scaleform::GFx::AS2::Object::GetMemberRaw(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // esi
  Scaleform::GFx::AS2::Value *v5; // ebx
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::LocalFrame *v8; // edi
  signed int v9; // eax
  int v10; // eax
  Scaleform::GFx::AS2::LocalFrame *v11; // eax
  Scaleform::GFx::AS2::Object *v13; // esi
  Scaleform::GFx::AS2::Value *v14; // ecx
  const Scaleform::GFx::AS2::FunctionRefBase *v15; // esi
  int v16; // eax
  bool v17; // zf
  const Scaleform::GFx::AS2::Value *v18; // eax
  const Scaleform::GFx::ASString *v19; // ebx
  Scaleform::GFx::ASStringNode *v20; // ecx
  Scaleform::GFx::AS2::Value *v21; // ebp
  Scaleform::GFx::ASMovieRootBase *v22; // eax
  Scaleform::GFx::ASStringNode *pLower; // ecx
  Scaleform::GFx::AS2::LocalFrame *v24; // ecx
  int *v25; // edi
  signed int v26; // eax
  int v27; // ecx
  int v28; // eax
  Scaleform::GFx::AS2::LocalFrame *v29; // eax
  int v30; // eax
  const Scaleform::GFx::AS2::Value *v31; // eax
  bool resolveHandlerSet; // [esp+13h] [ebp-5h]

  p_pLocalFrame = &this[-1].ResolveHandler.pLocalFrame;
  resolveHandlerSet = 0;
  if ( psc->SWFVersion > 6u )
  {
    if ( this != (Scaleform::GFx::AS2::Object *)16 )
    {
      v5 = val;
      while ( 1 )
      {
        pObject = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
        pNode = name->pNode;
        if ( name->pNode == *(Scaleform::GFx::ASStringNode **)&pObject[23].AVMVersion )
          break;
        if ( pNode == (Scaleform::GFx::ASStringNode *)pObject[24].pASSupport.pObject )
        {
          v15 = (const Scaleform::GFx::AS2::FunctionRefBase *)(p_pLocalFrame + 8);
          v14 = v5;
          if ( v15->Function )
          {
LABEL_22:
            Scaleform::GFx::AS2::Value::SetAsFunction(v14, v15);
            return 1;
          }
LABEL_20:
          Scaleform::GFx::AS2::Value::DropRefs(v14);
          v5->T.Type = 0;
          return 1;
        }
        v8 = p_pLocalFrame[7];
        if ( v8 )
        {
          v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                 (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_pLocalFrame
               + 7,
                 name,
                 (int)v8->pRCC & pNode->HashFlags);
          if ( v9 >= 0 && v9 <= (int)v8->pRCC )
          {
            v16 = 3 * v9;
            v17 = LOBYTE((&v8->Variables.mHash.pTable)[2 * v16]) == 10;
            v18 = (const Scaleform::GFx::AS2::Value *)(&v8->Variables + 2 * v16);
            if ( v17 && p_pLocalFrame != &this[-1].ResolveHandler.pLocalFrame )
              return ((int (__thiscall *)(char *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))p_pLocalFrame[4]->Callee.V.pStringNode)(
                       (char *)p_pLocalFrame + 16,
                       psc,
                       name,
                       v5);
            Scaleform::GFx::AS2::Value::operator=(v5, v18);
            return 1;
          }
        }
        if ( !resolveHandlerSet && p_pLocalFrame[8] )
        {
          Scaleform::GFx::AS2::Value::DropRefs(v5);
          v5->T.Type = 12;
          v5->V.FunctionValue.Flags = 0;
          v10 = (int)p_pLocalFrame[8];
          v5->NV.Int32Value = v10;
          if ( v10 )
            *(_DWORD *)(v10 + 12) = (*(_DWORD *)(v10 + 12) + 1) & 0x8FFFFFFF;
          v5->V.FunctionValue.pLocalFrame = 0;
          v11 = p_pLocalFrame[9];
          if ( v11 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v5->V.FunctionValue, v11, (_BYTE)p_pLocalFrame[10] & 1);
          resolveHandlerSet = 1;
        }
        p_pLocalFrame = (Scaleform::GFx::AS2::LocalFrame **)p_pLocalFrame[6];
        if ( !p_pLocalFrame )
          return 0;
      }
      v13 = (Scaleform::GFx::AS2::Object *)p_pLocalFrame[6];
      v14 = v5;
      if ( v13 )
        goto LABEL_19;
      goto LABEL_20;
    }
    return 0;
  }
  v19 = name;
  if ( !name->pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
  v20 = v19->pNode;
  v17 = v19->pNode->pLower == 0;
  name = v19;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v20);
  if ( !p_pLocalFrame )
    return 0;
  v21 = val;
  while ( 1 )
  {
    v22 = psc->pContext->pMovieRoot->pASMovieRoot.pObject;
    pLower = v19->pNode->pLower;
    if ( *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)&v22[23].AVMVersion + 8) == pLower )
    {
      v13 = (Scaleform::GFx::AS2::Object *)p_pLocalFrame[6];
      v14 = v21;
      if ( v13 )
      {
LABEL_19:
        Scaleform::GFx::AS2::Value::SetAsObject(v14, v13);
        return 1;
      }
      goto LABEL_49;
    }
    if ( (Scaleform::GFx::ASStringNode *)v22[24].pASSupport.pObject->SType == pLower )
    {
      v15 = (const Scaleform::GFx::AS2::FunctionRefBase *)(p_pLocalFrame + 8);
      v14 = v21;
      if ( v15->Function )
        goto LABEL_22;
LABEL_49:
      Scaleform::GFx::AS2::Value::DropRefs(v14);
      v21->T.Type = 0;
      return 1;
    }
    v24 = p_pLocalFrame[7];
    v25 = (int *)(p_pLocalFrame + 7);
    if ( v24 )
    {
      v26 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_pLocalFrame
            + 7,
              (const Scaleform::GFx::ASString::NoCaseKey *)&name,
              (int)v24->pRCC & v19->pNode->HashFlags);
      if ( v26 >= 0 )
      {
        v27 = *v25;
        if ( *v25 )
        {
          if ( v26 <= *(_DWORD *)(v27 + 4) )
            break;
        }
      }
    }
    if ( !resolveHandlerSet && p_pLocalFrame[8] )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v21);
      v21->T.Type = 12;
      v21->V.FunctionValue.Flags = 0;
      v28 = (int)p_pLocalFrame[8];
      v21->NV.Int32Value = v28;
      if ( v28 )
        *(_DWORD *)(v28 + 12) = (*(_DWORD *)(v28 + 12) + 1) & 0x8FFFFFFF;
      v21->V.FunctionValue.pLocalFrame = 0;
      v29 = p_pLocalFrame[9];
      if ( v29 )
        Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v21->V.FunctionValue, v29, (_BYTE)p_pLocalFrame[10] & 1);
      resolveHandlerSet = 1;
    }
    p_pLocalFrame = (Scaleform::GFx::AS2::LocalFrame **)p_pLocalFrame[6];
    if ( !p_pLocalFrame )
      return 0;
  }
  v30 = 3 * v26;
  v17 = *(_BYTE *)(v27 + 8 * v30 + 16) == 10;
  v31 = (const Scaleform::GFx::AS2::Value *)(v27 + 8 * v30 + 16);
  if ( v17 && p_pLocalFrame != &this[-1].ResolveHandler.pLocalFrame )
    return ((int (__thiscall *)(char *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))p_pLocalFrame[4]->Callee.V.pStringNode)(
             (char *)p_pLocalFrame + 16,
             psc,
             v19,
             v21);
  Scaleform::GFx::AS2::Value::operator=(v21, v31);
  return 1;
}
