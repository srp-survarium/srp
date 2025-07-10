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
