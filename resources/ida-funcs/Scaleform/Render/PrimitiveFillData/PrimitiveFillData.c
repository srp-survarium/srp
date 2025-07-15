void __userpurge Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        const Scaleform::Render::PrimitiveFillData *src@<esi>,
        Scaleform::Render::PrimitiveFillData *this)
{
  Scaleform::Render::Texture *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::Render::Texture *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  this->Type = src->Type;
  this->SolidColor.Raw = src->SolidColor.Raw;
  *(_WORD *)&this->FillModes[0].Fill = 0;
  this->Textures[0].pObject = 0;
  this->Textures[1].pObject = 0;
  this->pFormat = src->pFormat;
  *(_WORD *)&this->FillModes[0].Fill = *(_WORD *)&src->FillModes[0].Fill;
  pObject = src->Textures[0].pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
  v3 = (Scaleform::RefCountVImpl *)this->Textures[0].pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  this->Textures[0].pObject = src->Textures[0].pObject;
  v4 = src->Textures[1].pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v4);
  v5 = (Scaleform::RefCountVImpl *)this->Textures[1].pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->Textures[1].pObject = src->Textures[1].pObject;
}


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
