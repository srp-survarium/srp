int __thiscall Scaleform::GFx::Movie::Invoke(
        Scaleform::GFx::Movie *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, const char *, Scaleform::GFx::Value *, const Scaleform::GFx::Value *, unsigned int))this->pASMovieRoot.pObject->Invoke)(
           this->pASMovieRoot.pObject,
           pmethodName,
           presult,
           pargs,
           numArgs);
}
