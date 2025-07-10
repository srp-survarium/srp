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
