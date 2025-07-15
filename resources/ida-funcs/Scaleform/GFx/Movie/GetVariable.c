int __thiscall Scaleform::GFx::Movie::GetVariable(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::Value *, const char *))this->pASMovieRoot.pObject->GetVariable)(
           this->pASMovieRoot.pObject,
           pval,
           ppathToVar);
}
