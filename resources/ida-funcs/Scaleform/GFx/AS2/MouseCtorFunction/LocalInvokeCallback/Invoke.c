void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::Invoke(
        Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::AS2::FunctionRef *method)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  int v7; // ebp
  int v8; // eax
  Scaleform::GFx::AS2::LocalFrame *v9; // edx
  Scaleform::GFx::AS2::FunctionObject *v10; // ecx
  Scaleform::GFx::AS2::Value eventMethod; // [esp+10h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v12; // [esp+20h] [ebp-24h] BYREF

  Function = method->Function;
  eventMethod.T.Type = 8;
  eventMethod.V.FunctionValue.Flags = 0;
  eventMethod.NV.Int32Value = (int)Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  pLocalFrame = method->pLocalFrame;
  eventMethod.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&eventMethod.V.FunctionValue, pLocalFrame, method->Flags & 1);
  v7 = Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(
         penv,
         this->MouseIndex,
         this->EventName,
         &eventMethod,
         this->pTargetName,
         this->Button,
         this->Delta,
         this->DoubleClick);
  if ( eventMethod.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  if ( v7 >= 0 )
  {
    v8 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    v12.Result = &eventMethod;
    eventMethod.T.Type = 0;
    memset(&v12.ThisFunctionRef, 0, 9);
    v9 = method->pLocalFrame;
    v12.ThisPtr = pthis;
    v10 = method->Function;
    v12.FirstArgBottomIndex = v8;
    v12.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    v12.Env = penv;
    v12.NArgs = v7;
    v10->Invoke(v10, &v12, v9, 0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v12);
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&penv->Stack, v7);
    if ( eventMethod.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  }
}
