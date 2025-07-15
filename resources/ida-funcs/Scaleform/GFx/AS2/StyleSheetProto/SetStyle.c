void __cdecl Scaleform::GFx::AS2::StyleSheetProto::SetStyle(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebp
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // ebx
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::AS2::Environment *v11; // esi
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::Text::StyleManager *v14; // ecx
  Scaleform::GFx::AS2::Environment *v15; // [esp-Ch] [ebp-28h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-24h]
  Scaleform::GFx::AS2::Environment *v17; // [esp-4h] [ebp-20h]
  Scaleform::GFx::AS2::FnCall_vtbl *Size; // [esp-4h] [ebp-20h]
  Scaleform::GFx::ASString result; // [esp+Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS2::CSSStringBuilder propvis; // [esp+10h] [ebp-Ch] BYREF

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 31 )
  {
    ThisPtr = pData->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        NArgs = pData->NArgs;
        if ( NArgs >= 1 )
        {
          if ( NArgs < 2 || Scaleform::GFx::AS2::FnCall::Arg(pData, 1)->T.Type == 1 )
          {
            Env = pData->Env;
            v12 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
            Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
            v13 = (Scaleform::GFx::ASStringNode *)fn.pData;
            if ( *(_DWORD *)fn.pData[1].Data )
            {
              v14 = (Scaleform::GFx::Text::StyleManager *)&p_pProto[13];
              Size = (Scaleform::GFx::AS2::FnCall_vtbl *)fn.pData->Size;
              if ( *(_BYTE *)fn.pData->Size == 46 )
                Scaleform::GFx::Text::StyleManager::ClearStyle(v14, CSS_Class, (const char *)Size, 0xFFFFFFFF);
              else
                Scaleform::GFx::Text::StyleManager::ClearStyle(v14, CSS_Tag, (const char *)Size, 0xFFFFFFFF);
            }
            v9 = v13->RefCount-- == 1;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          }
          else
          {
            v15 = pData->Env;
            v5 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
            Scaleform::GFx::AS2::Value::ToStringImpl(v5, &result, v15, -1, 0);
            v17 = pData->Env;
            v6 = Scaleform::GFx::AS2::FnCall::Arg(pData, 1);
            v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v17);
            if ( v7 )
            {
              Scaleform::String::String(&fn);
              pNode = result.pNode;
              Scaleform::String::AppendString(&fn, (char *)result.pNode->pData, 0xFFFFFFFF);
              Scaleform::String::AppendChar(&fn, 0x7Bu);
              v11 = pData->Env;
              propvis.Dest = &fn;
              propvis.pEnv = v11;
              propvis.__vftable = (Scaleform::GFx::AS2::CSSStringBuilder_vtbl *)&Scaleform::GFx::AS2::CSSStringBuilder::`vftable';
              v7->VisitMembers(&v7->Scaleform::GFx::AS2::ObjectInterface, &v11->StringContext, &propvis, 0, 0);
              Scaleform::String::AppendChar(&fn, 0x7Du);
              Scaleform::GFx::Text::StyleManager::ParseCSS(
                (Scaleform::GFx::Text::StyleManager *)&p_pProto[13],
                (const char *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                *(_DWORD *)(fn.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
              propvis.__vftable = (Scaleform::GFx::AS2::CSSStringBuilder_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
              Scaleform::String::~String(&fn);
              v9 = pNode->RefCount-- == 1;
              if ( v9 )
                Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
            }
            else
            {
              v8 = result.pNode;
              v9 = result.pNode->RefCount-- == 1;
              if ( v9 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v8);
            }
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      pData->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
