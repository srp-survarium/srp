Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::Value::ToFunction(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        const Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::FunctionRef *v3; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  if ( this->T.Type == 8 )
  {
    result->Flags = 0;
    Function = this->V.FunctionValue.Function;
    result->Function = Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    result->pLocalFrame = 0;
    pLocalFrame = this->V.FunctionValue.pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(result, pLocalFrame, this->V.FunctionValue.Flags & 1);
    return result;
  }
  else if ( this->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ResolveFunctionName(this, result, penv);
    return result;
  }
  else
  {
    v3 = result;
    result->Flags = 0;
    result->Function = 0;
    result->pLocalFrame = 0;
  }
  return v3;
}
