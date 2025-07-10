void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayReverse(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // esi
  int v3; // eax
  int v4; // edx
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>_vtbl *v6; // edi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Array )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v3 = p_pProto[1].RootIndex - 1;
    v4 = 0;
    for ( LOBYTE(p_pProto[1].pProto.pObject) = 0; v4 < v3; --v3 )
    {
      pRCC = p_pProto[1].pRCC;
      v6 = (&pRCC->__vftable)[v4];
      (&pRCC->__vftable)[v4] = (&pRCC->__vftable)[v3];
      (&pRCC->__vftable)[v3] = v6;
      ++v4;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
