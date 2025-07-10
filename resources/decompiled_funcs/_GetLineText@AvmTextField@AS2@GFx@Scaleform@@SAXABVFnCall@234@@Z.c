void __cdecl Scaleform::GFx::AS2::AvmTextField::GetLineText(Scaleform::String fn)
{
  const Scaleform::GFx::AS2::FnCall *pData; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v3; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  long double v5; // st7
  Scaleform::GFx::AS2::Value *v6; // edi
  Scaleform::Render::Text::DocView *GetMemberRaw; // ecx
  wchar_t *LineText; // esi
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value *Result; // ecx
  bool v11; // zf
  const Scaleform::GFx::AS2::FnCall *ConstStringNode; // esi
  Scaleform::GFx::AS2::Value *v13; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-14h]
  unsigned int len; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASString asstr; // [esp+8h] [ebp-4h] BYREF

  pData = (const Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( *(_DWORD *)fn.pData->Data
    && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)fn.pData->Data + 8))(*(_DWORD *)fn.pData->Data) == 4 )
  {
    ThisPtr = pData->ThisPtr;
    v3 = (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 ? 0 : ThisPtr[1].__vftable;
    if ( pData->NArgs >= 1 )
    {
      Env = pData->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
      v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
      if ( (int)v5 >= 0 )
      {
        GetMemberRaw = (Scaleform::Render::Text::DocView *)v3[1].GetMemberRaw;
        len = 0;
        LineText = Scaleform::Render::Text::DocView::GetLineText(GetMemberRaw, (int)v5, (unsigned int)&len);
        if ( LineText )
        {
          Scaleform::String::String(&fn);
          Scaleform::String::AppendString(&fn, LineText, len);
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         (Scaleform::GFx::ASStringManager *)pData->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                         (char *)((fn.HeapTypeBits & 0xFFFFFFFC) + 8),
                         *(_DWORD *)(fn.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
          ++StringNode->RefCount;
          Result = pData->Result;
          asstr.pNode = StringNode;
          Scaleform::GFx::AS2::Value::SetString(Result, &asstr);
          v11 = StringNode->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
          Scaleform::String::~String(&fn);
        }
        else
        {
          ConstStringNode = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                   (Scaleform::GFx::ASStringManager *)pData->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                                   (char *)&buf,
                                                                   0,
                                                                   0);
          ++ConstStringNode->ThisFunctionRef.Function;
          v13 = pData->Result;
          fn.pData = (Scaleform::String::DataDesc *)ConstStringNode;
          Scaleform::GFx::AS2::Value::SetString(v13, (const Scaleform::GFx::ASString *)&fn);
          v11 = ConstStringNode->ThisFunctionRef.Function-- == (Scaleform::GFx::AS2::FunctionObject *)1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)ConstStringNode);
        }
      }
      else
      {
        v6 = pData->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v6);
        v6->T.Type = 0;
      }
    }
  }
}
