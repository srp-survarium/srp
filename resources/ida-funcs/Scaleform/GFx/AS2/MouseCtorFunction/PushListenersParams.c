int __cdecl Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        Scaleform::GFx::AS2::ASBuiltinType eventName,
        Scaleform::GFx::AS2::Value *eventMethod,
        const Scaleform::GFx::ASString *ptargetName,
        unsigned int button,
        int delta,
        bool dblClick)
{
  unsigned __int8 Value; // al
  Scaleform::GFx::AS2::ASBuiltinType v10; // edi
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  bool v14; // zf
  Scaleform::GFx::AS2::LocalFrame *v15; // ecx
  unsigned int v16; // eax
  int v17; // eax
  unsigned __int8 v18; // bl
  unsigned int v19; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::MouseState *v23; // eax
  double v24; // st7
  Scaleform::GFx::AS2::Value *v25; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *v27; // eax
  long double v28; // st7
  double v29; // st7
  Scaleform::GFx::AS2::Value *v30; // eax
  Scaleform::GFx::AS2::Value *v31; // eax
  long double v32; // st7
  Scaleform::GFx::AS2::Value *v33; // esi
  Scaleform::GFx::AS2::Value *v34; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value *v36; // esi
  Scaleform::GFx::AS2::Value *v37; // esi
  Scaleform::GFx::AS2::Value *v38; // esi
  Scaleform::GFx::AS2::Value *v39; // esi
  int v40; // [esp+18h] [ebp-18h]
  float x; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+24h] [ebp-Ch] BYREF
  bool penva; // [esp+34h] [ebp+4h]

  Value = penv->StringContext.pContext->GFxExtensions.Value;
  penva = Value != 1;
  v10 = eventName;
  if ( Value != 1 || !button || eventName != ASBuiltin_onMouseDown && eventName != ASBuiltin_onMouseUp )
    goto LABEL_25;
  Scaleform::GFx::AS2::Value::ToFunction(eventMethod, &result, penv);
  Function = result.Function;
  if ( result.Function )
  {
    if ( result.Function->GetNumArgs(result.Function) <= 0 )
    {
      if ( button > 1 )
      {
        Flags = result.Flags;
        if ( (result.Flags & 2) == 0 )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
        v14 = (Flags & 1) == 0;
        goto LABEL_12;
      }
      penva = 1;
    }
    v18 = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      v19 = Function->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
    if ( (v18 & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v21 = result.pLocalFrame->RefCount;
        if ( (v21 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
LABEL_25:
    v40 = 0;
    if ( penv->StringContext.pContext->GFxExtensions.Value == 1 && !penva )
    {
      if ( eventName == ASBuiltin_onMouseDown && dblClick )
      {
        if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
        pCurrent = penv->Stack.pCurrent;
        if ( pCurrent )
        {
          pCurrent->T.Type = 2;
          pCurrent->V.BooleanValue = dblClick;
        }
        v40 = 1;
      }
      if ( mouseIndex < 6 )
        v23 = &penv->Target->pASRoot->pMovieImpl->mMouseState[mouseIndex];
      else
        v23 = 0;
      x = v23->LastPosition.x;
      v24 = floor(v23->LastPosition.y + 0.5);
      v25 = ++penv->Stack.pCurrent;
      p_Stack = &penv->Stack;
      *(double *)&result.Function = v24 * 0.05;
      if ( v25 >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v27 = p_Stack->pCurrent;
      if ( p_Stack->pCurrent )
      {
        v28 = *(double *)&result.Function;
        v27->T.Type = 3;
        v27->NV.NumberValue = v28;
      }
      v29 = floor(x + 0.5);
      v30 = ++p_Stack->pCurrent;
      *(double *)&result.Function = v29 * 0.05;
      if ( v30 >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v31 = p_Stack->pCurrent;
      if ( p_Stack->pCurrent )
      {
        v32 = *(double *)&result.Function;
        v31->T.Type = 3;
        v31->NV.NumberValue = v32;
      }
      ++p_Stack->pCurrent;
      if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v33 = p_Stack->pCurrent;
      if ( v33 )
      {
        v33->T.Type = 4;
        v33->NV.Int32Value = mouseIndex;
      }
      v40 += 3;
    }
    if ( eventName == ASBuiltin_onMouseMove )
    {
LABEL_66:
      if ( v10 >= ASBuiltin_onMouseDown )
      {
        if ( v10 <= ASBuiltin_onMouseUp )
        {
          if ( button && !penva )
          {
            ++penv->Stack.pCurrent;
            *(double *)&result.Function = (double)button;
            if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
            v38 = penv->Stack.pCurrent;
            if ( v38 )
            {
              v17 = v40 + 1;
              v38->NV.NumberValue = *(double *)&result.Function;
              v38->T.Type = 3;
              return v17;
            }
            goto LABEL_84;
          }
          if ( v40 > 0 )
          {
            if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
            v39 = penv->Stack.pCurrent;
            if ( v39 )
              v39->T.Type = 1;
LABEL_84:
            ++v40;
          }
        }
        else if ( v10 == ASBuiltin_onMouseWheel )
        {
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v37 = penv->Stack.pCurrent;
          if ( v37 )
          {
            v37->NV.Int32Value = delta;
            v17 = v40 + 1;
            v37->T.Type = 4;
            return v17;
          }
          goto LABEL_84;
        }
      }
      return v40;
    }
    if ( ptargetName && (eventName == ASBuiltin_onMouseWheel || !penva) )
    {
      if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v34 = penv->Stack.pCurrent;
      if ( v34 )
      {
        v34->T.Type = 5;
        pNode = ptargetName->pNode;
        v34->NV.Int32Value = (int)ptargetName->pNode;
        ++pNode->RefCount;
      }
    }
    else
    {
      if ( v40 <= 0 )
      {
LABEL_65:
        v10 = eventName;
        goto LABEL_66;
      }
      if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      v36 = penv->Stack.pCurrent;
      if ( v36 )
        v36->T.Type = 1;
    }
    ++v40;
    goto LABEL_65;
  }
  v14 = (result.Flags & 1) == 0;
LABEL_12:
  if ( v14 )
  {
    v15 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v16 = result.pLocalFrame->RefCount;
      if ( (v16 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
      }
    }
  }
  return -1;
}
