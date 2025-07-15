void __cdecl Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // edi
  Scaleform::GFx::AS2::ObjectInterface *v3; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi

  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_MovieClipLoader
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        v3 = fn->ThisPtr;
LABEL_9:
        Scaleform::GFx::AS2::AsBroadcaster::AddListener(fn->Env, v3, ThisPtr);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
        return;
      }
    }
    else
    {
      p_pProto = 0;
    }
    ThisPtr = 0;
    v3 = 0;
    goto LABEL_9;
  }
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 1;
}
