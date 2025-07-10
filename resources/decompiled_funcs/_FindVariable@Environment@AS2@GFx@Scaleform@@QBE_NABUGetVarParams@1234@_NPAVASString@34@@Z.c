char __userpurge Scaleform::GFx::AS2::Environment::FindVariable@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        const Scaleform::GFx::AS2::Environment::GetVarParams *params,
        bool onlyTargets,
        Scaleform::GFx::ASString *varName)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int Size; // edi
  Scaleform::GFx::AS2::Value *pResult; // ecx
  const char *pData; // esi
  Scaleform::GFx::AS2::Value *pOwner; // ebp
  char v13; // bl
  Scaleform::GFx::InteractiveObject **ppNewTarget; // eax
  Scaleform::GFx::InteractiveObject *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // ecx
  Scaleform::GFx::AS2::Environment *v17; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::ASString *v19; // edi
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ecx
  bool v22; // zf
  Scaleform::GFx::ASStringNode *v23; // esi
  unsigned __int8 Type; // al
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v25; // eax
  Scaleform::GFx::AS2::ObjectInterface *ObjectInterface; // esi
  Scaleform::GFx::InteractiveObject *v27; // esi
  unsigned __int8 v28; // bl
  Scaleform::GFx::DisplayObject *Target; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // esi
  Scaleform::GFx::InteractiveObject *v31; // eax
  Scaleform::GFx::InteractiveObject *v32; // ecx
  int v33; // edx
  int v34; // eax
  Scaleform::GFx::DisplayObject *v35; // eax
  Scaleform::GFx::CharacterHandle *CharacterHandle; // esi
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStack; // eax
  const Scaleform::GFx::AS2::Value *v38; // eax
  Scaleform::GFx::AS2::AvmCharacter *v39; // eax
  Scaleform::GFx::AS2::ObjectInterface *v40; // ecx
  Scaleform::GFx::AS2::Object *v41; // eax
  Scaleform::GFx::AS2::Value *v42; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v43; // eax
  Scaleform::GFx::AS2::Object *v44; // eax
  Scaleform::GFx::AS2::Value *v45; // esi
  Scaleform::GFx::InteractiveObject **v46; // eax
  Scaleform::GFx::ASStringNode *RefCount; // esi
  Scaleform::GFx::ASStringNode *v48; // ecx
  Scaleform::GFx::AS2::Value *v49; // esi
  unsigned __int8 v50; // al
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::AS2::Value *v52; // ecx
  Scaleform::GFx::ASStringNode *v53; // eax
  int v54; // [esp-6h] [ebp-74h]
  int v55; // [esp-2h] [ebp-70h]
  char sep[4]; // [esp+Ah] [ebp-64h] BYREF
  const char *delim; // [esp+Eh] [ebp-60h]
  Scaleform::GFx::AS2::Environment *first_token; // [esp+12h] [ebp-5Ch]
  Scaleform::GFx::AS2::Value current; // [esp+16h] [ebp-58h] BYREF
  Scaleform::GFx::AS2::Value member; // [esp+26h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::StringTokenizer parser; // [esp+36h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+46h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v63; // [esp+56h] [ebp-18h] BYREF

  pNode = params->VarName->pNode;
  Size = pNode->Size;
  first_token = this;
  if ( !Size )
  {
    pResult = params->pResult;
    if ( pResult )
    {
      Scaleform::GFx::AS2::Value::SetAsCharacter(pResult, this->Target);
      return 1;
    }
    return 1;
  }
  v55 = a2;
  v54 = a3;
  pData = pNode->pData;
  pOwner = params->pOwner;
  v13 = 0;
  current.T.Type = 0;
  delim = ":./";
  if ( pOwner )
  {
    Scaleform::GFx::AS2::Value::DropRefs(pOwner);
    pOwner->T.Type = 0;
  }
  ppNewTarget = params->ppNewTarget;
  if ( ppNewTarget )
    *ppNewTarget = 0;
  if ( *pData == 47 )
  {
    v15 = first_token->Target->GetTopParent(first_token->Target, 0);
    Scaleform::GFx::AS2::Value::SetAsCharacter(&current, v15);
    v16 = params->pOwner;
    ++pData;
    --Size;
    v13 = 1;
    delim = onlySlashesDelim;
    if ( v16 )
      Scaleform::GFx::AS2::Value::operator=(v16, &current);
  }
  else if ( *pData == 46 )
  {
    delim = onlySlashesDelim;
  }
  v17 = first_token;
  pContext = first_token->StringContext.pContext;
  parser.Delimiters = delim;
  parser.Str = pData;
  parser.EndStr = &pData[Size];
  parser.Token.pNode = (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++parser.Token.pNode->RefCount;
  sep[3] = 0;
  LOBYTE(first_token) = 1;
  if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&parser, &sep[3]) )
  {
    v19 = varName;
    do
    {
      v20 = parser.Token.pNode;
      if ( !parser.Token.pNode->Size )
        goto LABEL_91;
      if ( v19 )
      {
        ++parser.Token.pNode->RefCount;
        v21 = v19->pNode;
        v22 = v19->pNode->RefCount-- == 1;
        v23 = v20;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v19->pNode = v23;
      }
      Type = current.T.Type;
      member.T.Type = 0;
      sep[2] = 0;
      if ( current.T.Type == 7 )
      {
        if ( v13 )
          goto LABEL_43;
      }
      else
      {
        if ( v13 )
          goto LABEL_57;
        if ( !Scaleform::GFx::AS2::GAS_IsRelativePathToken(&v17->StringContext, &parser.Token) )
        {
          v63.VarName = &parser.Token;
          pWithStack = params->pWithStack;
          v63.pResult = &member;
          v63.pWithStack = pWithStack;
          memset(&v63.ppNewTarget, 0, 12);
          sep[2] = Scaleform::GFx::AS2::Environment::GetVariableRaw(
                     v17,
                     (int)v17,
                     (int)&parser.Token,
                     (Scaleform::GFx::AS2::Object *)&v63,
                     v54,
                     v55);
          goto LABEL_75;
        }
      }
      v25 = params->pWithStack;
      if ( v25 )
      {
        if ( v25->Data.Size )
        {
          ObjectInterface = Scaleform::GFx::AS2::WithStackEntry::GetObjectInterface(&v25->Data.Data[v25->Data.Size - 1]);
          if ( (unsigned int)(ObjectInterface->GetObjectType(ObjectInterface) - 2) <= 3 )
          {
            if ( (unsigned int)(ObjectInterface->GetObjectType(ObjectInterface) - 2) > 3 )
              v27 = 0;
            else
              v27 = (Scaleform::GFx::InteractiveObject *)ObjectInterface[1].__vftable;
            Scaleform::GFx::AS2::Value::SetAsCharacter(&current, v27);
          }
        }
      }
      v28 = current.T.Type;
      if ( !current.T.Type || current.T.Type == 10 )
      {
        Target = v17->Target;
        if ( Target )
        {
          pObject = Target->pNameHandle.pObject;
          if ( !pObject )
            pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(Target);
        }
        else
        {
          pObject = 0;
        }
        if ( v28 != 7 || current.V.pCharHandle != pObject )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&current);
          current.T.Type = 7;
          current.NV.Int32Value = (int)pObject;
          if ( pObject )
            ++pObject->RefCount;
        }
      }
      if ( current.T.Type == 7 )
      {
LABEL_43:
        if ( current.NV.Int32Value )
        {
          v31 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                  current.V.pCharHandle,
                  v17->Target->pASRoot->pMovieImpl);
          if ( v31 )
          {
            if ( (LOBYTE(v31->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                ? (unsigned int)v31
                : 0) != 0 )
            {
              v33 = *(LOBYTE(v31->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                    ? &v31->AvmObjOffset
                    : (unsigned __int8 *)65);
              v32 = LOBYTE(v31->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0
                  ? v31
                  : 0;
              v34 = (*(int (__thiscall **)(int))(*((_DWORD *)&v32->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v33)
                                               + 4))((int)v32 + 4 * v33);
              v35 = (Scaleform::GFx::DisplayObject *)(*(int (__thiscall **)(int, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Environment *))(*(_DWORD *)v34 + 108))(
                                                       v34,
                                                       &parser.Token,
                                                       first_token);
              if ( v35 )
              {
                CharacterHandle = v35->pNameHandle.pObject;
                if ( !CharacterHandle )
                  CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v35);
                if ( member.T.Type != 7 || member.V.pCharHandle != CharacterHandle )
                {
                  Scaleform::GFx::AS2::Value::DropRefs(&member);
                  member.T.Type = 7;
                  member.NV.Int32Value = (int)CharacterHandle;
                  if ( CharacterHandle )
                    ++CharacterHandle->RefCount;
                }
                sep[2] = 1;
                goto LABEL_75;
              }
            }
          }
        }
LABEL_68:
        v39 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&current, v17);
        if ( !v39 )
          goto LABEL_75;
        v40 = &v39->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_72;
      }
      Type = current.T.Type;
