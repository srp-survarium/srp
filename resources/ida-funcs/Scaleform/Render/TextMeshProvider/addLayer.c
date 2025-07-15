void __thiscall Scaleform::Render::TextMeshProvider::addLayer(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        unsigned int start,
        unsigned int end)
{
  unsigned int v4; // ebp
  unsigned int v6; // esi
  unsigned int v7; // ebx
  unsigned __int16 LayerType; // ax
  Scaleform::Render::TextMeshLayer *v9; // eax
  unsigned int v10; // esi
  Scaleform::Render::TextMeshProvider *v11; // [esp+10h] [ebp-2Ch]
  Scaleform::Render::TextMeshLayer layer; // [esp+18h] [ebp-24h] BYREF
  unsigned __int16 storagea; // [esp+40h] [ebp+4h]

  v4 = start;
  v6 = start >> 6;
  v7 = start & 0x3F;
  LayerType = storage->Entries.Pages[v6][v7].LayerType;
  v11 = this;
  storagea = LayerType;
  if ( LayerType == 4 && this->Layers.Data.Size )
  {
    v9 = &this->Layers.Data.Data[this->Layers.Data.Size - 1];
    if ( v9->Type == TextLayer_Shadow || v9->Type == TextLayer_ShadowText )
    {
      if ( storage->Entries.Pages[v6][v7].pFill == storage->Entries.Pages[v9->Start >> 6][v9->Start & 0x3F].pFill )
      {
        v9->Count += end - start;
        v9->Type = TextLayer_ShadowText;
        return;
      }
      v4 = start;
    }
    LayerType = storagea;
  }
  memset(&layer.pMesh, 0, 12);
  layer.M.pHandle = &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  layer.pFill.pObject = 0;
  if ( LayerType == 8 || LayerType == 12 )
  {
    if ( v4 < end )
    {
      while ( 1 )
      {
        Scaleform::Render::TextMeshProvider::addLayer(
          this,
          storage,
          (Scaleform::Render::TextLayerType)storage->Entries.Pages[v6][start & 0x3F].LayerType,
          v4++,
          1u);
        if ( v4 >= end )
          break;
        this = v11;
      }
    }
  }
  else if ( LayerType == 7 )
  {
    v10 = v4;
    if ( v4 < end )
    {
      while ( 1 )
      {
        Scaleform::Render::TextMeshProvider::addLayer(this, storage, TextLayer_Images, v10++, 1u);
        if ( v10 >= end )
          break;
        this = v11;
      }
    }
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(&layer);
  }
  else
  {
    Scaleform::Render::TextMeshProvider::addLayer(
      this,
      storage,
      (Scaleform::Render::TextLayerType)LayerType,
      v4,
      end - v4);
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(&layer);
  }
}


void __thiscall Scaleform::Render::TextMeshProvider::addLayer(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::TextLayerType type,
        unsigned int start,
        unsigned int count)
{
  unsigned int v6; // ecx
  unsigned int v7; // ebx
  unsigned int v8; // edi
  Scaleform::Render::TmpTextMeshLayer *v9; // eax
  Scaleform::Render::PrimitiveFill *layer_12; // [esp+1Ch] [ebp-4h]

  do
  {
    v6 = count;
    v7 = count;
    if ( count >= 0x3FFE )
      v7 = 16382;
    v8 = storage->Layers.Size >> 4;
    layer_12 = storage->Entries.Pages[start >> 6][start & 0x3F].pFill;
    if ( v8 >= storage->Layers.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PathType,4,4>::allocPage(&storage->Layers, v8);
      v6 = count;
    }
    v9 = &storage->Layers.Pages[v8][storage->Layers.Size & 0xF];
    v9->Type = type;
    v9->Start = start;
    v9->Count = v7;
    v9->pFill = layer_12;
    ++storage->Layers.Size;
    start += v7;
    count = v6 - v7;
  }
  while ( v6 != v7 );
}
