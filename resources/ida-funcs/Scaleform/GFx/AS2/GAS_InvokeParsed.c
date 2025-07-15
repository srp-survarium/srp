char __cdecl Scaleform::GFx::AS2::GAS_InvokeParsed(
        Scaleform::GFx::AS2::Value *method,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        const char *pmethodArgFmt,
        char *args,
        const char *pmethodName)
{
  const char *v7; // edx
  int v8; // edi
  Scaleform::GFx::AS2::Environment *v9; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  unsigned int v11; // ebp
  char v12; // al
  const char *v13; // ebx
  char *v14; // ebp
  char *v15; // edi
  char v16; // al
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  int v18; // ecx
  Scaleform::GFx::AS2::Value *v19; // eax
  bool v20; // bl
  Scaleform::GFx::AS2::Value *v21; // eax
  long double v22; // st7
  Scaleform::GFx::AS2::Value *v23; // eax
  char v24; // al
  long double v25; // st7
  Scaleform::GFx::AS2::Value *v26; // eax
  char *v27; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v29; // edi
  Scaleform::GFx::AS2::Value *v30; // eax
  char i; // al
  unsigned int v33; // edx
  unsigned int v34; // eax
  char v35; // al
  const wchar_t *v36; // eax
  Scaleform::GFx::AS2::Value *v37; // ebx
  Scaleform::GFx::AS2::Value *v38; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v39; // esi
  char j; // bl
  const char *p; // [esp+Ch] [ebp-20h]
  char *v43; // [esp+10h] [ebp-1Ch]
  unsigned int v44; // [esp+10h] [ebp-1Ch]
  int startingIndex; // [esp+18h] [ebp-14h]
  int startingIndexa; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS2::Value v; // [esp+1Ch] [ebp-10h] BYREF
  const char *pmethodArgFmta; // [esp+40h] [ebp+14h]

  v7 = pmethodArgFmt;
  v8 = 0;
  if ( pmethodArgFmt )
  {
    v9 = penv;
    p_Stack = &penv->Stack;
    v11 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    v12 = *pmethodArgFmt;
    startingIndex = v11;
    v13 = pmethodArgFmt + 1;
    if ( *pmethodArgFmt )
    {
      v14 = args - 4;
      v15 = args - 8;
      while ( 1 )
      {
        if ( v12 == 37 )
        {
          v16 = *v13++;
          p = v13;
          switch ( v16 )
          {
            case 'd':
              ++p_Stack->pCurrent;
              v15 += 4;
              v14 += 4;
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              pCurrent = p_Stack->pCurrent;
              if ( p_Stack->pCurrent )
              {
                v18 = *(_DWORD *)v14;
                pCurrent->T.Type = 4;
                pCurrent->NV.Int32Value = v18;
              }
              break;
            case 'u':
              v19 = ++p_Stack->pCurrent;
              v.T.Type = 0;
              if ( v19 >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              if ( p_Stack->pCurrent )
              {
                Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &v);
                if ( v.T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&v);
              }
              break;
            case 'n':
              ++p_Stack->pCurrent;
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              if ( p_Stack->pCurrent )
                p_Stack->pCurrent->T.Type = 1;
              break;
            case 'b':
              v14 += 4;
              v15 += 4;
              v20 = *(_DWORD *)v14 != 0;
              ++p_Stack->pCurrent;
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v21 = p_Stack->pCurrent;
              if ( p_Stack->pCurrent )
              {
                v21->T.Type = 2;
                v21->V.BooleanValue = v20;
              }
              goto LABEL_48;
            case 'f':
              v22 = *((double *)v15 + 1);
              ++p_Stack->pCurrent;
              v15 += 8;
              v14 += 8;
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              v23 = p_Stack->pCurrent;
              if ( p_Stack->pCurrent )
              {
                v23->T.Type = 3;
                v23->NV.NumberValue = v22;
              }
              break;
            case 'h':
              v24 = *v13++;
              if ( v24 == 102 )
              {
                v25 = *((double *)v15 + 1);
                ++p_Stack->pCurrent;
                v15 += 8;
                v14 += 8;
                if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
                v26 = p_Stack->pCurrent;
                if ( p_Stack->pCurrent )
                {
                  v26->T.Type = 3;
                  v26->NV.NumberValue = v25;
                }
              }
              else
              {
                Scaleform::GFx::AS2::Environment::LogScriptError(
                  v9,
                  "InvokeParsed('%s','%s') - invalid format '%%h%c'",
                  pmethodName,
                  v7,
                  v24);
              }
              break;
            case 's':
              v27 = (char *)*((_DWORD *)v14 + 1);
              v14 += 4;
              v43 = v15 + 4;
              StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             (Scaleform::GFx::ASStringManager *)v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             v27);
              goto LABEL_41;
            case 'l':
              v35 = *v13++;
              p = v13;
              if ( v35 == 115 )
              {
                v36 = (const wchar_t *)*((_DWORD *)v14 + 1);
                v14 += 4;
                v43 = v15 + 4;
                StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                               (Scaleform::GFx::ASStringManager *)v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                               v36,
                               -1);
LABEL_41:
                v29 = StringNode;
                ++StringNode->RefCount;
                ++p_Stack->pCurrent;
                if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
                v30 = p_Stack->pCurrent;
                if ( p_Stack->pCurrent )
                {
                  v30->T.Type = 5;
                  v30->NV.Int32Value = (int)v29;
                  ++v29->RefCount;
                }
                if ( v29->RefCount-- == 1 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v29);
                v15 = v43;
LABEL_48:
                v13 = p;
                break;
              }
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v9,
                "InvokeParsed('%s','%s') - invalid format '%%l%c'",
                pmethodName,
                v7,
                v35);
              break;
            default:
              Scaleform::GFx::AS2::Environment::LogScriptError(
                v9,
                "InvokeParsed('%s','%s') - invalid format '%%%c'",
                pmethodName,
                v7,
                v16);
              break;
          }
        }
        else
        {
          Scaleform::GFx::AS2::Environment::LogScriptError(
            v9,
            "InvokeParsed('%s','%s') - invalid char '%c'",
            pmethodName,
            v7,
            v12);
        }
        for ( i = *v13; i; i = *++v13 )
        {
          if ( i != 32 && i != 9 && i != 44 )
            break;
        }
        v12 = *v13++;
        if ( !v12 )
        {
          v11 = startingIndex;
          break;
        }
        v7 = pmethodArgFmt;
        v9 = penv;
      }
    }
    v8 = 32 * penv->Stack.Pages.Data.Size + penv->Stack.pCurrent - penv->Stack.pPageStart - v11 - 32;
    if ( v8 >> 1 > 0 )
    {
      v33 = v11 + 1;
      v34 = v8 + startingIndex;
      pmethodArgFmta = (const char *)(v11 + 1);
      v44 = v8 + startingIndex;
      startingIndexa = v8 >> 1;
      while ( 1 )
      {
        v37 = 0;
        if ( v34 <= 32 * (penv->Stack.Pages.Data.Size - 1) + penv->Stack.pCurrent - penv->Stack.pPageStart )
          v37 = &penv->Stack.Pages.Data.Data[v34 >> 5]->Values[v34 & 0x1F];
        v38 = 0;
        if ( v33 <= 32 * (penv->Stack.Pages.Data.Size - 1) + penv->Stack.pCurrent - penv->Stack.pPageStart )
          v38 = &penv->Stack.Pages.Data.Data[v33 >> 5]->Values[v33 & 0x1F];
        Scaleform::GFx::AS2::Value::Value(&v, v38);
        Scaleform::GFx::AS2::Value::operator=(v38, v37);
        Scaleform::GFx::AS2::Value::operator=(v37, &v);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        ++pmethodArgFmta;
        --v44;
        if ( !--startingIndexa )
          break;
        v34 = v44;
        v33 = (unsigned int)pmethodArgFmta;
      }
    }
  }
  v39 = &penv->Stack;
  for ( j = Scaleform::GFx::AS2::GAS_Invoke(
              method,
              presult,
              pthis,
              penv,
              v8,
              penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32,
              pmethodName); v8; --v8 )
  {
    if ( v39->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v39->pCurrent);
    --v39->pCurrent;
    if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v39);
  }
  return j;
}