LABEL_57:
      if ( Type == 3 || Type == 4 || Type == 2 || Type == 5 )
      {
        v38 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(v17, &result, &current);
        Scaleform::GFx::AS2::Value::operator=(&current, v38);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
      }
      if ( current.T.Type != 6 )
      {
        if ( current.T.Type == 7 )
          goto LABEL_68;
        if ( current.T.Type != 8 && current.T.Type != 11 )
        {
LABEL_74:
          Scaleform::GFx::AS2::Value::DropRefs(&member);
          sep[2] = 0;
          member.T.Type = 0;
          goto LABEL_75;
        }
      }
      v41 = Scaleform::GFx::AS2::Value::ToObject(&current, v17);
      if ( !v41 )
        goto LABEL_75;
      v40 = &v41->Scaleform::GFx::AS2::ObjectInterface;
LABEL_72:
      if ( v40 )
      {
        sep[2] = v40->GetMember(v40, v17, &parser.Token, &member);
        if ( !sep[2] )
          goto LABEL_74;
      }
LABEL_75:
      v42 = params->pOwner;
      if ( v42 )
        Scaleform::GFx::AS2::Value::operator=(v42, &current);
      if ( onlyTargets && member.T.Type != 7 || !sep[2] )
      {
        Scaleform::GFx::AS2::Value::DropRefs(&current);
        current.T.Type = 0;
        v13 = 0;
        if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&parser, &sep[3]) )
        {
          v45 = params->pOwner;
          if ( v45 )
          {
            Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
            v45->T.Type = 0;
          }
          v46 = params->ppNewTarget;
          if ( v46 )
            *v46 = 0;
          if ( varName )
          {
            RefCount = (Scaleform::GFx::ASStringNode *)v17->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
            ++RefCount->RefCount;
            v48 = varName->pNode;
            v22 = varName->pNode->RefCount-- == 1;
            if ( v22 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v48);
            varName->pNode = RefCount;
          }
        }
        if ( member.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&member);
        break;
      }
      if ( member.T.Type != 9 )
      {
        Scaleform::GFx::AS2::Value::operator=(&current, &member);
        goto LABEL_88;
      }
      if ( current.T.Type == 7 )
      {
        v43 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&current, v17);
        if ( !v43 )
          goto LABEL_86;
        Scaleform::GFx::AS2::Value::GetPropertyValue(&member, v17, &v43->Scaleform::GFx::AS2::ObjectInterface, &current);
      }
      else
      {
        v44 = Scaleform::GFx::AS2::Value::ToObject(&current, v17);
        if ( !v44 )
        {
LABEL_86:
          Scaleform::GFx::AS2::Value::GetPropertyValue(&member, v17, 0, &current);
          goto LABEL_88;
        }
        Scaleform::GFx::AS2::Value::GetPropertyValue(&member, v17, &v44->Scaleform::GFx::AS2::ObjectInterface, &current);
      }
