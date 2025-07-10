Scaleform::Render::Text::ImageDesc *__thiscall Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        const wchar_t *pstr,
        unsigned int maxlen,
        unsigned int *ptextLen)
{
  unsigned int v5; // eax
  unsigned int v6; // edi
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element *v7; // ebx
  unsigned int Size; // [esp-Ch] [ebp-20h]
  Scaleform::Render::Text::ImageSubstCmp::Comparable e; // [esp+Ch] [ebp-8h] BYREF

  e.Str = pstr;
  Size = this->Elements.Data.Size;
  e.MaxSize = maxlen;
  v5 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2,Scaleform::ArrayDefaultPolicy>,Scaleform::Render::Text::ImageSubstCmp::Comparable,int (__cdecl *)(Scaleform::Render::Text::DocView::ImageSubstitutor::Element const &,Scaleform::Render::Text::ImageSubstCmp::Comparable const &)>(
         &this->Elements,
         0,
         Size,
         &e,
         Scaleform::Render::Text::ImageSubstCmp::Less);
  if ( v5 >= this->Elements.Data.Size )
    return 0;
  v6 = v5;
  v7 = &this->Elements.Data.Data[v5];
  if ( Scaleform::Render::Text::ImageSubstCmp::StrCompare(e.Str, e.MaxSize, v7->SubString, v7->SubStringLen, 0) )
    return 0;
  if ( ptextLen )
    *ptextLen = v7->SubStringLen;
  return this->Elements.Data.Data[v6].pImageDesc.pObject;
}
