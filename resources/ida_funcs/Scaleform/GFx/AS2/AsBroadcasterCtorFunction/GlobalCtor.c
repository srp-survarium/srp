void __cdecl Scaleform::GFx::AS2::AsBroadcasterCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // edi

  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_AsBroadcaster
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
    if ( p_pProto )
    {
      RefCount = p_pProto->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        p_pProto->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
      }
    }
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 1;
  }
}
