void __cdecl Scaleform::GFx::AS2::ObjectProto::ValueOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value::SetAsObjectInterface(fn->Result, fn->ThisPtr);
}
