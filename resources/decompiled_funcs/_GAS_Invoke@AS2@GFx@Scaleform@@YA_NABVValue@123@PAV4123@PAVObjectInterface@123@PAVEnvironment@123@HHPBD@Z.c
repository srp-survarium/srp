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
