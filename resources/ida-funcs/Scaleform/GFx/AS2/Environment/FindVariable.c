char __userpurge Scaleform::GFx::AS2::Environment::FindVariable@<al>(
        Scaleform::GFx::AS2::Environment *this@<ecx>,
        const Scaleform::GFx::ASString *a2@<ebp>,
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
  const Scaleform::GFx::ASString *v55; // [esp-2h] [ebp-70h]
  char VariableRaw; // [esp+Ch] [ebp-62h]
  char v57; // [esp+Dh] [ebp-61h] BYREF
  const char *v58; // [esp+Eh] [ebp-60h]
  Scaleform::GFx::AS2::Environment *penv; // [esp+12h] [ebp-5Ch]
  Scaleform::GFx::AS2::Value v; // [esp+16h] [ebp-58h] BYREF
  Scaleform::GFx::AS2::Value v61; // [esp+26h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::StringTokenizer v62; // [esp+36h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+46h] [ebp-28h] BYREF
  _DWORD v64[6]; // [esp+56h] [ebp-18h] BYREF

  pNode = params->VarName->pNode;
  Size = pNode->Size;
  penv = this;
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
  v.T.Type = 0;
  v58 = ":./";
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
    v15 = penv->Target->GetTopParent(penv->Target, 0);
    Scaleform::GFx::AS2::Value::SetAsCharacter(&v, v15);
    v16 = params->pOwner;
    ++pData;
    --Size;
    v13 = 1;
    v58 = onlySlashesDelim;
    if ( v16 )
      Scaleform::GFx::AS2::Value::operator=(v16, &v);
  }
  else if ( *pData == 46 )
  {
    v58 = onlySlashesDelim;
  }
  v17 = penv;
  pContext = penv->StringContext.pContext;
  v62.Delimiters = v58;
  v62.Str = pData;
  v62.EndStr = &pData[Size];
  v62.Token.pNode = (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++v62.Token.pNode->RefCount;
  v57 = 0;
  LOBYTE(penv) = 1;
  if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&v62, &v57) )
  {
    v19 = varName;
    do
    {
      v20 = v62.Token.pNode;
      if ( !v62.Token.pNode->Size )
        goto LABEL_91;
      if ( v19 )
      {
        ++v62.Token.pNode->RefCount;
        v21 = v19->pNode;
        v22 = v19->pNode->RefCount-- == 1;
        v23 = v20;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v19->pNode = v23;
      }
      Type = v.T.Type;
      v61.T.Type = 0;
      VariableRaw = 0;
      if ( v.T.Type == 7 )
      {
        if ( v13 )
          goto LABEL_43;
      }
      else
      {
        if ( v13 )
          goto LABEL_57;
        if ( !Scaleform::GFx::AS2::GAS_IsRelativePathToken(&v17->StringContext, &v62.Token) )
        {
          v64[0] = &v62.Token;
          pWithStack = params->pWithStack;
          v64[1] = &v61;
          v64[2] = pWithStack;
          memset(&v64[3], 0, 12);
          VariableRaw = Scaleform::GFx::AS2::Environment::GetVariableRaw(
                          v17,
                          (int)v17,
                          (int)&v62.Token,
                          (Scaleform::GFx::AS2::Object *)v64,
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
            Scaleform::GFx::AS2::Value::SetAsCharacter(&v, v27);
          }
        }
      }
      v28 = v.T.Type;
      if ( !v.T.Type || v.T.Type == 10 )
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
        if ( v28 != 7 || v.V.pCharHandle != pObject )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v);
          v.T.Type = 7;
          v.NV.Int32Value = (int)pObject;
          if ( pObject )
            ++pObject->RefCount;
        }
      }
      if ( v.T.Type == 7 )
      {
LABEL_43:
        if ( v.NV.Int32Value )
        {
          v31 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v.V.pCharHandle, v17->Target->pASRoot->pMovieImpl);
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
                                                       &v62.Token,
                                                       penv);
              if ( v35 )
              {
                CharacterHandle = v35->pNameHandle.pObject;
                if ( !CharacterHandle )
                  CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v35);
                if ( v61.T.Type != 7 || v61.V.pCharHandle != CharacterHandle )
                {
                  Scaleform::GFx::AS2::Value::DropRefs(&v61);
                  v61.T.Type = 7;
                  v61.NV.Int32Value = (int)CharacterHandle;
                  if ( CharacterHandle )
                    ++CharacterHandle->RefCount;
                }
                VariableRaw = 1;
                goto LABEL_75;
              }
            }
          }
        }
