void __thiscall Scaleform::Render::TextPrimitiveBundle::pinLayerBatches(Scaleform::Render::TextPrimitiveBundle *this)
{
  unsigned int i; // ebx
  _DWORD *p_pData; // eax
  int v4; // edi
  unsigned int j; // esi
  Scaleform::Render::TextMeshProvider *MeshProvider; // eax

  for ( i = 0; i < this->Layers.Size; ++i )
  {
    if ( this->Layers.Size <= 2 )
      p_pData = &this->Layers.AD.pData;
    else
      p_pData = &this->Layers.AD.pData->pObject;
    v4 = p_pData[i];
    for ( j = 0; j < *(_DWORD *)(v4 + 56); ++j )
    {
      MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider(*(Scaleform::Render::TreeCacheText **)(*(_DWORD *)(*(_DWORD *)(v4 + 52) + 4 * j) + 28));
      ++MeshProvider->PinCount;
    }
  }
}
