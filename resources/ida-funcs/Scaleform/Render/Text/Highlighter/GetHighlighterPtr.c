Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::Highlighter::GetHighlighterPtr(
        Scaleform::Render::Text::Highlighter *this,
        unsigned int id)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  Scaleform::Render::Text::HighlightDesc *result; // eax

  v3 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::HighlightDesc,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::Render::Text::HighlightDesc const &,unsigned int)>(
         &this->Highlighters,
         0,
         this->Highlighters.Data.Size,
         &id,
         Scaleform::Render::Text::IdComparator::Less);
  if ( v3 >= this->Highlighters.Data.Size )
    return 0;
  v4 = this->Highlighters.Data.Data[v3].Id;
  result = &this->Highlighters.Data.Data[v3];
  if ( v4 != id )
    return 0;
  return result;
}
