void __thiscall Scaleform::Render::StrokeSorter::Transform(
        Scaleform::Render::StrokeSorter *this,
        Scaleform::Render::TransformerBase *tr)
{
  unsigned int i; // esi

  for ( i = 0; i < this->OutVertices.Size; ++i )
    tr->Transform(tr, (float *)&this->OutVertices.Pages[i >> 4][i & 0xF], &this->OutVertices.Pages[i >> 4][i & 0xF].y);
}
