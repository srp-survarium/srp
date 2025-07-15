Scaleform::GFx::AS2::RefCountBaseGC<323> *__usercall Scaleform::GFx::AS2::TextFieldProto::ParseStyle@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *result,
        const Scaleform::GFx::AS2::FnCall *fn,
        unsigned int paramIndex,
        Scaleform::GFx::ASStringNode *initialHInfo,
        int a7,
        Scaleform::GFx::ASString a8)
{
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // ecx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::ObjectInterface *v14; // edi
  char v15; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  bool v17; // al
  Scaleform::GFx::ASStringNode *v18; // ecx
  bool v19; // zf
  bool v20; // bl
  long double v21; // st7
  unsigned int v22; // eax
  bool v23; // bl
  Scaleform::GFx::ASStringNode *v24; // eax
  bool v25; // al
  Scaleform::GFx::ASStringNode *v26; // ecx
  bool v27; // bl
  long double v28; // st7
  unsigned int v29; // eax
  bool v30; // bl
  Scaleform::GFx::ASStringNode *v31; // eax
  bool v32; // al
  Scaleform::GFx::ASStringNode *v33; // ecx
  bool v34; // bl
  long double v35; // st7
  unsigned int v36; // eax
  char v37; // bl
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v43; // [esp+3Ch] [ebp-10h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v44; // [esp+50h] [ebp+4h]

  v8 = initialHInfo;
  result->__vftable = (Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *)initialHInfo->pData;
  result->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v8->pManager;
  result->RootIndex = (unsigned int)v8->pLower;
  LOBYTE(result->RefCount) = v8->RefCount;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v11 = fn->FirstArgBottomIndex - paramIndex;
    v12 = 0;
    if ( v11 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v12 = &Env->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    v13 = Scaleform::GFx::AS2::Value::ToObject(v12, Env);
    v44 = v13;
    if ( v13 )
    {
      v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
      v43.T.Type = 0;
      v14 = &v13->Scaleform::GFx::AS2::ObjectInterface;
      initialHInfo = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "textColor",
                       9u,
                       0);
      ++initialHInfo->RefCount;
      v15 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, int, int))v14->GetMember)(
              v14,
              fn->Env,
              &initialHInfo,
              &v43,
              a2,
              a1);
      pNode = a8.pNode;
      --a8.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v15 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v17 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v18 = a8.pNode;
        v19 = a8.pNode->RefCount-- == 1;
        v20 = v17;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        if ( v20 )
        {
          LOBYTE(result->RefCount) &= ~0x10u;
        }
        else
        {
          v21 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v21) )
          {
            v22 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                    fn->Env);
            LOBYTE(result->RefCount) |= 0x10u;
            result->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)(v22 | 0xFF000000);
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "backgroundColor",
                   0xFu,
                   0);
      ++a8.pNode->RefCount;
      v23 = v14->GetMember(v14, fn->Env, &a8, (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4));
      v24 = a8.pNode;
      --a8.pNode->RefCount;
      if ( !v24->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v25 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v26 = a8.pNode;
        v19 = a8.pNode->RefCount-- == 1;
        v27 = v25;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        if ( v27 )
        {
          LOBYTE(result->RefCount) &= ~8u;
        }
        else
        {
          v28 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v28) )
          {
            v29 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                    fn->Env);
            LOBYTE(result->RefCount) |= 8u;
            result->__vftable = (Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *)(v29 | 0xFF000000);
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "underlineColor",
                   0xEu,
                   0);
      ++a8.pNode->RefCount;
      v30 = v14->GetMember(v14, fn->Env, &a8, (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4));
      v31 = a8.pNode;
      --a8.pNode->RefCount;
      if ( !v31->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      if ( v30 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(
          (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
          &a8,
          fn->Env,
          -1,
          0);
        v32 = Scaleform::GFx::ASString::operator==(&a8, "none");
        v33 = a8.pNode;
        v19 = a8.pNode->RefCount-- == 1;
        v34 = v32;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v33);
        if ( v34 )
        {
          LOBYTE(result->RefCount) &= ~0x20u;
        }
        else
        {
          v35 = Scaleform::GFx::AS2::Value::ToNumber(
                  (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                  fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(v35) )
          {
            v36 = Scaleform::GFx::AS2::Value::ToUInt32(
                    (Scaleform::GFx::AS2::Value *)((char *)&v43.NV.NumberValue + 4),
                    fn->Env);
            LOBYTE(result->RefCount) |= 0x20u;
            result->RootIndex = v36 | 0xFF000000;
          }
        }
      }
      a8.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "underlineStyle",
                   0xEu,
                   0);
      ++a8.pNode->RefCount;
      v37 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *))v14->GetMember)(
              v14,
              fn->Env);
      v38 = initialHInfo;
      --initialHInfo->RefCount;
      if ( !v38->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      if ( v37 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&v43, (Scaleform::GFx::ASString *)&initialHInfo, fn->Env, -1, 0);
        if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "dotted") )
        {
          LOBYTE(result->RefCount) = result->RefCount & 0xF8 | 3;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "single") )
        {
          LOBYTE(result->RefCount) = result->RefCount & 0xF8 | 1;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "thick") )
        {
          LOBYTE(result->RefCount) = result->RefCount & 0xF8 | 2;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "ditheredSingle") )
        {
          LOBYTE(result->RefCount) = result->RefCount & 0xF8 | 5;
        }
        else if ( Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&initialHInfo, "ditheredThick") )
        {
          LOBYTE(result->RefCount) = result->RefCount & 0xF8 | 6;
        }
        else
        {
          LOBYTE(result->RefCount) &= 0xF8u;
        }
        v39 = initialHInfo;
        v19 = initialHInfo->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v39);
      }
      if ( v43.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v43);
      RefCount = v44->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v44->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v44);
      }
    }
  }
  return result;
}
