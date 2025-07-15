void __thiscall Scaleform::GFx::AS2::Value::SetAsFunction(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::FunctionRefBase *func)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  if ( this->T.Type != 8 || (Scaleform::GFx::AS2::FunctionObject *)this->NV.Int32Value != func->Function )
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 8;
    this->V.FunctionValue.Flags = 0;
    Function = func->Function;
    this->NV.Int32Value = (int)func->Function;
    if ( Function )
      Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
    this->V.FunctionValue.pLocalFrame = 0;
    pLocalFrame = func->pLocalFrame;
    if ( pLocalFrame )
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->V.FunctionValue, pLocalFrame, func->Flags & 1);
  }
}