LABEL_88:
      v13 = sep[2];
      if ( member.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&member);
      v19 = varName;
LABEL_91:
      if ( delim == onlySlashesDelim )
      {
        if ( sep[3] != 58 )
          goto LABEL_100;
        v22 = params->ppNewTarget == 0;
        parser.Delimiters = ":./";
        delim = ":./";
        if ( !v22 && current.T.Type == 7 )
          goto LABEL_95;
      }
      else
      {
        if ( sep[3] != 46 )
        {
LABEL_100:
          if ( sep[3] == 47 )
          {
            parser.Delimiters = onlySlashesDelim;
            delim = onlySlashesDelim;
          }
          goto LABEL_102;
        }
        if ( params->ppNewTarget && current.T.Type == 7 )
LABEL_95:
          *params->ppNewTarget = Scaleform::GFx::AS2::Value::ToCharacter(&current, v17);
      }
LABEL_102:
      LOBYTE(first_token) = 0;
    }
    while ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&parser, &sep[3]) );
  }
  if ( params->ppNewTarget && current.T.Type == 7 )
    *params->ppNewTarget = Scaleform::GFx::AS2::Value::ToCharacter(&current, v17);
  v49 = params->pOwner;
  if ( v49 )
  {
    v50 = v49->T.Type;
    if ( v49->T.Type != 6 && v50 != 7 && v50 != 8 && v50 != 11 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(params->pOwner);
      v49->T.Type = 0;
    }
  }
  if ( v13 )
  {
    v52 = params->pResult;
    if ( v52 )
      Scaleform::GFx::AS2::Value::operator=(v52, &current);
    v53 = parser.Token.pNode;
    --parser.Token.pNode->RefCount;
    if ( !v53->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v53);
    if ( current.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&current);
    return 1;
  }
  v51 = parser.Token.pNode;
  --parser.Token.pNode->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( current.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&current);
  return 0;
}
