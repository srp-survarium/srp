char __thiscall Scaleform::GFx::AS2ValueObjectInterface::CreateObjectValue(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::CharacterHandle *pdata,
        bool isdobj)
{
  return Scaleform::GFx::AS2::MovieRoot::CreateObjectValue(
           (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject,
           pval,
           this,
           pdata,
           isdobj);
}
