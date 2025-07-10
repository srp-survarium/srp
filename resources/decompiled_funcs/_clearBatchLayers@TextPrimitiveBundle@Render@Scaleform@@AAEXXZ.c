void __thiscall Scaleform::Render::TextPrimitiveBundle::clearBatchLayers(Scaleform::Render::TextPrimitiveBundle *this)
{
  unsigned int i; // edi
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  for ( i = 0; i < this->Entries.Data.Size; ++i )
  {
    MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider((Scaleform::Render::TreeCacheText *)this->Entries.Data.Data[i]->pSourceNode);
    if ( MeshProvider )
    {
      MeshProvider->pBundle = 0;
      MeshProvider->pBundleEntry = 0;
    }
  }
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(&this->Layers);
  pObject = (Scaleform::RefCountVImpl *)this->pMaskPrimitive.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pMaskPrimitive.pObject = 0;
}
