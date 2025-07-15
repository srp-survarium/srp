Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::Value::ToResolveHandler(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::FunctionRef *result)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::FunctionRef *v4; // eax

  if ( this->T.Type == 12 )
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
  else
  {
    v4 = result;
    result->Flags = 0;
    result->Function = 0;
    result->pLocalFrame = 0;
  }
  return v4;
}
