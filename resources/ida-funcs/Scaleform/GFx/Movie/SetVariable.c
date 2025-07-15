int __thiscall Scaleform::GFx::Movie::SetVariable(
        Scaleform::GFx::Movie *this,
        const char *ppathToVar,
        const Scaleform::GFx::Value *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, const char *, const Scaleform::GFx::Value *, Scaleform::GFx::Movie::SetVarType))this->pASMovieRoot.pObject->SetVariable)(
           this->pASMovieRoot.pObject,
           ppathToVar,
           value,
           setType);
}
