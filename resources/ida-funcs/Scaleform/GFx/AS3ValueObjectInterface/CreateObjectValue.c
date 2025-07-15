char __thiscall Scaleform::GFx::AS3ValueObjectInterface::CreateObjectValue(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::Value *pval,
        _DWORD *pdata,
        bool isdobj)
{
  return Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(
           (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject,
           pval,
           this,
           pdata,
           isdobj);
}
