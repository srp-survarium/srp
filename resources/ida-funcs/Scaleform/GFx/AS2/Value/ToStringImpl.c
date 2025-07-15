Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Value::ToStringImpl(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        int precision,
        Scaleform::GFx::ASString debug)
{
  Scaleform::GFx::AS2::Environment *v5; // ebx
  Scaleform::GFx::ASStringNode *RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::ASStringNode *pStringNode; // ebp
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v12; // zf
  int v14; // eax
  __m128i *v15; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  __m128i *v18; // eax
  Scaleform::GFx::AS2::ObjectInterface *v19; // eax
  unsigned __int16 FuncCallNestingLevel; // ax
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  Scaleform::GFx::ASStringNode *v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // eax
  __m128i *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // esi
  const Scaleform::GFx::ASString *CharacterNamePath; // eax
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::GFx::ASStringNode *v30; // ecx
  __int64 v31; // [esp+8h] [ebp-88h]
  Scaleform::GFx::AS2::FunctionRef resulta; // [esp+24h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [esp+30h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v34; // [esp+40h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::FnCall v35; // [esp+50h] [ebp-40h] BYREF
  Scaleform::GFx::ASString *v36; // [esp+94h] [ebp+4h]

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
      HIDWORD(v31) = 64;
      LODWORD(v31) = &v35;
      v15 = (__m128i *)Scaleform::GFx::NumberUtil::ToString(this->NV.NumberValue, v31, v14);
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     v15);
      goto LABEL_9;
    case 4u:
      v18 = (__m128i *)Scaleform::GFx::NumberUtil::IntToString(this->NV.Int32Value, (char *)&v35, 0x40u);
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
      v34.T.Type = 0;
      v19 = Scaleform::GFx::AS2::Value::ToObjectInterface(this, v5);
      v36 = (Scaleform::GFx::ASString *)v19;
      if ( !LOBYTE(debug.pNode)
        && v19
        && (debug.pNode = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject,
            v19->GetMemberRaw(v19, p_StringContext, (const Scaleform::GFx::ASString *)&debug.pNode[21].pManager, &v34)) )
      {
        FuncCallNestingLevel = v5->FuncCallNestingLevel;
        v5->FuncCallNestingLevel = FuncCallNestingLevel + 1;
        if ( FuncCallNestingLevel >= 0xFFu )
        {
          Scaleform::GFx::ASString::operator=(
            result,
            (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[25]);
          if ( v5->IsVerboseActionErrors(v5) )
            Scaleform::GFx::AS2::Environment::LogScriptError(
              v5,
              "Stack overflow, max level of 255 nested calls of toString is reached.");
        }
        else
        {
          ResIn.T.Type = 0;
          Scaleform::GFx::AS2::Value::ToFunction(&v34, &resulta, v5);
          Function = resulta.Function;
          pLocalFrame = resulta.pLocalFrame;
          if ( resulta.Function )
          {
            Scaleform::GFx::AS2::FnCall::FnCall(&v35, &ResIn, (Scaleform::GFx::AS2::ObjectInterface *)v36, v5, 0, 0);
            Function->Invoke(Function, &v35, pLocalFrame, 0);
            Scaleform::GFx::AS2::FnCall::~FnCall(&v35);
          }
          Scaleform::GFx::AS2::Value::ToStringImpl(&ResIn, (Scaleform::GFx::ASString *)&penv, v5, -1, 0);
          Scaleform::GFx::ASString::operator=(result, (const Scaleform::GFx::ASString *)&penv);
          v23 = (Scaleform::GFx::ASStringNode *)penv;
          --penv->Stack.pPageEnd;
          if ( !v23->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          if ( (resulta.Flags & 2) == 0 )
          {
            if ( Function )
            {
              v24 = Function->RefCount;
              if ( (v24 & 0x3FFFFFF) != 0 )
              {
                Function->RefCount = v24 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              }
            }
          }
          if ( (resulta.Flags & 1) == 0 )
          {
            if ( pLocalFrame )
            {
              v25 = pLocalFrame->RefCount;
              if ( (v25 & 0x3FFFFFF) != 0 )
              {
                pLocalFrame->RefCount = v25 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          if ( ResIn.T.Type >= 5u )
          {
            Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
            --v5->FuncCallNestingLevel;
            goto LABEL_47;
          }
        }
        --v5->FuncCallNestingLevel;
      }
      else if ( this->T.Type == 6
             && this->NV.Int32Value
             && (v26 = (__m128i *)(*(int (__thiscall **)(int, Scaleform::GFx::AS2::Environment *))(*(_DWORD *)(this->NV.Int32Value + 16)
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
LABEL_47:
      if ( v34.T.Type < 5u )
        return result;
      Scaleform::GFx::AS2::Value::DropRefs(&v34);
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