LABEL_68:
        v39 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&v, v17);
        if ( !v39 )
          goto LABEL_75;
        v40 = &v39->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_72;
      }
      Type = v.T.Type;
LABEL_57:
      if ( Type == 3 || Type == 4 || Type == 2 || Type == 5 )
      {
        v38 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(v17, &result, &v);
        Scaleform::GFx::AS2::Value::operator=(&v, v38);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
      }
      if ( v.T.Type != 6 )
      {
        if ( v.T.Type == 7 )
          goto LABEL_68;
        if ( v.T.Type != 8 && v.T.Type != 11 )
        {
LABEL_74:
          Scaleform::GFx::AS2::Value::DropRefs(&v61);
          VariableRaw = 0;
          v61.T.Type = 0;
          goto LABEL_75;
        }
      }
      v41 = Scaleform::GFx::AS2::Value::ToObject(&v, v17);
      if ( !v41 )
        goto LABEL_75;
      v40 = &v41->Scaleform::GFx::AS2::ObjectInterface;
LABEL_72:
      if ( v40 )
      {
        VariableRaw = v40->GetMember(v40, v17, &v62.Token, &v61);
        if ( !VariableRaw )
          goto LABEL_74;
      }
LABEL_75:
      v42 = params->pOwner;
      if ( v42 )
        Scaleform::GFx::AS2::Value::operator=(v42, &v);
      if ( onlyTargets && v61.T.Type != 7 || !VariableRaw )
      {
        Scaleform::GFx::AS2::Value::DropRefs(&v);
        v.T.Type = 0;
        v13 = 0;
        if ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&v62, &v57) )
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
        if ( v61.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v61);
        break;
      }
      if ( v61.T.Type != 9 )
      {
        Scaleform::GFx::AS2::Value::operator=(&v, &v61);
        goto LABEL_88;
      }
      if ( v.T.Type == 7 )
      {
        v43 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&v, v17);
        if ( !v43 )
          goto LABEL_86;
        Scaleform::GFx::AS2::Value::GetPropertyValue(&v61, v17, &v43->Scaleform::GFx::AS2::ObjectInterface, &v);
      }
      else
      {
        v44 = Scaleform::GFx::AS2::Value::ToObject(&v, v17);
        if ( !v44 )
        {
LABEL_86:
          Scaleform::GFx::AS2::Value::GetPropertyValue(&v61, v17, 0, &v);
          goto LABEL_88;
        }
        Scaleform::GFx::AS2::Value::GetPropertyValue(&v61, v17, &v44->Scaleform::GFx::AS2::ObjectInterface, &v);
      }
LABEL_88:
      v13 = VariableRaw;
      if ( v61.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v61);
      v19 = varName;
LABEL_91:
      if ( v58 == onlySlashesDelim )
      {
        if ( v57 != 58 )
          goto LABEL_100;
        v22 = params->ppNewTarget == 0;
        v62.Delimiters = ":./";
        v58 = ":./";
        if ( !v22 && v.T.Type == 7 )
          goto LABEL_95;
      }
      else
      {
        if ( v57 != 46 )
        {
LABEL_100:
          if ( v57 == 47 )
          {
            v62.Delimiters = onlySlashesDelim;
            v58 = onlySlashesDelim;
          }
          goto LABEL_102;
        }
        if ( params->ppNewTarget && v.T.Type == 7 )
LABEL_95:
          *params->ppNewTarget = Scaleform::GFx::AS2::Value::ToCharacter(&v, v17);
      }
LABEL_102:
      LOBYTE(penv) = 0;
    }
    while ( Scaleform::GFx::AS2::StringTokenizer::NextToken(&v62, &v57) );
  }
  if ( params->ppNewTarget && v.T.Type == 7 )
    *params->ppNewTarget = Scaleform::GFx::AS2::Value::ToCharacter(&v, v17);
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
      Scaleform::GFx::AS2::Value::operator=(v52, &v);
    v53 = v62.Token.pNode;
    --v62.Token.pNode->RefCount;
    if ( !v53->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v53);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    return 1;
  }
  v51 = v62.Token.pNode;
  --v62.Token.pNode->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 0;
}
