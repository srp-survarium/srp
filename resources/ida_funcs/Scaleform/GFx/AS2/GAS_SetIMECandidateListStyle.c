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
  Scaleform::GFx::AS2::Environment *v_4; // [esp+80h] [ebp-84h]
  bool v19; // [esp+B2h] [ebp-52h]
  bool v20; // [esp+B2h] [ebp-52h]
  bool v21; // [esp+B2h] [ebp-52h]
  bool v22; // [esp+B2h] [ebp-52h]
  bool v23; // [esp+B2h] [ebp-52h]
  bool v24; // [esp+B2h] [ebp-52h]
  bool v25; // [esp+B2h] [ebp-52h]
  bool v26; // [esp+B2h] [ebp-52h]
  bool v27; // [esp+B2h] [ebp-52h]
  long double n; // [esp+B4h] [ebp-50h] BYREF
  Scaleform::Ptr<Scaleform::GFx::IMEManagerBase> pimeMgr; // [esp+C0h] [ebp-44h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // [esp+C4h] [ebp-40h]
  Scaleform::GFx::AS2::Value val; // [esp+C8h] [ebp-3Ch] BYREF
  Scaleform::GFx::IMECandidateListStyle st; // [esp+D8h] [ebp-2Ch] BYREF

  if ( fn->NArgs >= 1 )
  {
    pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
    pimeMgr.pObject = (Scaleform::GFx::IMEManagerBase *)pMovieImpl->GetStateAddRef(
                                                          &pMovieImpl->Scaleform::GFx::StateBag,
                                                          State_IMEManager);
    if ( pimeMgr.pObject )
    {
      v_4 = fn->Env;
      v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v3 = Scaleform::GFx::AS2::Value::ToObject(v2, v_4);
      v30 = v3;
      if ( v3 )
      {
        v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
        st.Flags = 0;
        val.T.Type = 0;
        v4 = &v3->Scaleform::GFx::AS2::ObjectInterface;
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "textColor",
                       9u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v19 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v5 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v5->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
        if ( v19 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 1u;
            *(_QWORD *)&n = (__int64)n;
            st.TextColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "backgroundColor",
                       0xFu,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v20 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v6 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v6->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v6);
        if ( v20 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 2u;
            *(_QWORD *)&n = (__int64)n;
            st.BackgroundColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "indexBackgroundColor",
                       0x14u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v21 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v7 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v7->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        if ( v21 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 4u;
            *(_QWORD *)&n = (__int64)n;
            st.IndexBackgroundColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "selectedTextColor",
                       0x11u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v22 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v8 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v8->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        if ( v22 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 8u;
            *(_QWORD *)&n = (__int64)n;
            st.SelectedTextColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "selectedTextBackgroundColor",
                       0x1Bu,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v23 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v9 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v9->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        if ( v23 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x10u;
            *(_QWORD *)&n = (__int64)n;
            st.SelectedBackgroundColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "selectedIndexBackgroundColor",
                       0x1Cu,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v24 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v10 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v10->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        if ( v24 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x20u;
            *(_QWORD *)&n = (__int64)n;
            st.SelectedIndexBackgroundColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "fontSize",
                       8u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v25 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v11 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v11->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        if ( v25 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x40u;
            *(_QWORD *)&n = (__int64)n;
            st.FontSize = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "readingWindowTextColor",
                       0x16u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v26 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v12 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v12->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        if ( v26 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x80u;
            *(_QWORD *)&n = (__int64)n;
            st.ReadingWindowTextColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "readingWindowBackgroundColor",
                       0x1Cu,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v27 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v13 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v13->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        if ( v27 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x100u;
            *(_QWORD *)&n = (__int64)n;
            st.ReadingWindowBackgroundColor = LODWORD(n);
          }
        }
        LODWORD(n) = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "readingWindowFontSize",
                       0x15u,
                       0);
        ++*(_DWORD *)(LODWORD(n) + 12);
        v14 = v4->GetMember(v4, fn->Env, (const Scaleform::GFx::ASString *)&n, &val);
        v15 = (Scaleform::GFx::ASStringNode *)LODWORD(n);
        --*(_DWORD *)(LODWORD(n) + 12);
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        if ( v14 )
        {
          n = Scaleform::GFx::AS2::Value::ToNumber(&val, fn->Env);
          if ( !Scaleform::GFx::NumberUtil::IsNaNOrInfinity(n) )
          {
            st.Flags |= 0x200u;
            *(_QWORD *)&n = (__int64)n;
            st.ReadingWindowFontSize = LODWORD(n);
          }
        }
        Scaleform::GFx::IMEManagerBase::SetCandidateListStyle(pimeMgr.pObject, &st);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v16 = v30;
        RefCount = v30->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v30->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        }
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pimeMgr.pObject);
    }
  }
}
