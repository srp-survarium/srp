void __thiscall Scaleform::Render::Text::TextFormat::SetImageDesc(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::HTMLImageTagDesc *pimage)
{
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // ecx

  if ( pimage )
    ++pimage->RefCount;
  pObject = this->pImageDesc.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pImageDesc.pObject = pimage;
  this->PresentMask |= 0x200u;
}
