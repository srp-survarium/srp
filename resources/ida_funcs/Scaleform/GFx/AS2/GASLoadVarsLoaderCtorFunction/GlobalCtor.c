void __cdecl Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value *Result; // esi

  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_LoadVars
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto);
    else
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0);
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 1;
  }
}
