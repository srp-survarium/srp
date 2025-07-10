Scaleform::GFx::FontManager *__thiscall Scaleform::GFx::DisplayObjectBase::GetFontManager(
        Scaleform::GFx::DisplayObjectBase *this)
{
  if ( this->pParent )
    return this->pParent->GetFontManager(this->pParent);
  else
    return 0;
}
