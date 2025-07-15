void __thiscall Scaleform::GFx::Movie::CreateFunction(
        Scaleform::GFx::Movie *this,
        Scaleform::GFx::Value *pvalue,
        Scaleform::GFx::FunctionHandler *pfc,
        void *puserData)
{
  this->pASMovieRoot.pObject->CreateFunction(this->pASMovieRoot.pObject, pvalue, pfc, puserData);
}
