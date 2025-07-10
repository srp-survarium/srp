void __thiscall Scaleform::GFx::FontProviderWin32::LoadFontNames(
        Scaleform::GFx::FontProviderWin32 *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  this->pFontProvider.pObject->LoadFontNames(this->pFontProvider.pObject, fontnames);
}
