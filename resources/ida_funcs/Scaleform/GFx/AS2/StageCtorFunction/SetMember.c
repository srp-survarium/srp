char __thiscall Scaleform::GFx::AS2::StageCtorFunction::SetMember(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  bool v5; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v7; // esi
  const Scaleform::GFx::ASString *v8; // ebp
  bool v9; // zf
  bool v10; // bl
  const Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // ebp
  bool v16; // bl
  int v17; // esi
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // esi
  bool v20; // bl
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // esi
  bool v23; // bl
  bool v25; // bl
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // esi
  bool v28; // zf
  bool v29; // bl
  Scaleform::GFx::ASStringNode *v30; // eax
  unsigned int v31; // esi
  unsigned int Length; // edi
  unsigned int CharAt; // ebx
  int v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax

  v5 = penv->StringContext.SWFVersion > 6u;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "scaleMode",
                      9u,
                      0);
  v7 = ConstStringNode;
  ++ConstStringNode->RefCount;
  if ( v5 )
  {
    v8 = name;
    v9 = ConstStringNode == name->pNode;
  }
  else
  {
    if ( !ConstStringNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
    v8 = name;
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v9 = v7->pLower == v8->pNode->pLower;
  }
  v10 = v9;
  v9 = v7->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v10 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&val, penv, -1, 0);
    v11 = (const Scaleform::GFx::ASString *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->ResolveHandler.Flags + 56))(*(_DWORD *)&this->ResolveHandler.Flags);
    pMovieRoot = penv->StringContext.pContext->pMovieRoot;
    name = (Scaleform::GFx::ASString *)v11;
    v13 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "noScale",
            7u,
            0);
    v14 = v13;
    ++v13->RefCount;
    if ( !v13->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v13);
    v15 = (Scaleform::GFx::ASStringNode *)val;
    if ( !val->V.FunctionValue.pLocalFrame )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)val);
    v16 = v14->pLower == v15->pLower;
    v9 = v14->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    if ( v16 )
    {
      v17 = 0;
    }
    else
    {
      v18 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
              (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
              "exactFit",
              8u,
              0);
      v19 = v18;
      ++v18->RefCount;
      if ( !v18->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v18);
      if ( !v15->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15);
      v20 = v19->pLower == v15->pLower;
      v9 = v19->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( v20 )
      {
        v17 = 2;
      }
      else
      {
        v21 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                "noBorder",
                8u,
                0);
        v22 = v21;
        ++v21->RefCount;
        if ( !v21->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v21);
        if ( !v15->pLower )
          Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v15);
        v23 = v22->pLower == v15->pLower;
        v9 = v22->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        v17 = 2 * v23 + 1;
      }
    }
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->ResolveHandler.Flags + 52))(
      *(_DWORD *)&this->ResolveHandler.Flags,
      v17);
    if ( name != (Scaleform::GFx::ASString *)v17 && !v17 )
      Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize(
        (Scaleform::GFx::AS2::StageCtorFunction *)((char *)this - 16),
        penv);
    v9 = v15->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    return 1;
  }
  v25 = penv->StringContext.SWFVersion > 6u;
  v26 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
          (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
          "align",
          5u,
          0);
  v27 = v26;
  ++v26->RefCount;
  if ( v25 )
  {
    v28 = v26 == v8->pNode;
  }
  else
  {
    if ( !v26->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v26);
    if ( !v8->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v8->pNode);
    v28 = v27->pLower == v8->pNode->pLower;
  }
  v29 = v28;
  v9 = v27->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( !v29 )
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, v8, val, flags);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, penv, -1, 0);
  val = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::ASConstString::ToUpperNode((Scaleform::GFx::ASConstString *)&name);
  ++*((_DWORD *)&val->NV + 3);
  v30 = (Scaleform::GFx::ASStringNode *)name;
  --name[3].pNode;
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  v31 = 0;
  Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&val);
  if ( !Length )
    goto LABEL_75;
  CharAt = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&val, 0);
  if ( Length >= 2 )
    v31 = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&val, (const char *)1);
  if ( CharAt != 84 )
  {
    switch ( CharAt )
    {
      case 'L':
        if ( v31 == 84 )
          goto LABEL_61;
        if ( v31 != 66 )
        {
          v34 = 3;
          goto LABEL_76;
        }
LABEL_70:
        v34 = 7;
        goto LABEL_76;
      case 'R':
        if ( v31 == 84 )
          goto LABEL_64;
        if ( v31 != 66 )
        {
          v34 = 4;
          goto LABEL_76;
        }
        goto LABEL_72;
      case 'B':
        if ( v31 == 76 )
          goto LABEL_70;
        if ( v31 != 82 )
        {
          v34 = 2;
          goto LABEL_76;
        }
LABEL_72:
        v34 = 8;
        goto LABEL_76;
    }
LABEL_75:
    v34 = 0;
    goto LABEL_76;
  }
  if ( v31 == 76 )
  {
LABEL_61:
    v34 = 5;
    goto LABEL_76;
  }
  if ( v31 == 82 )
  {
LABEL_64:
    v34 = 6;
    goto LABEL_76;
  }
  v34 = 1;
LABEL_76:
  (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->ResolveHandler.Flags + 60))(
    *(_DWORD *)&this->ResolveHandler.Flags,
    v34);
  v35 = (Scaleform::GFx::ASStringNode *)val;
  --*((_DWORD *)&val->NV + 3);
  if ( v35->RefCount )
    return 1;
  Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  return 1;
}
