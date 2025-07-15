void __thiscall Scaleform::GFx::FontManager::FontManager(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::MovieImpl *movie,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontMap::MapEntry *p_FontMapEntry; // edi

  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::GFx::FontManager::`vftable';
  this->CreatedFonts.pTable = 0;
  this->FontMovies.Data.Data = 0;
  this->FontMovies.Data.Size = 0;
  p_FontMapEntry = &this->FontMapEntry;
  this->FontMovies.Data.Policy.Capacity = 0;
  this->pEmptyFont.pObject = 0;
  Scaleform::String::String(&this->FontMapEntry.Name);
  p_FontMapEntry->ScaleFactor = 1.0;
  p_FontMapEntry->Flags = MFF_Original;
  this->pIMECandidateFont.pObject = 0;
  this->pDefImpl = pdefImpl;
  this->pMovie = movie;
  this->pWeakLib = 0;
  this->pState = pstate;
  Scaleform::GFx::FontManager::commonInit(this);
}


void __thiscall Scaleform::GFx::FontManager::FontManager(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::ResourceWeakLib *pweakLib,
        Scaleform::GFx::FontManagerStates *pstate)
{
  Scaleform::GFx::FontMap::MapEntry *p_FontMapEntry; // edi

  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::GFx::FontManager::`vftable';
  this->CreatedFonts.pTable = 0;
  this->FontMovies.Data.Data = 0;
  this->FontMovies.Data.Size = 0;
  p_FontMapEntry = &this->FontMapEntry;
  this->FontMovies.Data.Policy.Capacity = 0;
  this->pEmptyFont.pObject = 0;
  Scaleform::String::String(&this->FontMapEntry.Name);
  p_FontMapEntry->ScaleFactor = 1.0;
  p_FontMapEntry->Flags = MFF_Original;
  this->pIMECandidateFont.pObject = 0;
  this->pState = pstate;
  this->pMovie = 0;
  this->pDefImpl = 0;
  this->pWeakLib = pweakLib;
  Scaleform::GFx::FontManager::commonInit(this);
}
