void __thiscall Scaleform::Render::VectorGlyphShape::GetFillData(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::FillData *data,
        unsigned int layer,
        unsigned int fillIndex,
        unsigned int meshGenFlags)
{
  int v5; // eax
  Scaleform::Render::FillData v6; // [esp+0h] [ebp-14h] BYREF

  Scaleform::Render::FillData::FillData(&v6, Fill_VColor);
  data->Type = *(_DWORD *)v5;
  data->Color = *(_DWORD *)(v5 + 4);
  data->Color = *(_DWORD *)(v5 + 4);
  data->Color = *(_DWORD *)(v5 + 4);
  data->PrimFill = *(_DWORD *)(v5 + 8);
  data->FillMode.Fill = *(_BYTE *)(v5 + 12);
  data->PrimFill = PrimFill_VColor;
  data->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
}
