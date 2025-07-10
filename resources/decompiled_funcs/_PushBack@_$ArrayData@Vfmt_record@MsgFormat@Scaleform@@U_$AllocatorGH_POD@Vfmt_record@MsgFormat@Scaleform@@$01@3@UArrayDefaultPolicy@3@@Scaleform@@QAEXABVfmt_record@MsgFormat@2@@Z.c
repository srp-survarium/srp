void __thiscall Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::MsgFormat::fmt_record *val)
{
  unsigned int v3; // esi
  Scaleform::MsgFormat::fmt_record *Data; // eax

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  Data[v3 - 1] = *val;
}
