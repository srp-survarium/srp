Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Value::ToPrimitive(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value::Hint __formal)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // esi
  char v7; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v10; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // esi
  Scaleform::GFx::AS2::AvmCharacter *v15; // eax
  Scaleform::GFx::AS2::ObjectInterface *v16; // ebx
  Scaleform::GFx::AS2::Object *v17; // eax
  unsigned __int16 FuncCallNestingLevel; // ax
  __int64 v19; // kr00_8
  char v20; // bl
  int v21; // eax
  int v22; // eax
  Scaleform::GFx::AS2::Value *v23; // esi
  Scaleform::GFx::AS2::Value *p_ResIn; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  __m128i *v26; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  bool v28; // zf
  Scaleform::GFx::ASStringNode *v29; // ecx
  Scaleform::GFx::AS2::Value resulta; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+20h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [esp+30h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v33; // [esp+40h] [ebp-24h] BYREF

  Type = this->T.Type;
  if ( this->T.Type != 6 && Type != 7 && Type != 8 )
  {
    if ( Type == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(this, (Scaleform::GFx::AS2::FunctionRef *)&resulta, penv);
      v6 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&resulta.T.Type;
      if ( *(_DWORD *)&resulta.T.Type )
      {
        Scaleform::GFx::AS2::Value::Value(result, (const Scaleform::GFx::AS2::FunctionRef *)&resulta);
        v7 = BYTE4(resulta.NV.NumberValue);
        if ( (BYTE4(resulta.NV.NumberValue) & 2) == 0 )
        {
          RefCount = v6->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v6->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
          }
        }
        if ( (v7 & 1) == 0 )
        {
          pStringNode = resulta.V.pStringNode;
          if ( resulta.NV.Int32Value )
          {
            v10 = *(_DWORD *)(resulta.NV.Int32Value + 12);
            if ( (v10 & 0x3FFFFFF) != 0 )
            {
              *(_DWORD *)(resulta.NV.Int32Value + 12) = v10 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
            }
          }
        }
        return result;
      }
      if ( (BYTE4(resulta.NV.NumberValue) & 1) == 0 )
      {
        v12 = resulta.V.pStringNode;
        if ( resulta.NV.Int32Value )
        {
          v13 = *(_DWORD *)(resulta.NV.Int32Value + 12);
          if ( (v13 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(resulta.NV.Int32Value + 12) = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
          }
        }
      }
    }
    Scaleform::GFx::AS2::Value::Value(result, this);
    return result;
  }
  v14 = penv;
  v31.T.Type = 0;
  if ( Type != 7 )
  {
    v17 = Scaleform::GFx::AS2::Value::ToObject(this, penv);
    if ( v17 )
    {
      v16 = &v17->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_25;
    }
LABEL_24:
    v16 = 0;
    goto LABEL_25;
  }
  v15 = Scaleform::GFx::AS2::Value::ToAvmCharacter(this, penv);
  if ( !v15 )
    goto LABEL_24;
  v16 = &v15->Scaleform::GFx::AS2::ObjectInterface;
LABEL_25:
  if ( v14
    && v16
    && v16->GetMemberRaw(
         v16,
         &v14->StringContext,
         (const Scaleform::GFx::ASString *)&v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].pASSupport,
         &v31) )
  {
    FuncCallNestingLevel = v14->FuncCallNestingLevel;
    ResIn.T.Type = 0;
    v14->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel >= 0xFFu )
    {
      if ( v14->IsVerboseActionErrors(v14) )
        Scaleform::GFx::AS2::Environment::LogScriptError(
          v14,
          "Stack overflow, max level of 255 nested calls of valueOf is reached.");
    }
    else
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v31, (Scaleform::GFx::AS2::FunctionRef *)&resulta, v14);
      v19 = *(_QWORD *)&resulta.T.Type;
      if ( *(_DWORD *)&resulta.T.Type )
      {
        Scaleform::GFx::AS2::FnCall::FnCall(&v33, &ResIn, v16, v14, 0, 0);
        (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS2::FnCall *, _DWORD, _DWORD))(*(_DWORD *)v19 + 40))(
          v19,
          &v33,
          HIDWORD(v19),
          0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v33);
      }
      v20 = BYTE4(resulta.NV.NumberValue);
      if ( (BYTE4(resulta.NV.NumberValue) & 2) == 0 )
      {
        if ( (_DWORD)v19 )
        {
          v21 = *(_DWORD *)(v19 + 12);
          if ( (v21 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v19 + 12) = v21 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v19);
          }
        }
      }
      if ( (v20 & 1) == 0 )
      {
        if ( HIDWORD(v19) )
        {
          v22 = *(_DWORD *)(HIDWORD(v19) + 12);
          if ( (v22 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(HIDWORD(v19) + 12) = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)HIDWORD(v19));
          }
        }
      }
    }
    --v14->FuncCallNestingLevel;
    v23 = result;
    Scaleform::GFx::AS2::Value::Value(result, &ResIn);
    if ( ResIn.T.Type < 5u )
      goto LABEL_56;
    p_ResIn = &ResIn;
    goto LABEL_55;
  }
  if ( this->T.Type == 7 && this->NV.Int32Value )
  {
    pNode = Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, v14)->pNode;
    ++pNode->RefCount;
    resulta.T.Type = 5;
    resulta.NV.Int32Value = (int)pNode;
    goto LABEL_53;
  }
  if ( this->T.Type == 6
    && this->NV.Int32Value
    && (v26 = (__m128i *)(*(int (__thiscall **)(int, Scaleform::GFx::AS2::Environment *))(*(_DWORD *)(this->NV.Int32Value + 16)
                                                                                        + 4))(
                           this->NV.Int32Value + 16,
                           v14)) != 0 )
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   v26);
    ++StringNode->RefCount;
    v28 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    resulta.T.Type = 5;
    resulta.NV.Int32Value = (int)StringNode;
    if ( !v28 )
      goto LABEL_53;
    v29 = StringNode;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(this, (Scaleform::GFx::ASString *)&penv, v14, -1, 0);
    v29 = (Scaleform::GFx::ASStringNode *)penv;
    ++penv->Stack.pPageEnd;
    v28 = v29->RefCount-- == 1;
    resulta.T.Type = 5;
    resulta.NV.Int32Value = (int)v29;
    if ( !v28 )
      goto LABEL_53;
  }
  Scaleform::GFx::ASStringNode::ReleaseNode(v29);
LABEL_53:
  v23 = result;
  Scaleform::GFx::AS2::Value::Value(result, &resulta);
  if ( resulta.T.Type >= 5u )
  {
    p_ResIn = &resulta;
LABEL_55:
    Scaleform::GFx::AS2::Value::DropRefs(p_ResIn);
  }
LABEL_56:
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  return v23;
}
