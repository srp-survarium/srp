void __thiscall Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage_::_4_::LocalInvokeCallback::Invoke(
        Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::__l4::LocalInvokeCallback *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::AS2::FunctionRef *method)
{
  int FirstArgBottomIndex; // eax
  int NArgs; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::Value result; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v9; // [esp+1Ch] [ebp-24h] BYREF

  FirstArgBottomIndex = this->FirstArgBottomIndex;
  NArgs = this->NArgs;
  v9.Result = &result;
  v9.FirstArgBottomIndex = FirstArgBottomIndex;
  v9.ThisPtr = pthis;
  v9.NArgs = NArgs;
  Function = method->Function;
  pLocalFrame = method->pLocalFrame;
  result.T.Type = 0;
  memset(&v9.ThisFunctionRef, 0, 9);
  v9.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  v9.Env = penv;
  Function->Invoke(Function, &v9, pLocalFrame, 0);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v9);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
}
