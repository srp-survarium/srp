void __cdecl Scaleform::GFx::AS2::Selection::BroadcastOnSetFocus(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pOldFocus,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        unsigned int controllerIdx)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  long double v9; // st7
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  const Scaleform::GFx::AS2::Value *v11; // eax
  const Scaleform::GFx::AS2::Value *v12; // edi
  const Scaleform::GFx::AS2::Value *v13; // eax
  const Scaleform::GFx::AS2::Value *v14; // edi
  int v15; // edi
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::Value v17; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *pselectionObj; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS2::Value selectionCtorVal; // [esp+20h] [ebp-10h] BYREF
  int nargs; // [esp+34h] [ebp+4h]

  pContext = penv->StringContext.pContext;
  selectionCtorVal.T.Type = 0;
  p_StringContext = &penv->StringContext;
  if ( pContext->pGlobal.pObject->GetMemberRaw(
         &pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &penv->StringContext,
         (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[12].pMovieImpl,
         &selectionCtorVal) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToObject(&selectionCtorVal, penv);
    if ( v7 )
    {
      pselectionObj = &v7->Scaleform::GFx::AS2::ObjectInterface;
      if ( v7 != (Scaleform::GFx::AS2::Object *)-16 )
      {
        nargs = 2;
        if ( p_StringContext->pContext->GFxExtensions.Value == 1 )
        {
          ++penv->Stack.pCurrent;
          *(double *)&v17.T.Type = (double)controllerIdx;
          if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          pCurrent = penv->Stack.pCurrent;
          if ( pCurrent )
          {
            v9 = *(double *)&v17.T.Type;
            pCurrent->T.Type = 3;
            pCurrent->NV.NumberValue = v9;
          }
          nargs = 3;
        }
        if ( pNewFocus )
        {
          Scaleform::GFx::AS2::Value::Value(&v17, pNewFocus);
          ++penv->Stack.pCurrent;
          p_Stack = &penv->Stack;
          v12 = v11;
          if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          if ( p_Stack->pCurrent )
            Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v12);
          if ( v17.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v17);
        }
        else
        {
          ++penv->Stack.pCurrent;
          p_Stack = &penv->Stack;
          if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          if ( p_Stack->pCurrent )
            p_Stack->pCurrent->T.Type = 1;
        }
        if ( pOldFocus )
        {
          Scaleform::GFx::AS2::Value::Value(&v17, pOldFocus);
          ++p_Stack->pCurrent;
          v14 = v13;
          if ( p_Stack->pCurrent >= p_Stack->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
          if ( p_Stack->pCurrent )
            Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v14);
          if ( v17.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v17);
        }
        else
        {
          if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
          if ( p_Stack->pCurrent )
            p_Stack->pCurrent->T.Type = 1;
        }
        v15 = p_Stack->pCurrent - p_Stack->pPageStart + 32 * p_Stack->Pages.Data.Size - 32;
        *(_DWORD *)&v17.T.Type = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                   (Scaleform::GFx::ASStringManager *)p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                   "onSetFocus",
                                   0xAu,
                                   0);
        ++*(_DWORD *)(*(_DWORD *)&v17.T.Type + 12);
        Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage(
          penv,
          pselectionObj,
          (const Scaleform::GFx::ASString *)&v17,
          nargs,
          v15);
        v16 = *(Scaleform::GFx::ASStringNode **)&v17.T.Type;
        --*(_DWORD *)(*(_DWORD *)&v17.T.Type + 12);
        if ( !v16->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(p_Stack, nargs);
      }
    }
  }
  if ( selectionCtorVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&selectionCtorVal);
}
