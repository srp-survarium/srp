Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::Highlighter::CreateNewHighlighter(
        Scaleform::Render::Text::Highlighter *this,
        Scaleform::Render::Text::HighlightDesc *pdesc)
{
  int Size; // edx
  unsigned int LastId; // ebx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // esi

  Size = this->Highlighters.Data.Size;
  this->Valid = 0;
  this->HasUnderline = 0;
  do
  {
    LastId = ++this->LastId;
    v5 = 0;
    while ( Size > 0 )
    {
      v6 = (Size >> 1) + v5;
      LastId = this->LastId;
      if ( (int)(this->Highlighters.Data.Data[v6].Id - LastId) >= 0 )
      {
        Size >>= 1;
      }
      else
      {
        v5 = v6 + 1;
        Size += -1 - (Size >> 1);
      }
    }
    Size = this->Highlighters.Data.Size;
  }
  while ( v5 < Size && this->Highlighters.Data.Data[v5].Id == LastId && &this->Highlighters.Data.Data[v5] );
  pdesc->Id = LastId;
  v7 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::HighlightDesc,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::Render::Text::HighlightDesc const &,unsigned int)>(
         &this->Highlighters,
         0,
         this->Highlighters.Data.Size,
         &pdesc->Id,
         Scaleform::Render::Text::IdComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Highlighters,
    v7,
    pdesc);
  return &this->Highlighters.Data.Data[v7];
}
