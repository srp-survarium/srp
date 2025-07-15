char __cdecl Scaleform::GFx::AS2::GAS_Invoke(
        Scaleform::GFx::AS2::Value *method,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        int nargs,
        int firstArgBottomIndex,
        const char *pmethodName)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  unsigned int RefCount; // eax
  unsigned int v10; // eax
  Scaleform::GFx::AS2::LocalFrame *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::FunctionRef func; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FnCall v15; // [esp+18h] [ebp-24h] BYREF

  Scaleform::GFx::AS2::Value::ToFunction(method, &func, penv);
  if ( presult )
  {
    Scaleform::GFx::AS2::Value::DropRefs(presult);
    presult->T.Type = 0;
  }
  Function = func.Function;
  if ( func.Function )
  {
    v15.FirstArgBottomIndex = firstArgBottomIndex;
    v15.Result = presult;
    pLocalFrame = func.pLocalFrame;
    v15.ThisPtr = pthis;
    v15.NArgs = nargs;
    v15.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v15.ThisFunctionRef, 0, 9);
    v15.Env = penv;
    func.Function->Invoke(func.Function, &v15, func.pLocalFrame, pmethodName);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v15);
    if ( (func.Flags & 2) == 0 )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
    if ( (func.Flags & 1) == 0 && pLocalFrame )
    {
      v10 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
      {
        pLocalFrame->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
    return 1;
  }
  else
  {
    if ( (func.Flags & 1) == 0 )
    {
      v12 = func.pLocalFrame;
      if ( func.pLocalFrame )
      {
        v13 = func.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
        {
          func.pLocalFrame->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
        }
      }
    }
    return 0;
  }
}


bool __cdecl Scaleform::GFx::AS2::GAS_Invoke(
        char *pmethodName,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        int numArgs,
        int firstArgBottomIndex)
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
      v18 = Scaleform::GFx::AS2::GAS_Invoke(&method, presult, v17, v7, numArgs, firstArgBottomIndex, v6);
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
