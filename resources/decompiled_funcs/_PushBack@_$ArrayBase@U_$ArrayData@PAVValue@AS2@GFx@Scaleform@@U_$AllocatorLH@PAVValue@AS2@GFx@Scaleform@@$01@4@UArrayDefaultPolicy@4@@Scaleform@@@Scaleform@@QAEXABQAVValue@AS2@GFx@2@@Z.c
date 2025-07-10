void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::GFx::AS2::Value *const *val)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS2::Value **Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (Scaleform::GFx::AS2::Value **)4 )
    Data[v3 - 1] = *val;
}
