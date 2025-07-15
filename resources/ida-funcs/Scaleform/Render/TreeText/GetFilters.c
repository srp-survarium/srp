unsigned int __thiscall Scaleform::Render::TreeText::GetFilters(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::Filter *filtersBuf,
        unsigned int filtersCntInBuf)
{
  int v3; // ecx
  unsigned int v4; // esi
  double v5; // st7
  Scaleform::Render::TreeText::Filter *v6; // eax
  Scaleform::Render::TreeText::Filter *v8; // eax

  v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                             + 20)
                 + 144);
  if ( !v3 )
    return 0;
  v4 = 0;
  if ( (0.0 != *(float *)(v3 + 176) || 0.0 != *(float *)(v3 + 180)) && filtersCntInBuf )
  {
    filtersBuf->Type = 2;
    v4 = 1;
    filtersBuf->Blur.BlurX = *(float *)(v3 + 176) * 0.05000000074505806;
    filtersBuf->Blur.BlurY = *(float *)(v3 + 180) * 0.05000000074505806;
    filtersBuf->Blur.Strength = *(float *)(v3 + 184) * 100.0;
  }
  if ( 0.0 == *(float *)(v3 + 196) && 0.0 == *(float *)(v3 + 200) || v4 >= filtersCntInBuf )
    return v4;
  if ( 0.0 == *(float *)(v3 + 228) )
  {
    v5 = 100.0;
    if ( 0.0 == *(float *)(v3 + 232) )
    {
      v6 = &filtersBuf[v4];
      v6->Type = 3;
      v6->Glow.Flags = *(_BYTE *)(v3 + 224);
      v6->Blur.BlurX = *(float *)(v3 + 196) * 0.05000000074505806;
      v6->Blur.BlurY = 0.05000000074505806 * *(float *)(v3 + 200);
      v6->Blur.Strength = 100.0 * *(float *)(v3 + 212);
      v6->Glow.Color = *(_DWORD *)(v3 + 216) & 0xFFFFFF | (*(unsigned __int8 *)(v3 + 236) << 24);
      return v4 + 1;
    }
  }
  else
  {
    v5 = 100.0;
  }
  v8 = &filtersBuf[v4];
  v8->Type = 1;
  v8->Glow.Flags = *(_BYTE *)(v3 + 224);
  v8->Blur.BlurX = *(float *)(v3 + 196) * 0.05000000074505806;
  v8->Blur.BlurY = *(float *)(v3 + 200) * 0.05000000074505806;
  v8->Blur.Strength = v5 * *(float *)(v3 + 212);
  v8->Glow.Color = *(_DWORD *)(v3 + 216) & 0xFFFFFF | (*(unsigned __int8 *)(v3 + 236) << 24);
  v8->DropShadow.Angle = *(float *)(v3 + 228) * 180.0 / 3.141592653589793;
  v8->DropShadow.Distance = 0.05000000074505806 * *(float *)(v3 + 232);
  return v4 + 1;
}
