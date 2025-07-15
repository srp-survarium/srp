void __usercall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        Scaleform::Render::PrimitiveFillData *this@<edi>,
        const Scaleform::Render::PrimitiveFillData *src@<esi>)
{
  Scaleform::RefCountVImpl **Textures; // ebp
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::Resource *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx

  this->Type = src->Type;
  this->SolidColor.Raw = src->SolidColor.Raw;
  `vector constructor iterator'(
    (char *)this->FillModes,
    1u,
    2,
    (void *(__thiscall *)(void *))Scaleform::Render::ImageFillMode::ImageFillMode);
  Textures = (Scaleform::RefCountVImpl **)this->Textures;
  `vector constructor iterator'(
    (char *)this->Textures,
    4u,
    2,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->pFormat = src->pFormat;
  *(_WORD *)&this->FillModes[0].Fill = *(_WORD *)&src->FillModes[0].Fill;
  pObject = (Scaleform::GFx::Resource *)src->Textures[0].pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  if ( *Textures )
    Scaleform::RefCountImpl::Release(*Textures);
  *Textures = (Scaleform::RefCountVImpl *)src->Textures[0].pObject;
  v4 = (Scaleform::GFx::Resource *)src->Textures[1].pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
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
