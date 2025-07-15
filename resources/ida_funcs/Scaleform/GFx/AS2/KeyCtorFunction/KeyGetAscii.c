void __cdecl Scaleform::GFx::AS2::KeyCtorFunction::KeyGetAscii(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  int pObject_low; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-Ch]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    p_pProto = &ThisPtr[-2].pProto;
  else
    p_pProto = 0;
  v3 = 0;
  if ( fn->Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v3 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
  }
  Result = fn->Result;
  pObject_low = LOBYTE(p_pProto[3 * v3 + 16].pObject);
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.Int32Value = pObject_low;
  Result->T.Type = 4;
}
