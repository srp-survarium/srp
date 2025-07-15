void __thiscall Scaleform::Render::GlyphShape::Clear(Scaleform::Render::GlyphShape *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Data; // esi

  p_Data = &this->Data;
  if ( this->Data.Data.Size )
  {
    if ( (this->Data.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
        &this->Data,
        0);
      p_Data->Data.Size = 0;
      return;
    }
  }
  else if ( !this->Data.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      &this->Data,
      0);
  }
  p_Data->Data.Size = 0;
}
