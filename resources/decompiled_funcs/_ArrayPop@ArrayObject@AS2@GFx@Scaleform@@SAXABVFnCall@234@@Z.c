void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayPop(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // esi
  unsigned int Size; // eax
  const Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *Result; // edi
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Value *v7; // edi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Size = p_pProto->Elements.Data.Size;
    p_pProto->LengthValueOverriden = 0;
    if ( Size )
    {
      v4 = p_pProto->Elements.Data.Data[Size - 1];
      if ( v4 )
      {
        Scaleform::GFx::AS2::Value::operator=(fn->Result, v4);
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
      v6 = p_pProto->Elements.Data.Size;
      if ( v6 )
        Scaleform::GFx::AS2::ArrayObject::Resize(p_pProto, v6 - 1);
    }
    else
    {
      v7 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v7);
      v7->T.Type = 0;
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