bool __cdecl Scaleform::GFx::AS2::GAS_InvokeParsed(
        char *pmethodName,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        const char *pmethodArgFmt,
        char *args)
{
  const char *v6; // edi
  Scaleform::GFx::AS2::Environment *v7; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // eax
  bool v11; // bl
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::LocalFrame *v14; // ecx
  unsigned int v15; // eax
  int v16; // eax
  Scaleform::GFx::AS2::ObjectInterface *v17; // eax
  char v18; // al
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v22; // eax
  Scaleform::GFx::InteractiveObject *pnewTarget; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FunctionRef func; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value owner; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value method; // [esp+24h] [ebp-10h] BYREF

  v6 = pmethodName;
  if ( !pmethodName || !*pmethodName )
    return 0;
  v7 = penv;
  pContext = penv->StringContext.pContext;
  pnewTarget = 0;
  method.T.Type = 0;
  owner.T.Type = 0;
  pmethodName = (char *)Scaleform::GFx::ASStringManager::CreateStringNode(
                          (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                          pmethodName);
  ++*((_DWORD *)pmethodName + 3);
  v9 = Scaleform::GFx::AS2::Environment::GetVariable(
         v7,
         (const Scaleform::GFx::ASString *)&pmethodName,
         &method,
         0,
         &pnewTarget,
         &owner,
         0) == 0;
  v10 = (Scaleform::GFx::ASStringNode *)pmethodName;
  v11 = v9;
  --*((_DWORD *)pmethodName + 3);
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v11 )
  {
    if ( owner.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&owner);
    if ( method.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&method);
    return 0;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToFunction(&method, &func, v7);
    Function = func.Function;
    if ( func.Function )
    {
      if ( owner.T.Type == 7 || owner.T.Type == 6 )
      {
        v17 = Scaleform::GFx::AS2::Value::ToObjectInterface(&owner, v7);
      }
      else if ( pnewTarget )
      {
        v16 = (*(int (__thiscall **)(char *))(*((_DWORD *)&pnewTarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                              + pnewTarget->AvmObjOffset)
                                            + 4))(
                (char *)&pnewTarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 4 * pnewTarget->AvmObjOffset);
        if ( v16 )
          v17 = (Scaleform::GFx::AS2::ObjectInterface *)(v16 + 4);
        else
          v17 = 0;
      }
      else
      {
        v17 = pthis;
      }
      v18 = Scaleform::GFx::AS2::GAS_InvokeParsed(&method, presult, v17, v7, pmethodArgFmt, args, v6);
      Flags = func.Flags;
      LOBYTE(pmethodName) = v18;
      if ( (func.Flags & 2) == 0 )
      {
        RefCount = Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
      if ( (Flags & 1) == 0 )
      {
        pLocalFrame = func.pLocalFrame;
        if ( func.pLocalFrame )
        {
          v22 = func.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
          {
            func.pLocalFrame->RefCount = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      if ( owner.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&owner);
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
      return (char)pmethodName;
    }
    else
    {
      if ( (func.Flags & 1) == 0 )
      {
        v14 = func.pLocalFrame;
        if ( func.pLocalFrame )
        {
          v15 = func.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v15) != 0 )
          {
            func.pLocalFrame->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
          }
        }
      }
      if ( owner.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&owner);
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
      return 0;
    }
  }
}
