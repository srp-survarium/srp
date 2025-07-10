Scaleform::GFx::FontHandle *__thiscall Scaleform::GFx::FontManager::GetEmptyFont(Scaleform::GFx::FontManager *this)
{
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->pEmptyFont.pObject);
  return this->pEmptyFont.pObject;
}
