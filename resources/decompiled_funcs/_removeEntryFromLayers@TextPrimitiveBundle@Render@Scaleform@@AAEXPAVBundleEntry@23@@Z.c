void __thiscall Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::BundleEntry *e)
{
  Scaleform::Render::BundleEntry *v2; // ebp
  unsigned int v4; // edi
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *p_Layers; // esi
  Scaleform::Render::TextLayerPrimitive **p_pObject; // eax
  _DWORD *p_pData; // eax
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax
  Scaleform::Render::MaskPrimitive *pObject; // eax
  unsigned int Size; // ecx
  Scaleform::Render::MatrixPoolImpl::HMatrix *Data; // edx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v12; // esi
  unsigned int v13; // eax
  Scaleform::Render::MaskPrimitive *v14; // eax

  v2 = e;
  v4 = 0;
  p_Layers = &this->Layers;
  if ( this->Layers.Size )
  {
    do
    {
      if ( p_Layers->Size <= 2 )
        p_pObject = (Scaleform::Render::TextLayerPrimitive **)&p_Layers->4;
      else
        p_pObject = &p_Layers->AD.pData->pObject;
      Scaleform::Render::TextLayerPrimitive::RemoveEntry(p_pObject[v4], v2);
      if ( p_Layers->Size <= 2 )
        p_pData = &p_Layers->AD.pData;
      else
        p_pData = &p_Layers->AD.pData->pObject;
      if ( !*(_DWORD *)(p_pData[v4] + 36) )
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(
          p_Layers,
          v4--);
      ++v4;
    }
    while ( v4 < p_Layers->Size );
  }
  if ( this->pMaskPrimitive.pObject )
  {
    MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider((Scaleform::Render::TreeCacheText *)v2->pSourceNode);
    if ( MeshProvider && (MeshProvider->Flags & 0x100) != 0 )
    {
      Scaleform::Render::TextMeshProvider::GetMaskClearBounds(
        MeshProvider,
        (Scaleform::Render::MatrixPoolImpl::HMatrix *)&e);
      pObject = this->pMaskPrimitive.pObject;
      Size = pObject->MaskAreas.Data.Size;
      Data = pObject->MaskAreas.Data.Data;
      v12 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)e;
      v13 = 0;
      if ( Size )
      {
        while ( (Scaleform::Render::BundleEntry *)Data[v13].pHandle != e )
        {
          if ( ++v13 >= Size )
            goto LABEL_19;
        }
        Scaleform::Render::MaskPrimitive::Remove(this->pMaskPrimitive.pObject, v13, 1u);
        v12 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)e;
      }
LABEL_19:
      if ( v12 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
        Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v12->pHeader);
    }
    v14 = this->pMaskPrimitive.pObject;
    if ( !v14->MaskAreas.Data.Size )
    {
      if ( v14 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pMaskPrimitive.pObject);
      this->pMaskPrimitive.pObject = 0;
    }
  }
}
