void __thiscall Scaleform::GFx::AS2::Object::Watchpoint::Watchpoint(
        Scaleform::GFx::AS2::Object::Watchpoint *this,
        const Scaleform::GFx::AS2::Object::Watchpoint *__that)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax

  this->Callback.Flags = 0;
  Function = __that->Callback.Function;
  this->Callback.Function = __that->Callback.Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Callback.pLocalFrame = 0;
  pLocalFrame = __that->Callback.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->Callback, pLocalFrame, __that->Callback.Flags & 1);
  Scaleform::GFx::AS2::Value::Value(&this->UserData, &__that->UserData);
}
