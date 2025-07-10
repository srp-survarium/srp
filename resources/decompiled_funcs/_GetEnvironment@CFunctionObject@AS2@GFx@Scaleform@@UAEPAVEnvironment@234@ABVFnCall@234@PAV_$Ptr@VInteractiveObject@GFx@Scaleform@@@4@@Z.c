Scaleform::GFx::AS2::Environment *__thiscall Scaleform::GFx::AS2::CFunctionObject::GetEnvironment(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        const Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *ptargetCh)
{
  return fn->Env;
}
