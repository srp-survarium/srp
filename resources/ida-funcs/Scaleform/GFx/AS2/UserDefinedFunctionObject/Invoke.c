void __thiscall Scaleform::GFx::AS2::UserDefinedFunctionObject::Invoke(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
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
  Scaleform::GFx::AS2::FnCall fna; // [esp+4h] [ebp-24h] BYREF

  if ( this->pContext.pObject )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr && ThisPtr->IsSuper(fn->ThisPtr) )
    {
      NArgs = fn->NArgs;
      Env = fn->Env;
      Result = fn->Result;
      fna.FirstArgBottomIndex = fn->FirstArgBottomIndex;
      p_pProto = (Scaleform::GFx::AS2::SuperObject *)&ThisPtr[-2].pProto;
      fna.Result = Result;
      RealThis = p_pProto->RealThis;
      fna.NArgs = NArgs;
      fna.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
      fna.ThisPtr = RealThis;
      memset(&fna.ThisFunctionRef, 0, 9);
      fna.Env = Env;
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(this, &fna);
      Scaleform::GFx::AS2::SuperObject::ResetAltProto(p_pProto);
      Scaleform::GFx::AS2::FnCall::~FnCall(&fna);
    }
    else
    {
      Scaleform::GFx::AS2::UserDefinedFunctionObject::InvokeImpl(this, fn);
    }
  }
}
