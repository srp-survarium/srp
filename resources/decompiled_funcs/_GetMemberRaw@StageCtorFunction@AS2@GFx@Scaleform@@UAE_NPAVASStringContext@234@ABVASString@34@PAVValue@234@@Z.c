char __thiscall Scaleform::GFx::AS2::StageCtorFunction::GetMemberRaw(
        Scaleform::GFx::AS2::StageCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        float name,
        Scaleform::GFx::AS2::Value *val)
{
  const Scaleform::GFx::ASString *v4; // ebp
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::MovieImpl **p_pMovieImpl; // esi
  bool v8; // zf
  double v9; // st7
  Scaleform::GFx::AS2::Value *v10; // esi
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *p_pASSupport; // esi
  bool v13; // zf
  bool v14; // bl
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v16; // esi
  bool v17; // zf
  bool v18; // bl
  int v19; // eax
  int v20; // eax
  char *v21; // edx
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS2::Value *v23; // edi
  Scaleform::GFx::ASStringNode *v24; // esi
  bool v25; // bl
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // esi
  bool v28; // zf
  bool v29; // bl
  char *v30; // edx
  const Scaleform::GFx::ASString *v31; // eax
  Scaleform::GFx::AS2::Value *v32; // ecx
  Scaleform::GFx::ASStringNode *v33; // esi
  Scaleform::GFx::AS2::StageCtorFunction *v34; // [esp+10h] [ebp-4h]

  v4 = (const Scaleform::GFx::ASString *)LODWORD(name);
  pNode = *(Scaleform::GFx::ASStringNode **)LODWORD(name);
  p_pMovieImpl = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl;
  v34 = this;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    pNode = v4->pNode;
    v8 = (*p_pMovieImpl)->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable == (Scaleform::GFx::StateBag_vtbl *)v4->pNode->pLower;
  }
  else
  {
    v8 = *p_pMovieImpl == (Scaleform::GFx::MovieImpl *)pNode;
  }
  if ( v8 )
  {
    name = *(float *)(*(_DWORD *)&this->ResolveHandler.Flags + 168)
         - *(float *)(*(_DWORD *)&this->ResolveHandler.Flags + 160);
    name = name * 0.05000000074505806;
    v9 = name;
LABEL_8:
    v10 = val;
    if ( val->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(val);
    v10->T.Type = 4;
    v10->NV.Int32Value = (int)v9;
    return 1;
  }
  p_pASSupport = &psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].pASSupport;
  if ( psc->SWFVersion <= 6u )
  {
    if ( !pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
    v13 = (Scaleform::GFx::ASStringNode *)p_pASSupport->pObject->SType == v4->pNode->pLower;
  }
  else
  {
    v13 = p_pASSupport->pObject == (Scaleform::GFx::ASSupport *)pNode;
  }
  if ( v13 )
  {
    name = *(float *)(*(_DWORD *)&this->ResolveHandler.Flags + 172)
         - *(float *)(*(_DWORD *)&this->ResolveHandler.Flags + 164);
    name = name * 0.05000000074505806;
    v9 = name;
    goto LABEL_8;
  }
  v14 = psc->SWFVersion > 6u;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                      "scaleMode",
                      9u,
                      0);
  v16 = ConstStringNode;
  ++ConstStringNode->RefCount;
  if ( v14 )
  {
    v17 = ConstStringNode == v4->pNode;
  }
  else
  {
    if ( !ConstStringNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(ConstStringNode);
    if ( !v4->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
    v17 = v16->pLower == v4->pNode->pLower;
  }
  v18 = v17;
  v8 = v16->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( v18 )
  {
    v19 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v34->ResolveHandler.Flags + 56))(*(_DWORD *)&v34->ResolveHandler.Flags);
    if ( v19 )
    {
      v20 = v19 - 2;
      if ( v20 )
      {
        if ( v20 == 1 )
          v21 = "noBorder";
        else
          v21 = "showAll";
      }
      else
      {
        v21 = "exactFit";
      }
    }
    else
    {
      v21 = "noScale";
    }
    v22 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            v21,
            strlen(v21),
            0);
    v23 = val;
    v24 = v22;
    ++v22->RefCount;
    if ( v23->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v23);
    v23->T.Type = 5;
    v23->NV.Int32Value = (int)v24;
    v8 = ++v24->RefCount == 1;
    --v24->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    return 1;
  }
  else
  {
    v25 = psc->SWFVersion > 6u;
    v26 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
            (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
            "align",
            5u,
            0);
    v27 = v26;
    ++v26->RefCount;
    if ( v25 )
    {
      v28 = v26 == v4->pNode;
    }
    else
    {
      if ( !v26->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v26);
      if ( !v4->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
      v28 = v27->pLower == v4->pNode->pLower;
    }
    v29 = v28;
    v8 = v27->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    if ( v29 )
    {
      switch ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v34->ResolveHandler.Flags + 64))(*(_DWORD *)&v34->ResolveHandler.Flags) )
      {
        case 1:
          v30 = "T";
          break;
        case 2:
          v30 = "B";
          break;
        case 3:
          v30 = "L";
          break;
        case 4:
          v30 = "R";
          break;
        case 5:
          v30 = "LT";
          break;
        case 6:
          v30 = "TR";
          break;
        case 7:
          v30 = "LB";
          break;
        case 8:
          v30 = "RB";
          break;
        default:
          v30 = (char *)&buf;
          break;
      }
      v31 = (const Scaleform::GFx::ASString *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                v30,
                                                strlen(v30),
                                                0);
      v32 = val;
      v33 = (Scaleform::GFx::ASStringNode *)v31;
      ++v31[3].pNode;
      name = *(float *)&v31;
      Scaleform::GFx::AS2::Value::SetString(v32, (const Scaleform::GFx::ASString *)&name);
      v8 = v33->RefCount-- == 1;
      if ( !v8 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      return 1;
    }
    else
    {
      return Scaleform::GFx::AS2::Object::GetMemberRaw(v34, psc, v4, val);
    }
  }
}
