Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Value::ToStringImpl(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        int precision,
        const Scaleform::GFx::ASString debug)
{
  Scaleform::GFx::AS2::Environment *v5; // ebx
  Scaleform::GFx::ASStringNode *RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::ASStringNode *pStringNode; // ebp
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v12; // zf
  int v14; // eax
  char *v15; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  char *v18; // eax
  Scaleform::GFx::AS2::ObjectInterface *v19; // eax
  unsigned __int16 FuncCallNestingLevel; // ax
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  Scaleform::GFx::ASStringNode *v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  char *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // esi
  const Scaleform::GFx::ASString *CharacterNamePath; // eax
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::GFx::ASStringNode *v30; // ecx
  Scaleform::GFx::AS2::FunctionRef func; // [esp+24h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS2::Value resulta; // [esp+30h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value toStringFunc; // [esp+40h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::FnCall fnCall; // [esp+50h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *piobj; // [esp+94h] [ebp+4h]

  v5 = penv;
  RefCount = (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  p_StringContext = &penv->StringContext;
  result->pNode = RefCount;
  ++RefCount->RefCount;
  switch ( this->T.Type )
  {
    case 0u:
    case 0xAu:
      Scaleform::GFx::ASString::operator=(
        result,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[18].pMovieImpl);
      return result;
    case 1u:
      Scaleform::GFx::ASString::operator=(
        result,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[18].pASSupport);
      return result;
    case 2u:
      Scaleform::GFx::ASString::operator=(
        result,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[18].AVMVersion
      + !this->V.BooleanValue);
      return result;
    case 3u:
      if ( precision >= 0 )
        v14 = -precision;
      else
        v14 = 10;
      v15 = Scaleform::GFx::NumberUtil::ToString(this->NV.NumberValue, (char *)&fnCall, 0x40u, v14);
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     v15);
      goto LABEL_9;
    case 4u:
      v18 = Scaleform::GFx::NumberUtil::IntToString(this->NV.Int32Value, (char *)&fnCall, 0x40u);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                          (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          v18);
      goto LABEL_10;
    case 5u:
      pStringNode = this->V.pStringNode;
      ++pStringNode->RefCount;
      pNode = result->pNode;
      v12 = result->pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->pNode = pStringNode;
      return result;
    case 6u:
    case 7u:
      toStringFunc.T.Type = 0;
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, v5);
      piobj = v19;
      if ( !LOBYTE(debug.pNode)
        && v19
        && (debug.pNode = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject,
            v19->GetMemberRaw(
              v19,
              p_StringContext,
              (const Scaleform::GFx::ASString *)&debug.pNode[21].pManager,
              &toStringFunc)) )
      {
        FuncCallNestingLevel = v5->FuncCallNestingLevel;
        v5->FuncCallNestingLevel = FuncCallNestingLevel + 1;
        if ( FuncCallNestingLevel >= 0xFFu )
        {
          Scaleform::GFx::ASString::operator=(
            result,
            (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[25]);
        }
        else
        {
          resulta.T.Type = 0;
          Scaleform::GFx::AS2::Value::ToFunction(&toStringFunc, &func, v5);
          Function = func.Function;
          pLocalFrame = func.pLocalFrame;
          if ( func.Function )
          {
            Scaleform::GFx::AS2::FnCall::FnCall(&fnCall, &resulta, piobj, v5, 0, 0);
            Function->Invoke(Function, &fnCall, pLocalFrame, 0);
            Scaleform::GFx::AS2::FnCall::~FnCall(&fnCall);
          }
          Scaleform::GFx::AS2::Value::ToStringImpl(&resulta, (Scaleform::GFx::ASString *)&penv, v5, -1, 0);
          Scaleform::GFx::ASString::operator=(result, (const Scaleform::GFx::ASString *)&penv);
          v23 = (Scaleform::GFx::ASStringNode *)penv;
          --penv->Stack.pPageEnd;
          if ( !v23->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          if ( (func.Flags & 2) == 0 )
          {
            if ( Function )
            {
              v24 = Function->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v24) != 0 )
              {
                Function->RefCount = v24 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          if ( (func.Flags & 1) == 0 )
          {
            if ( pLocalFrame )
            {
              v25 = pLocalFrame->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v25) != 0 )
              {
                pLocalFrame->RefCount = v25 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          if ( resulta.T.Type >= 5u )
          {
            Scaleform::GFx::AS2::Value::DropRefs(&resulta);
            --v5->FuncCallNestingLevel;
            goto LABEL_46;
          }
        }
        --v5->FuncCallNestingLevel;
      }
      else if ( this->T.Type == 6
             && this->NV.Int32Value
             && (v26 = (char *)(*(int (__thiscall **)(int, Scaleform::GFx::AS2::Environment *))(*(_DWORD *)(this->NV.Int32Value + 16)
                                                                                              + 4))(
                                 this->NV.Int32Value + 16,
                                 v5)) != 0 )
      {
        v27 = Scaleform::GFx::ASStringManager::CreateStringNode(
                (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                v26);
        ++v27->RefCount;
        debug.pNode = v27;
        Scaleform::GFx::ASString::operator=(result, &debug);
        v12 = v27->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      else
      {
        if ( this->T.Type == 7 && this->NV.Int32Value )
          CharacterNamePath = Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, v5);
        else
          CharacterNamePath = (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[25].RefCount;
        Scaleform::GFx::ASString::operator=(result, CharacterNamePath);
      }
LABEL_46:
      if ( toStringFunc.T.Type < 5u )
        return result;
      Scaleform::GFx::AS2::Value::DropRefs(&toStringFunc);
      return result;
    case 8u:
    case 0xBu:
      Scaleform::GFx::ASString::operator=(
        result,
        (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24].AVMVersion);
      return result;
    case 9u:
      StringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     "[property]",
                     0xAu,
                     0);
LABEL_9:
      ConstStringNode = StringNode;
      goto LABEL_10;
    case 0xCu:
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          "[resolveHandler]",
                          0x10u,
                          0);
LABEL_10:
      ++ConstStringNode->RefCount;
      debug.pNode = ConstStringNode;
      Scaleform::GFx::ASString::operator=(result, &debug);
      v12 = ConstStringNode->RefCount-- == 1;
      if ( !v12 )
        return result;
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      return result;
    default:
      pObject = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[17].pASSupport.pObject;
      ++pObject->RefCount;
      v30 = result->pNode;
      v12 = result->pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      result->pNode = pObject;
      return result;
  }
}
