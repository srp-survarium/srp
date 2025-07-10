void __cdecl Scaleform::GFx::AS2::SharedObjectProto::GetSize(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  unsigned int v2; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  unsigned int v4; // edi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_SharedObject )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr && ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
    {
      v2 = Scaleform::GFx::AS2::SharedObject::ComputeSizeInBytes(
             (Scaleform::GFx::AS2::SharedObject *)&ThisPtr[-2].pProto,
             (Scaleform::GFx::ASStringNode *)fn->Env);
      Result = fn->Result;
      v4 = v2;
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->NV.Int32Value = v4;
      Result->T.Type = 4;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "SharedObject");
  }
}
