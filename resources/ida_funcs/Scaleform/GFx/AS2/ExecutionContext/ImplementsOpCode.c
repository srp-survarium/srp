void __thiscall Scaleform::GFx::AS2::ExecutionContext::ImplementsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // ecx
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v7; // edi
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::ObjectInterface *v11; // ebx
  unsigned int i; // edi
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // ecx
  Scaleform::GFx::AS2::FunctionObject *v15; // esi
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v19; // eax
  unsigned __int8 v20; // bl
  unsigned int v21; // eax
  Scaleform::GFx::AS2::LocalFrame *v22; // ecx
  unsigned int v23; // eax
  signed int intfNum; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS2::ObjectInterface *v25; // [esp+28h] [ebp-3Ch]
  Scaleform::GFx::AS2::FunctionRef intfFunc; // [esp+2Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [esp+38h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value protoVal; // [esp+44h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value ctorFuncVal; // [esp+54h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&ctorFuncVal, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = this->pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  v4 = Scaleform::GFx::AS2::Value::ToInt32(pPrevPageTop, this->pEnv);
  v5 = this->pEnv->Stack.pCurrent;
  p_Stack = &this->pEnv->Stack;
  intfNum = v4;
  if ( &v5[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    --p_Stack->pCurrent;
    if ( p_Stack->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
    --p_Stack->pCurrent;
  }
  else
  {
    v7 = 2;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      if ( --p_Stack->pCurrent < p_Stack->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
      --v7;
    }
    while ( v7 );
  }
  if ( ctorFuncVal.T.Type == 8 || ctorFuncVal.T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&ctorFuncVal, &ctorFunc, this->pEnv);
    Function = ctorFunc.Function;
    if ( ctorFunc.Function )
    {
      pEnv = this->pEnv;
      protoVal.T.Type = 0;
      if ( ctorFunc.Function->GetMemberRaw(
             &ctorFunc.Function->Scaleform::GFx::AS2::ObjectInterface,
             &pEnv->StringContext,
             (const Scaleform::GFx::ASString *)&pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
             &protoVal) )
      {
        v10 = Scaleform::GFx::AS2::Value::ToObject(&protoVal, this->pEnv);
        if ( v10 )
        {
          v11 = &v10->Scaleform::GFx::AS2::ObjectInterface;
          v25 = &v10->Scaleform::GFx::AS2::ObjectInterface;
          v10->AddInterface(&v10->Scaleform::GFx::AS2::ObjectInterface, &this->pEnv->StringContext, intfNum, 0);
          for ( i = 0; (int)i < intfNum; ++i )
          {
            v13 = 32 * (this->pEnv->Stack.Pages.Data.Size - 1)
                + this->pEnv->Stack.pCurrent
                - this->pEnv->Stack.pPageStart;
            v14 = 0;
            if ( i <= v13 )
              v14 = &this->pEnv->Stack.Pages.Data.Data[(v13 - i) >> 5]->Values[(v13 - i) & 0x1F];
            if ( v14->T.Type == 8 || v14->T.Type == 11 )
            {
              Scaleform::GFx::AS2::Value::ToFunction(v14, &intfFunc, this->pEnv);
              v15 = intfFunc.Function;
              if ( intfFunc.Function )
                v11->AddInterface(v11, &this->pEnv->StringContext, i, intfFunc.Function);
              Flags = intfFunc.Flags;
              if ( (intfFunc.Flags & 2) == 0 )
              {
                if ( v15 )
                {
                  RefCount = v15->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
                  {
                    v15->RefCount = RefCount - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
                  }
                }
              }
              intfFunc.Function = 0;
              if ( (Flags & 1) == 0 )
              {
                pLocalFrame = intfFunc.pLocalFrame;
                if ( intfFunc.pLocalFrame )
                {
                  v19 = intfFunc.pLocalFrame->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v19) != 0 )
                  {
                    intfFunc.pLocalFrame->RefCount = v19 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
                  }
                }
              }
              v11 = v25;
              intfFunc.pLocalFrame = 0;
            }
            Function = ctorFunc.Function;
          }
        }
      }
      if ( protoVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&protoVal);
    }
    v20 = ctorFunc.Flags;
    if ( (ctorFunc.Flags & 2) == 0 )
    {
      if ( Function )
      {
        v21 = Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v21) != 0 )
        {
          Function->RefCount = v21 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (v20 & 1) == 0 )
    {
      v22 = ctorFunc.pLocalFrame;
      if ( ctorFunc.pLocalFrame )
      {
        v23 = ctorFunc.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
        {
          ctorFunc.pLocalFrame->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
        }
      }
    }
  }
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&this->pEnv->Stack, intfNum);
  if ( ctorFuncVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&ctorFuncVal);
}
