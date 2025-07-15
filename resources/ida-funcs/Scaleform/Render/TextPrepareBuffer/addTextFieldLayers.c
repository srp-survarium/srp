void __thiscall Scaleform::Render::TextPrepareBuffer::addTextFieldLayers(
        Scaleform::Render::TextPrepareBuffer *this,
        bool startFlag)
{
  Scaleform::Render::TreeCacheText *pRemainingTextFields; // eax
  Scaleform::Render::TreeCacheText *pNextNoBatch; // ebp
  Scaleform::Render::TextMeshProvider *MeshProvider; // edi
  Scaleform::Render::TreeCacheText *v6; // eax
  Scaleform::Render::TreeCacheText *v7; // [esp+4h] [ebp-4h]

  pRemainingTextFields = this->pRemainingTextFields;
  v7 = pRemainingTextFields;
  if ( pRemainingTextFields )
  {
    do
    {
      pNextNoBatch = this->pRemainingTextFields->pNextNoBatch;
      if ( !this->LayersPinned )
      {
        Scaleform::Render::TextPrimitiveBundle::pinLayerBatches(this->pBundle);
        this->LayersPinned = 1;
      }
      MeshProvider = Scaleform::Render::TreeCacheText::GetMeshProvider(this->pRemainingTextFields);
      if ( !MeshProvider )
      {
        MeshProvider = Scaleform::Render::TreeCacheText::CreateMeshProvider(this->pRemainingTextFields);
        if ( !MeshProvider )
          break;
      }
      Scaleform::Render::TextMeshProvider::AddToInUseList(MeshProvider);
      if ( Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(
             this->pBundle,
             this->pRemainingTextFields,
             MeshProvider) )
      {
        v6 = this->pRemainingTextFields;
        MeshProvider->pBundle = this->pBundle;
        MeshProvider->pBundleEntry = &v6->SorterShapeNode;
      }
      this->pRemainingTextFields->pNextNoBatch = 0;
      this->pRemainingTextFields = pNextNoBatch;
    }
    while ( pNextNoBatch );
    pRemainingTextFields = v7;
  }
  if ( !startFlag && pRemainingTextFields == this->pRemainingTextFields )
    this->pRemainingTextFields = 0;
}
