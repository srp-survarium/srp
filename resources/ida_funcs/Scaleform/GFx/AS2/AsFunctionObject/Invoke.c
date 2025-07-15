void __thiscall Scaleform::GFx::AS2::AsFunctionObject::Invoke(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::LocalFrame *localFrame,
        const char *pmethodName)
{
  Scaleform::GFx::AS2::Environment *(__thiscall *GetEnvironment)(Scaleform::GFx::AS2::FunctionObject *, const Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *); // edx
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned __int16 FuncCallNestingLevel; // cx
  Scaleform::GFx::AS2::InvokeContext ctxt; // [esp+8h] [ebp-2Ch] BYREF

  ctxt.pLocalFrame = localFrame;
  GetEnvironment = this->GetEnvironment;
  memset(&ctxt.TargetCh, 0, 20);
  ctxt.pMethodName = pmethodName;
  ctxt.pThis = this;
  ctxt.mFnCall = fn;
  Env = (Scaleform::GFx::AS2::Environment *)((int (__stdcall *)(const Scaleform::GFx::AS2::FnCall *, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *))GetEnvironment)(
                                              fn,
                                              &ctxt.TargetCh);
  ctxt.pOurEnv = Env;
  if ( (Env->Target->Flags & 0x10) != 0 )
  {
    Env = fn->Env;
    ctxt.pOurEnv = Env;
  }
  FuncCallNestingLevel = Env->FuncCallNestingLevel;
  Env->FuncCallNestingLevel = FuncCallNestingLevel + 1;
  if ( FuncCallNestingLevel < 0xFFu )
  {
    Scaleform::GFx::AS2::InvokeContext::Setup(&ctxt);
    Scaleform::GFx::AS2::ActionBuffer::Execute(
      this->pActionBuffer.pObject,
      ctxt.pOurEnv,
      this->StartPc,
      this->Length,
      fn->Result,
      &this->WithStack,
      (Scaleform::GFx::AS2::ActionBuffer::ExecuteType)this->ExecType);
    Scaleform::GFx::AS2::InvokeContext::Cleanup(&ctxt);
  }
  --ctxt.pOurEnv->FuncCallNestingLevel;
  Scaleform::GFx::AS2::InvokeContext::~InvokeContext(&ctxt);
}
