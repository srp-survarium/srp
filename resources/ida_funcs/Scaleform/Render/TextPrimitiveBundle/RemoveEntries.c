void __thiscall Scaleform::Render::TextPrimitiveBundle::RemoveEntries(
        Scaleform::Render::TextPrimitiveBundle *this,
        unsigned int index,
        unsigned int count)
{
  unsigned int v3; // ebx
  Scaleform::Render::TreeCacheText *pSourceNode; // edi
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax
  Scaleform::Render::TextMeshProvider *v7; // esi

  v3 = index;
  if ( index < index + count )
  {
    do
    {
      pSourceNode = (Scaleform::Render::TreeCacheText *)this->Entries.Data.Data[v3]->pSourceNode;
      MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider(pSourceNode);
      v7 = MeshProvider;
      if ( MeshProvider && MeshProvider->pBundle )
      {
        Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(this, &pSourceNode->SorterShapeNode);
        v7->pBundle = 0;
        v7->pBundleEntry = 0;
      }
      ++v3;
    }
    while ( v3 < index + count );
    v3 = index;
  }
  Scaleform::Render::Bundle::RemoveEntries(this, v3, count);
}
