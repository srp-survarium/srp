void __cdecl Scaleform::GFx::AS2::FunctionProto::ValueOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto);
  else
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, 0);
}
