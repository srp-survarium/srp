void __thiscall Scaleform::GFx::LoadProcess::SetJpegHeader(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::Resource *pth)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  if ( pth )
    Scaleform::RefCountImpl::AddRef(pth);
  pObject = (Scaleform::RefCountVImpl *)this->pJpegTables.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pJpegTables.pObject = (Scaleform::Render::JPEG::TablesHeader *)pth;
}
