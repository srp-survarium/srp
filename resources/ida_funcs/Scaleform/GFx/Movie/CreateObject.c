void __thiscall Scaleform::GFx::Movie::CreateObject(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pvalue,
        const char *className,
        const Scaleform::GFx::Value *pargs,
        unsigned int nargs)
{
  this->pASMovieRoot.pObject->CreateObject(this->pASMovieRoot.pObject, pvalue, className, pargs, nargs);
}
