void __thiscall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        Scaleform::Render::PrimitiveFillData *this,
        Scaleform::Render::PrimitiveFillType type,
        const Scaleform::Render::VertexFormat *format,
        Scaleform::GFx::Resource *texture0,
        Scaleform::Render::ImageFillMode fm0,
        Scaleform::GFx::Resource *texture1,
        Scaleform::Render::ImageFillMode fm1)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::RefCountVImpl *v9; // ecx

  this->Type = type;
  this->SolidColor.Raw = 0;
  this->Textures[0].pObject = 0;
  this->Textures[1].pObject = 0;
  this->pFormat = format;
  this->FillModes[0] = fm0;
  this->FillModes[1] = fm1;
  if ( texture0 )
    Scaleform::RefCountImpl::AddRef(texture0);
  pObject = (Scaleform::RefCountVImpl *)this->Textures[0].pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Textures[0].pObject = (Scaleform::Render::Texture *)texture0;
  if ( texture1 )
    Scaleform::RefCountImpl::AddRef(texture1);
  v9 = (Scaleform::RefCountVImpl *)this->Textures[1].pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  this->Textures[1].pObject = (Scaleform::Render::Texture *)texture1;
}
