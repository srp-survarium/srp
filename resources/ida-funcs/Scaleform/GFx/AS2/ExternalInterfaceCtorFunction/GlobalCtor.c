void __cdecl Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // esi

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
}
