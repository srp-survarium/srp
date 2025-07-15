void __thiscall Scaleform::GFx::AS2::AsFunctionObject::Invoke(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::LocalFrame *localFrame,
        const char *pmethodName)
{
  Scaleform::GFx::AS2::Environment *(__thiscall *GetEnvironment)(Scaleform::GFx::AS2::FunctionObject *, const Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *); // edx
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned __int16 FuncCallNestingLevel; // cx
  Scaleform::GFx::AS2::InvokeContext v8; // [esp+8h] [ebp-2Ch] BYREF

  v8.pLocalFrame = localFrame;
  GetEnvironment = this->GetEnvironment;
  memset(&v8.TargetCh, 0, 20);
  v8.pMethodName = pmethodName;
  v8.pThis = this;
  v8.mFnCall = fn;
  Env = (Scaleform::GFx::AS2::Environment *)((int (__stdcall *)(const Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *))GetEnvironment)(
                                              fn,
                                              &v8.TargetCh);
  v8.pOurEnv = Env;
  if ( (Env->Target->Flags & 0x10) != 0 )
  {
    Env = fn->Env;
    v8.pOurEnv = Env;
  }
  FuncCallNestingLevel = Env->FuncCallNestingLevel;
  Env->FuncCallNestingLevel = FuncCallNestingLevel + 1;
  if ( FuncCallNestingLevel < 0xFFu )
  {
    Scaleform::GFx::AS2::InvokeContext::Setup(&v8);
    Scaleform::GFx::AS2::ActionBuffer::Execute(
      this->pActionBuffer.pObject,
      v8.pOurEnv,
      this->StartPc,
      this->Length,
      fn->Result,
      &this->WithStack,
      (Scaleform::GFx::AS2::ActionBuffer::ExecuteType)this->ExecType);
    Scaleform::GFx::AS2::InvokeContext::Cleanup(&v8);
    --v8.pOurEnv->FuncCallNestingLevel;
    Scaleform::GFx::AS2::InvokeContext::~InvokeContext(&v8);
  }
  else
  {
    if ( v8.pOurEnv->IsVerboseActionErrors(v8.pOurEnv) )
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v8.pOurEnv,
        "Stack overflow, max level of 255 nested calls is reached.");
    --v8.pOurEnv->FuncCallNestingLevel;
    Scaleform::GFx::AS2::InvokeContext::~InvokeContext(&v8);
  }
}
