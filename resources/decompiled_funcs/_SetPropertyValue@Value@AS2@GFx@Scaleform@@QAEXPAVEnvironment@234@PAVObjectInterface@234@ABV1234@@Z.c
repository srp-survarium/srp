void __thiscall Scaleform::GFx::AS2::Value::SetPropertyValue(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  _DWORD *v7; // eax
  Scaleform::GFx::AS2::Value result; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v9; // [esp+1Ch] [ebp-24h] BYREF

  if ( this->T.Type == 9 && penv )
  {
    if ( *(_DWORD *)(this->NV.Int32Value + 28) )
    {
      v5 = ++penv->Stack.pCurrent;
      p_Stack = &penv->Stack;
      result.T.Type = 0;
      if ( v5 >= penv->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
      if ( p_Stack->pCurrent )
        Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, val);
      v9.FirstArgBottomIndex = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
      v7 = (_DWORD *)(this->NV.Int32Value + 28);
      v9.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      v9.Result = &result;
      v9.ThisPtr = pthis;
      memset(&v9.ThisFunctionRef, 0, 9);
      v9.Env = penv;
      v9.NArgs = 1;
      (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS2::FnCall *, _DWORD, _DWORD))(*(_DWORD *)*v7 + 40))(
        *v7,
        &v9,
        v7[1],
        0);
      Scaleform::GFx::AS2::FnCall::~FnCall(&v9);
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      --p_Stack->pCurrent;
      if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
      if ( result.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&result);
    }
    else if ( penv->IsVerboseActionErrors(penv) )
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(penv, "Setter method is null.");
    }
  }
}
