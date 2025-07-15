void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayShift(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // esi
  const Scaleform::GFx::AS2::Value **Data; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( p_pProto->Elements.Data.Size )
    {
      Data = (const Scaleform::GFx::AS2::Value **)p_pProto->Elements.Data.Data;
      p_pProto->LengthValueOverriden = 0;
      if ( *Data )
      {
        Scaleform::GFx::AS2::Value::operator=(fn->Result, *Data);
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
      Scaleform::GFx::AS2::ArrayObject::PopFront(p_pProto);
    }
    else
    {
      v3 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v3);
      v3->T.Type = 0;
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
