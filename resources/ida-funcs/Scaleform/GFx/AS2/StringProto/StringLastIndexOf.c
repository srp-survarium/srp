void __cdecl Scaleform::GFx::AS2::StringProto::StringLastIndexOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // eax
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // esi
  long double v7; // st7
  bool v8; // cc
  Scaleform::GFx::AS2::Value *v9; // eax
  unsigned int Char_Advance0; // esi
  int v11; // ebp
  int i; // ebx
  unsigned int v13; // eax
  unsigned int v14; // esi
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-38h]
  Scaleform::GFx::AS2::Environment *v20; // [esp-Ch] [ebp-30h]
  char *putf8Buffer; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::ASConstString v22; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::GFx::ASConstString v23; // [esp+Ch] [ebp-18h] BYREF
  char *v24; // [esp+10h] [ebp-14h] BYREF
  char *v25; // [esp+14h] [ebp-10h] BYREF
  int v26; // [esp+18h] [ebp-Ch]
  long double v27; // [esp+1Ch] [ebp-8h]

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
      v23.pNode = (Scaleform::GFx::ASStringNode *)p_pProto[13].pObject;
      ++v23.pNode->RefCount;
      Env = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v22, Env, -1, 0);
      if ( Scaleform::GFx::ASConstString::GetLength(&v22) )
      {
        v8 = v1->NArgs <= 1;
        putf8Buffer = (char *)v23.pNode->pData;
        fn = (const Scaleform::GFx::AS2::FnCall *)v22.pNode->pData;
        v26 = 0x7FFFFFF;
        if ( !v8 )
        {
          v20 = v1->Env;
          v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v26 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, v20);
        }
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&fn);
        LODWORD(v27) = Char_Advance0;
        if ( !Char_Advance0 )
          fn = (const Scaleform::GFx::AS2::FnCall *)((char *)fn - 1);
        v11 = -1;
        for ( i = 0; ; ++i )
        {
          v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !v13 )
            break;
          if ( i <= v26 && v13 == Char_Advance0 )
          {
            v24 = putf8Buffer;
            v25 = (char *)fn;
            do
            {
              v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v24);
              if ( !v14 )
                --v24;
              v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v25);
              if ( !v15 )
                --v25;
              if ( !v14 )
                break;
              if ( !v15 )
                goto LABEL_32;
            }
            while ( v14 == v15 );
            if ( v15 )
              goto LABEL_33;
LABEL_32:
            v11 = i;
LABEL_33:
            if ( !v14 )
              goto LABEL_37;
            Char_Advance0 = LODWORD(v27);
          }
        }
        --putf8Buffer;
LABEL_37:
        Result = v1->Result;
        if ( Result->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        Result->NV.Int32Value = v11;
        Result->T.Type = 4;
      }
      else
      {
        LODWORD(v27) = Scaleform::GFx::ASConstString::GetLength(&v23);
        v6 = v1->Result;
        v27 = (double)LODWORD(v27);
        if ( v6->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v6);
        v7 = v27;
        v6->T.Type = 3;
        v6->NV.NumberValue = v7;
      }
      pNode = v22.pNode;
      --v22.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v18 = v23.pNode;
      --v23.pNode->RefCount;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    else
    {
      v4 = v1->Result;
      if ( v4->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
      v4->T.Type = 3;
      v4->NV.NumberValue = -1.0;
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
