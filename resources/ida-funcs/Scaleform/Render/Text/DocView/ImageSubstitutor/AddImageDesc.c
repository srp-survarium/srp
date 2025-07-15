void __thiscall Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(
        Scaleform::Render::Text::DocView::ImageSubstitutor *this,
        const Scaleform::Render::Text::DocView::ImageSubstitutor::Element *elem)
{
  unsigned int SubStringLen; // ecx
  unsigned int v4; // eax
  unsigned int Size; // [esp-Ch] [ebp-1Ch]
  Scaleform::Render::Text::ImageSubstCmp::Comparable val; // [esp+8h] [ebp-8h] BYREF

  if ( !Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(this, elem->SubString, elem->SubStringLen, 0) )
  {
    SubStringLen = elem->SubStringLen;
    Size = this->Elements.Data.Size;
    val.Str = (const wchar_t *)elem;
    val.MaxSize = SubStringLen;
    v4 = Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2,Scaleform::ArrayDefaultPolicy>,Scaleform::Render::Text::ImageSubstCmp::Comparable,int (__cdecl *)(Scaleform::Render::Text::DocView::ImageSubstitutor::Element const &,Scaleform::Render::Text::ImageSubstCmp::Comparable const &)>(
           &this->Elements,
           0,
           Size,
           &val,
           Scaleform::Render::Text::ImageSubstCmp::InsLess);
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,Scaleform::AllocatorLH<Scaleform::Render::Text::DocView::ImageSubstitutor::Element,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->Elements,
      v4,
      elem);
  }
}
