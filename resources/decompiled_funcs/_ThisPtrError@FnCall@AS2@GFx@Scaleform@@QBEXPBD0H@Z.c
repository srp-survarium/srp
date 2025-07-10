void __thiscall Scaleform::GFx::AS2::FnCall::ThisPtrError(
        Scaleform::GFx::AS2::FnCall *this,
        const char *className,
        const char *psrcfile,
        int line)
{
  Scaleform::GFx::AS2::Environment::LogScriptError(
    this->Env,
    "Error: Null or invalid 'this' is used for a method of %s class.\n",
    className);
}
