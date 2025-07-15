Scaleform::Render::Font *__thiscall Scaleform::GFx::FontProvider::CreateFontA(
        Scaleform::GFx::FontProviderWin32 *this,
        const char *name,
        unsigned int fontFlags)
{
  return this->pFontProvider.pObject->CreateFontA(this->pFontProvider.pObject, name, fontFlags);
}
