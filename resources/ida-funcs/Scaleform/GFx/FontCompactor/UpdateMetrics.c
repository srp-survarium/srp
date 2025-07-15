void __thiscall Scaleform::GFx::FontCompactor::UpdateMetrics(
        Scaleform::GFx::FontCompactor *this,
        __int16 ascent,
        __int16 descent,
        __int16 leading)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax

  v4 = this->FontMetricsPos + 4;
  this->Encoder.Data->Pages[v4 >> 12][(LOWORD(this->FontMetricsPos) + 4) & 0xFFF] = ascent;
  this->Encoder.Data->Pages[(v4 + 1) >> 12][(v4 + 1) & 0xFFF] = HIBYTE(ascent);
  v5 = this->FontMetricsPos + 6;
  this->Encoder.Data->Pages[v5 >> 12][(LOWORD(this->FontMetricsPos) + 6) & 0xFFF] = descent;
  this->Encoder.Data->Pages[(v5 + 1) >> 12][(v5 + 1) & 0xFFF] = HIBYTE(descent);
  v6 = this->FontMetricsPos + 8;
  this->Encoder.Data->Pages[v6 >> 12][(LOWORD(this->FontMetricsPos) + 8) & 0xFFF] = leading;
  this->Encoder.Data->Pages[(v6 + 1) >> 12][(v6 + 1) & 0xFFF] = HIBYTE(leading);
}
