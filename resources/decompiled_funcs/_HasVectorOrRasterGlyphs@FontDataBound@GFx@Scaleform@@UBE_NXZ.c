int __thiscall Scaleform::GFx::FontDataBound::HasVectorOrRasterGlyphs(Scaleform::GFx::FontDataBound *this)
{
  return ((int (__thiscall *)(Scaleform::Render::Font *))this->pFont.pObject->HasVectorOrRasterGlyphs)(this->pFont.pObject);
}
