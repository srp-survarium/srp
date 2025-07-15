void __thiscall Scaleform::Render::TextPrimitiveBundle::UpdateMesh(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::BundleEntry *entry)
{
  Scaleform::Render::BundleEntry *v2; // esi
  Scaleform::Render::TreeCacheText *pSourceNode; // edi
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax
  Scaleform::Render::TextMeshProvider *v6; // esi

  v2 = entry;
  if ( Scaleform::Render::Bundle::findEntryIndex(this, (unsigned int *)&entry, entry) )
  {
    pSourceNode = (Scaleform::Render::TreeCacheText *)v2->pSourceNode;
    MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider(pSourceNode);
    v6 = MeshProvider;
    if ( MeshProvider )
    {
      if ( MeshProvider->pBundle )
      {
        Scaleform::Render::TextPrimitiveBundle::removeEntryFromLayers(this, &pSourceNode->SorterShapeNode);
        v6->pBundle = 0;
        v6->pBundleEntry = 0;
      }
    }
  }
}
