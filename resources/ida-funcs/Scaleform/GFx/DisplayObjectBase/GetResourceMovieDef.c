Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::DisplayObjectBase::GetResourceMovieDef(
        Scaleform::GFx::DisplayObjectBase *this)
{
  if ( this->pParent )
    return this->pParent->GetResourceMovieDef(this->pParent);
  else
    return 0;
}
