void __thiscall Scaleform::Render::TextMeshProvider::GetFillData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::FillData *data,
        unsigned int layer,
        unsigned int fillIndex,
        char meshGenFlags)
{
  int v5; // eax
  Scaleform::Render::TextMeshLayer *v6; // eax
  const Scaleform::Render::FillData *v7; // eax
  Scaleform::Render::RawImage *Image; // eax
  const Scaleform::Render::FillData *v9; // eax
  Scaleform::Render::Image *v10; // esi
  const Scaleform::Render::FillData *v11; // eax
  const Scaleform::Render::FillData *v12; // eax
  const Scaleform::Render::FillData *v13; // eax
  const Scaleform::Render::FillData *v14; // eax
  Scaleform::Render::FillData v15; // [esp+8h] [ebp-78h] BYREF
  Scaleform::Render::FillData v16; // [esp+1Ch] [ebp-64h] BYREF
  Scaleform::Render::FillData v17; // [esp+30h] [ebp-50h] BYREF
  Scaleform::Render::FillData v18; // [esp+44h] [ebp-3Ch] BYREF
  Scaleform::Render::FillData v19; // [esp+58h] [ebp-28h] BYREF
  Scaleform::Render::FillData v20; // [esp+6Ch] [ebp-14h] BYREF

  if ( (meshGenFlags & 2) != 0 )
  {
    Scaleform::Render::FillData::FillData(&v15, Fill_Mask);
    data->Type = *(_DWORD *)v5;
    data->Color = *(_DWORD *)(v5 + 4);
    data->Color = *(_DWORD *)(v5 + 4);
    data->Color = *(_DWORD *)(v5 + 4);
    data->PrimFill = *(_DWORD *)(v5 + 8);
    data->FillMode.Fill = *(_BYTE *)(v5 + 12);
    data->pVFormat = *(const Scaleform::Render::VertexFormat **)(v5 + 16);
  }
  else
  {
    v6 = &this->Layers.Data.Data[layer];
    switch ( v6->Type )
    {
      case TextLayer_Background:
      case TextLayer_Selection:
      case TextLayer_Shapes:
      case TextLayer_Underline:
      case TextLayer_Cursor:
      case TextLayer_Shapes_Masked:
      case TextLayer_Underline_Masked:
        Scaleform::Render::FillData::FillData(&v15, Fill_VColor);
        Scaleform::Render::FillData::operator=(data, v7);
        data->PrimFill = PrimFill_VColor;
        data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
        break;
      case TextLayer_Shadow:
      case TextLayer_ShadowText:
      case TextLayer_RasterText:
        Image = Scaleform::Render::GlyphCache::GetImage(this->pCache, this->Entries.Data.Data[v6->Start].TextureId);
        Scaleform::Render::FillData::FillData(&v16, Image, (Scaleform::Render::ImageFillMode)3);
        Scaleform::Render::FillData::operator=(data, v9);
        data->PrimFill = PrimFill_UVTextureAlpha_VColor;
        data->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        break;
      case TextLayer_PackedText:
        v10 = *(Scaleform::Render::Image **)(this->Entries.Data.Data[v6->Start].EntryData.BackgroundData.BorderColor + 8);
        Scaleform::Render::FillData::FillData(&v17, v10, (Scaleform::Render::ImageFillMode)3);
        Scaleform::Render::FillData::operator=(data, v11);
        if ( v10->GetFormat(v10) == Image_A8 )
        {
          data->PrimFill = PrimFill_UVTextureAlpha_VColor;
          data->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        }
        else
        {
          data->PrimFill = PrimFill_UVTexture;
          data->pVFormat = &Scaleform::Render::ImageGlyphVertex::Format;
        }
        break;
      case TextLayer_PackedDFAText:
        Scaleform::Render::FillData::FillData(
          &v18,
          *(Scaleform::Render::Image **)(this->Entries.Data.Data[v6->Start].EntryData.BackgroundData.BorderColor + 8),
          (Scaleform::Render::ImageFillMode)3);
        Scaleform::Render::FillData::operator=(data, v12);
        data->PrimFill = PrimFill_UVTextureDFAlpha_VColor;
        data->pVFormat = &Scaleform::Render::RasterGlyphVertex::Format;
        break;
      case TextLayer_Images:
        Scaleform::Render::FillData::FillData(
          &v19,
          this->Entries.Data.Data[v6->Start].EntryData.ImageData.pImage,
          (Scaleform::Render::ImageFillMode)3);
        Scaleform::Render::FillData::operator=(data, v13);
        data->PrimFill = PrimFill_UVTexture;
        data->pVFormat = &Scaleform::Render::ImageGlyphVertex::Format;
        break;
      case TextLayer_Mask:
        Scaleform::Render::FillData::FillData(&v20, Fill_Mask);
        Scaleform::Render::FillData::operator=(data, v14);
        break;
      default:
        return;
    }
  }
}
