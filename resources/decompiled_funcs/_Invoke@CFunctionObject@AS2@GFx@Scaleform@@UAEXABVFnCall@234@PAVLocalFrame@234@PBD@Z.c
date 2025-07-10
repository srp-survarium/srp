void __thiscall Scaleform::GFx::AS2::CFunctionObject::Invoke(
        Scaleform::GFx::AS2::CFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::GFx::AS2::LocalFrame *__formal,
        const char *a4)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  int NArgs; // ecx
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::SuperObject *p_pProto; // edi
  Scaleform::GFx::AS2::ObjectInterface *RealThis; // esi
  void (__cdecl *pFunction)(const Scaleform::GFx::AS2::FnCall *); // ecx
  Scaleform::GFx::AS2::FnCall fn2; // [esp+4h] [ebp-24h] BYREF

  if ( this->pFunction )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr && ThisPtr->IsSuper(fn->ThisPtr) )
    {
      NArgs = fn->NArgs;
      Env = fn->Env;
      Result = fn->Result;
      fn2.FirstArgBottomIndex = fn->FirstArgBottomIndex;
      p_pProto = (Scaleform::GFx::AS2::SuperObject *)&ThisPtr[-2].pProto;
      fn2.Result = Result;
      RealThis = p_pProto->RealThis;
      fn2.NArgs = NArgs;
      pFunction = this->pFunction;
      fn2.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      fn2.ThisPtr = RealThis;
      memset(&fn2.ThisFunctionRef, 0, 9);
      fn2.Env = Env;
      pFunction(&fn2);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto(p_pProto);
      Scaleform::GFx::AS2::FnCall::~FnCall(&fn2);
    }
    else
    {
      this->pFunction(fn);
    }
  }
}
