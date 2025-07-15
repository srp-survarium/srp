void __cdecl Scaleform::GFx::AS2::DateProto::DateValueOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  __int64 *p_pProto; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  double v4; // [esp+4h] [ebp-8h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (__int64 *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Result = fn->Result;
    v4 = (double)p_pProto[7];
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Date");
  }
}
