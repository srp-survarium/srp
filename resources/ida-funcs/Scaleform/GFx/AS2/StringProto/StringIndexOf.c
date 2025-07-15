void __cdecl Scaleform::GFx::AS2::StringProto::StringIndexOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // esi
  Scaleform::GFx::ASStringNode *v7; // eax
  int v8; // ebp
  bool v9; // cc
  Scaleform::GFx::AS2::Value *v10; // eax
  unsigned int Char_Advance0; // esi
  int i; // ebx
  unsigned int v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v19; // [esp-10h] [ebp-28h]
  char *putf8Buffer; // [esp+4h] [ebp-14h] BYREF
  char *v21; // [esp+8h] [ebp-10h] BYREF
  char *v22; // [esp+Ch] [ebp-Ch] BYREF
  char *v23; // [esp+10h] [ebp-8h] BYREF
  unsigned int v24; // [esp+14h] [ebp-4h]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&fn) )
      {
        putf8Buffer = (char *)fn->__vftable;
        v8 = 0;
        v9 = v1->NArgs <= 1;
        v21 = (char *)p_pProto[13].pObject->__vftable;
        if ( !v9 )
        {
          v19 = v1->Env;
          v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v10, v19);
        }
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        v24 = Char_Advance0;
        if ( !Char_Advance0 )
          --putf8Buffer;
        for ( i = 0; ; ++i )
        {
          v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v21);
          if ( !v13 )
          {
            Result = v1->Result;
            --v21;
            if ( Result->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(Result);
            Result->T.Type = 3;
            Result->NV.NumberValue = -1.0;
            goto LABEL_39;
          }
          if ( i >= v8 && v13 == Char_Advance0 )
            break;
LABEL_35:
          ;
        }
        v22 = v21;
        v23 = putf8Buffer;
        do
        {
          v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v22);
          if ( !v14 )
            --v22;
          v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v23);
          if ( !v15 )
            --v23;
          if ( !v14 )
            break;
          if ( !v15 )
            goto LABEL_42;
        }
        while ( v14 == v15 );
        if ( !v15 )
        {
LABEL_42:
          Scaleform::GFx::AS2::Value::SetInt(v1->Result, i);
          goto LABEL_39;
        }
        if ( v14 )
        {
          Char_Advance0 = v24;
          goto LABEL_35;
        }
        Scaleform::GFx::AS2::Value::SetInt(v1->Result, -1);
LABEL_39:
        v17 = (Scaleform::GFx::ASStringNode *)fn;
        --fn->ThisFunctionRef.Function;
        if ( !v17->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      else
      {
        v6 = v1->Result;
        if ( v6->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v6->T.Type = 3;
        v6->NV.NumberValue = 0.0;
        v7 = (Scaleform::GFx::ASStringNode *)fn;
        --fn->ThisFunctionRef.Function;
        if ( !v7->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      }
    }
    else
    {
      v4 = v1->Result;
      if ( v4->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
      v4->NV.NumberValue = -1.0;
      v4->T.Type = 3;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
