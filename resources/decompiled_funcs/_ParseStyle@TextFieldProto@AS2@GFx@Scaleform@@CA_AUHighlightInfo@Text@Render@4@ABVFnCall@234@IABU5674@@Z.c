Scaleform::Render::Text::HighlightInfo *__usercall Scaleform::GFx::AS2::TextFieldProto::ParseStyle@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        Scaleform::Render::Text::HighlightInfo *result,
        const Scaleform::GFx::AS2::FnCall *fn,
        unsigned int paramIndex,
        Scaleform::GFx::ASStringNode *initialHInfo,
        int a7,
        Scaleform::GFx::ASString a8)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value *v11; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::ObjectInterface *v13; // edi
  char v14; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v16; // al
  Scaleform::GFx::ASStringNode *v17; // ecx
  bool v18; // zf
  bool v19; // bl
  long double v20; // st7
  unsigned int v21; // eax
  bool v22; // bl
  Scaleform::GFx::ASStringNode *v23; // eax
  bool v24; // al
  Scaleform::GFx::ASStringNode *v25; // ecx
  bool v26; // bl
  long double v27; // st7
  unsigned int v28; // eax
  bool v29; // bl
  Scaleform::GFx::ASStringNode *v30; // eax
  bool v31; // al
  Scaleform::GFx::ASStringNode *v32; // ecx
  bool v33; // bl
  long double v34; // st7
  unsigned int v35; // eax
  char v36; // bl
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [esp+3Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *resulta; // [esp+50h] [ebp+4h]

  *result = *(Scaleform::Render::Text::HighlightInfo *)&initialHInfo->pData;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v10 = fn->FirstArgBottomIndex - paramIndex;
    v11 = 0;
    if ( v10 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v11 = &Env->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
    v12 = Scaleform::GFx::AS2::Value::ToObject(v11, Env);
    resulta = v12;
    if ( v12 )
    {
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
      val.T.Type = 0;
      v13 = &v12->Scaleform::GFx::AS2::ObjectInterface;
      initialHInfo = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "textColor",
                       9u,
                       0);
      ++initialHInfo->RefCount;
      v14 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, int, int))v13->GetMember)(
              v13,
              fn->Env,
              &initialHInfo,
              &val,
              a2,
              a1);
      pNode = a8.pNode;
      --a8.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v14 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v16 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v17 = a8.pNode;
        v18 = a8.pNode->RefCount-- == 1;
        v19 = v16;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        if ( v19 )
        {
          result->Flags &= ~0x10u;
        }
        else
        {
          v20 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v20) )
          {
            v21 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                    fn->Env);
            result->Flags |= 0x10u;
            result->TextColor.Raw = v21 | 0xFF000000;
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "backgroundColor",
                   0xFu,
                   0);
      ++a8.pNode->RefCount;
      v22 = v13->GetMember(v13, fn->Env, &a8, (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4));
      v23 = a8.pNode;
      --a8.pNode->RefCount;
      if ( !v23->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      if ( v22 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v24 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v25 = a8.pNode;
        v18 = a8.pNode->RefCount-- == 1;
        v26 = v24;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        if ( v26 )
        {
          result->Flags &= ~8u;
        }
        else
        {
          v27 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v27) )
          {
            v28 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                    fn->Env);
            result->Flags |= 8u;
            result->BackgroundColor.Raw = v28 | 0xFF000000;
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "underlineColor",
                   0xEu,
                   0);
      ++a8.pNode->RefCount;
      v29 = v13->GetMember(v13, fn->Env, &a8, (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4));
      v30 = a8.pNode;
      --a8.pNode->RefCount;
      if ( !v30->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      if ( v29 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v31 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v32 = a8.pNode;
        v18 = a8.pNode->RefCount-- == 1;
        v33 = v31;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
        if ( v33 )
        {
          result->Flags &= ~0x20u;
        }
        else
        {
          v34 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v34) )
          {
            v35 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&val.NV.NumberValue + 4),
                    fn->Env);
            result->Flags |= 0x20u;
            result->UnderlineColor.Raw = v35 | 0xFF000000;
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "underlineStyle",
                   0xEu,
                   0);
      ++a8.pNode->RefCount;
      v36 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))v13->GetMember)(
              v13,
              fn->Env);
      v37 = initialHInfo;
      --initialHInfo->RefCount;
      if ( !v37->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      if ( v36 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&val, (Scaleform::GFx::ASString *)&initialHInfo, fn->Env, -1, 0);
        if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "dotted") )
        {
          result->Flags = result->Flags & 0xF8 | 3;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "single") )
        {
          result->Flags = result->Flags & 0xF8 | 1;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "thick") )
        {
          result->Flags = result->Flags & 0xF8 | 2;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "ditheredSingle") )
        {
          result->Flags = result->Flags & 0xF8 | 5;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "ditheredThick") )
        {
          result->Flags = result->Flags & 0xF8 | 6;
        }
        else
        {
          result->Flags &= 0xF8u;
        }
        v38 = initialHInfo;
        v18 = initialHInfo->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      }
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      RefCount = resulta->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        resulta->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(resulta);
      }
    }
  }
  return result;
}
