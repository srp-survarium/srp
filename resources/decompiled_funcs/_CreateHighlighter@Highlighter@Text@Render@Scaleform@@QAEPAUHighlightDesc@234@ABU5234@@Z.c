Scaleform::Render::Text::HighlightDesc *__thiscall Scaleform::Render::Text::Highlighter::CreateHighlighter(
        Scaleform::Render::Text::Highlighter *this,
        const Scaleform::Render::Text::HighlightDesc *desc)
{
  const Scaleform::Render::Text::HighlightDesc *v2; // ebp
  const Scaleform::Render::Text::HighlightDesc *Id; // ebx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edx
  Scaleform::Render::Text::HighlightDesc *v8; // eax
  unsigned int v9; // edi
  unsigned int Size; // [esp-Ch] [ebp-1Ch]

  v2 = desc;
  Size = this->Highlighters.Data.Size;
  this->Valid = 0;
  this->HasUnderline = 0;
  Id = (const Scaleform::Render::Text::HighlightDesc *)v2->Id;
  desc = Id;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::HighlightDesc,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::Render::Text::HighlightDesc const &,unsigned int)>(
         &this->Highlighters,
         0,
         Size,
         (unsigned int *)&desc,
         Scaleform::Render::Text::IdComparator::Less);
  v6 = this->Highlighters.Data.Size;
  if ( v5 < v6 )
  {
    v7 = v5;
    v8 = &this->Highlighters.Data.Data[v5];
    if ( (const Scaleform::Render::Text::HighlightDesc *)this->Highlighters.Data.Data[v7].Id == Id )
    {
      if ( v8 )
        return 0;
    }
  }
  v9 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::HighlightDesc,2,Scaleform::ArrayDefaultPolicy>,unsigned int,int (__cdecl *)(Scaleform::Render::Text::HighlightDesc const &,unsigned int)>(
         &this->Highlighters,
         0,
         v6,
         &v2->Id,
         Scaleform::Render::Text::IdComparator::Less);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorLH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Highlighters,
    v9,
    v2);
  return &this->Highlighters.Data.Data[v9];
}
