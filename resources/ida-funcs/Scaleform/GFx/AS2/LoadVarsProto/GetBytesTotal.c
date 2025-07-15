void __cdecl Scaleform::GFx::AS2::LoadVarsProto::GetBytesTotal(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  double *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  double v4; // [esp+4h] [ebp-8h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_LoadVars )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (double *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Result = fn->Result;
    if ( p_pProto[8] >= 0.0 )
    {
      v4 = p_pProto[8];
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 3;
      Result->NV.NumberValue = v4;
    }
    else
    {
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}
