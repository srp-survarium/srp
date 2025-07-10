void __thiscall Scaleform::GFx::Sprite::SetIMECandidateListFont(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::Resource *pfontHandle)
{
  if ( pfontHandle )
    Scaleform::GFx::FontManager::SetIMECandidateFont(this->pRootNode->pFontManager.pObject, pfontHandle);
}
