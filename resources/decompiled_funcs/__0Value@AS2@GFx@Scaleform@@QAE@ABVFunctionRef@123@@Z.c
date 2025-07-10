void __thiscall Scaleform::GFx::AS2::Value::Value(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::FunctionRef *func)
{
  $52EB37658F6E465B8DB431649A109BC1 *v2; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  this->T.Type = 8;
  v2 = &this->V.4;
  v2->FunctionValue.Flags = 0;
  Function = func->Function;
  v2->pStringNode = (Scaleform::GFx::ASStringNode *)func->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  v2->FunctionValue.pLocalFrame = 0;
  pLocalFrame = func->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)v2,
      pLocalFrame,
      func->Flags & 1);
}
