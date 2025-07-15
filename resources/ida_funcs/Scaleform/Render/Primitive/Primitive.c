void __thiscall Scaleform::Render::Primitive::Primitive(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::HAL *phal,
        Scaleform::Render::PrimitiveFill *pfill)
{
  Scaleform::Render::PrimitiveFillType Type; // edx
  char v5; // cl

  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::Primitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::Primitive_vtbl *)&Scaleform::Render::Primitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,68>'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::Primitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->pHAL = phal;
  if ( pfill )
    ++pfill->RefCount;
  this->pFill.pObject = pfill;
  this->Batches.Root.pPrev = (Scaleform::Render::PrimitiveBatch *)&this->Batches;
  this->Batches.Root.pNext = (Scaleform::Render::PrimitiveBatch *)&this->Batches;
  Type = pfill->Data.Type;
  if ( Type < PrimFill_Texture || Type > PrimFill_2Texture_EAlpha )
    v5 = 0;
  else
    v5 = (Type >= PrimFill_2Texture) + 1;
  ++Primitive_CreateCount;
  ++Primitive_Total;
  this->MatricesPerMesh = v5 + 1;
  this->Meshes.Data.Data = 0;
  this->Meshes.Data.Size = 0;
  this->Meshes.Data.Policy.Capacity = 0;
  this->ModifyIndex = 0;
}
