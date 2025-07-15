void __cdecl Scaleform::GFx::AS2::LoadVarsProto::SendAndLoad(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::LogState *v1; // eax

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_LoadVars )
  {
    v1 = (Scaleform::GFx::LogState *)fn->Env->Target->GetLog(fn->Env->Target);
    if ( v1 )
      Scaleform::GFx::LogState::LogMessageByType(
        v1,
        (Scaleform::LogMessageId)&loc_34000,
        "LoadVars.sendAndLoad is not implemented.");
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "LoadVars");
  }
}
