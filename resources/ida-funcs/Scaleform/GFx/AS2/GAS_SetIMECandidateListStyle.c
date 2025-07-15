void __cdecl Scaleform::GFx::AS2::GAS_SetIMECandidateListStyle(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::AS2::Value *v2; // eax
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::ObjectInterface *v4; // edi
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  bool v14; // bl
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+80h] [ebp-84h]
  bool v19; // [esp+B2h] [ebp-52h]
  bool v20; // [esp+B2h] [ebp-52h]
  bool v21; // [esp+B2h] [ebp-52h]
  bool v22; // [esp+B2h] [ebp-52h]
  bool v23; // [esp+B2h] [ebp-52h]
  bool v24; // [esp+B2h] [ebp-52h]
  bool v25; // [esp+B2h] [ebp-52h]
  bool v26; // [esp+B2h] [ebp-52h]
  bool v27; // [esp+B2h] [ebp-52h]
  Scaleform::GFx::ASStringNode *v28[3]; // [esp+B4h] [ebp-50h] BYREF
  Scaleform::RefCountVImpl *v29; // [esp+C0h] [ebp-44h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // [esp+C4h] [ebp-40h]
  Scaleform::GFx::AS2::Value v31; // [esp+C8h] [ebp-3Ch] BYREF
  Scaleform::GFx::IMECandidateListStyle v32; // [esp+D8h] [ebp-2Ch] BYREF

  if ( fn->NArgs >= 1 )
  {
    pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
    v29 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(
                                        &pMovieImpl->Scaleform::GFx::StateBag,
                                        State_IMEManager);
    if ( v29 )
    {
      Env = fn->Env;
      v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v3 = Scaleform::GFx::AS2::Value::ToObject(v2, Env);
      v30 = v3;
      if ( v3 )
      {
        v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
        v32.Flags = 0;
        v31.T.Type = 0;
        v4 = &v3->Scaleform::GFx::AS2::ObjectInterface;
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "textColor",
                   9u,
                   0);
        ++v28[0]->RefCount;
        v19 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v5 = v28[0];
        --v28[0]->RefCount;
        if ( !v5->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        if ( v19 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 1u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.TextColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "backgroundColor",
                   0xFu,
                   0);
        ++v28[0]->RefCount;
        v20 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v6 = v28[0];
        --v28[0]->RefCount;
        if ( !v6->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
        if ( v20 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 2u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.BackgroundColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "indexBackgroundColor",
                   0x14u,
                   0);
        ++v28[0]->RefCount;
        v21 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v7 = v28[0];
        --v28[0]->RefCount;
        if ( !v7->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        if ( v21 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 4u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.IndexBackgroundColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "selectedTextColor",
                   0x11u,
                   0);
        ++v28[0]->RefCount;
        v22 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v8 = v28[0];
        --v28[0]->RefCount;
        if ( !v8->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( v22 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 8u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.SelectedTextColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "selectedTextBackgroundColor",
                   0x1Bu,
                   0);
        ++v28[0]->RefCount;
        v23 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v9 = v28[0];
        --v28[0]->RefCount;
        if ( !v9->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        if ( v23 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x10u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.SelectedBackgroundColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "selectedIndexBackgroundColor",
                   0x1Cu,
                   0);
        ++v28[0]->RefCount;
        v24 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v10 = v28[0];
        --v28[0]->RefCount;
        if ( !v10->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        if ( v24 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x20u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.SelectedIndexBackgroundColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "fontSize",
                   8u,
                   0);
        ++v28[0]->RefCount;
        v25 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v11 = v28[0];
        --v28[0]->RefCount;
        if ( !v11->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        if ( v25 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x40u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.FontSize = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "readingWindowTextColor",
                   0x16u,
                   0);
        ++v28[0]->RefCount;
        v26 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v12 = v28[0];
        --v28[0]->RefCount;
        if ( !v12->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        if ( v26 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x80u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.ReadingWindowTextColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "readingWindowBackgroundColor",
                   0x1Cu,
                   0);
        ++v28[0]->RefCount;
        v27 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v13 = v28[0];
        --v28[0]->RefCount;
        if ( !v13->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        if ( v27 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x100u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.ReadingWindowBackgroundColor = (unsigned int)v28[0];
          }
        }
        v28[0] = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   "readingWindowFontSize",
                   0x15u,
                   0);
        ++v28[0]->RefCount;
        v14 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)v28, &v31);
        v15 = v28[0];
        --v28[0]->RefCount;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        if ( v14 )
        {
          *(double *)v28 = Scaleform::GFx::AS2::Value::ToNumber(&v31, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(*(long double *)v28) )
          {
            v32.Flags |= 0x200u;
            *(_QWORD *)v28 = (__int64)*(double *)v28;
            v32.ReadingWindowFontSize = (unsigned int)v28[0];
          }
        }
        Scaleform::GFx::IMEManagerBase::SetCandidateListStyle((Scaleform::GFx::IMEManagerBase *)v29, &v32);
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
        v16 = v30;
        RefCount = v30->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v30->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        }
      }
      Scaleform::RefCountImpl::Release(v29);
    }
  }
}
