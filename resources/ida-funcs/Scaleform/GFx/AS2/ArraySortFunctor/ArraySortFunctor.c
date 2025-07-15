void __thiscall Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(
        Scaleform::GFx::AS2::ArraySortFunctor *this,
        const Scaleform::GFx::AS2::ArraySortFunctor *__that)
{
  Scaleform::GFx::AS2::FunctionRef *p_Func; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  this->This = __that->This;
  this->Flags = __that->Flags;
  p_Func = &this->Func;
  p_Func->Flags = 0;
  Function = __that->Func.Function;
  p_Func->Function = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  p_Func->pLocalFrame = 0;
  pLocalFrame = __that->Func.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Func, pLocalFrame, __that->Func.Flags & 1);
  this->Env = __that->Env;
  this->LogPtr = __that->LogPtr;
}


void __thiscall Scaleform::GFx::AS2::ArraySortFunctor::ArraySortFunctor(
        Scaleform::GFx::AS2::ArraySortFunctor *this,
        Scaleform::GFx::AS2::ObjectInterface *pThis,
        int flags,
        const Scaleform::GFx::AS2::FunctionRef *func,
        Scaleform::GFx::AS2::Environment *env,
        const Scaleform::Log *log)
{
  Scaleform::GFx::AS2::FunctionRef *p_Func; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  this->Flags = flags;
  this->This = pThis;
  p_Func = &this->Func;
  p_Func->Flags = 0;
  Function = func->Function;
  p_Func->Function = func->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  p_Func->pLocalFrame = 0;
  pLocalFrame = func->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Func, pLocalFrame, func->Flags & 1);
  this->Env = env;
  this->LogPtr = log;
}
