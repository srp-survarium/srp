void __thiscall Scaleform::GFx::FontManager::SetIMECandidateFont(
        Scaleform::GFx::FontManager *this,
        Scaleform::GFx::Resource *pfont)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( pfont )
    Scaleform::RefCountImpl::AddRef(pfont);
  pObject = (Scaleform::RefCountVImpl *)this->pIMECandidateFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pIMECandidateFont.pObject = (Scaleform::GFx::FontHandle *)pfont;
}
