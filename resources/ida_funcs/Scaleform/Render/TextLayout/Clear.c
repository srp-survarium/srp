void __thiscall Scaleform::Render::TextLayout::Clear(Scaleform::Render::TextLayout *this)
{
  unsigned int i; // edi
  unsigned int j; // edi
  Scaleform::Render::Image *v4; // ecx
  unsigned int k; // edi
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // esi

  for ( i = 0; i < this->FontCount; ++i )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pFonts[i]);
  for ( j = 0; j < this->ImageCount; ++j )
  {
    v4 = this->pImages[j];
    v4->Release(v4);
  }
  for ( k = 0; k < this->RefCntCount; ++k )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pRefCntData[k]);
  p_Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data;
  if ( p_Data->Size )
  {
    if ( (p_Data->Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Data,
        p_Data,
        0);
      p_Data->Size = 0;
      return;
    }
  }
  else if ( !p_Data->Policy.Capacity )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Data,
      p_Data,
      0);
  }
  p_Data->Size = 0;
}
