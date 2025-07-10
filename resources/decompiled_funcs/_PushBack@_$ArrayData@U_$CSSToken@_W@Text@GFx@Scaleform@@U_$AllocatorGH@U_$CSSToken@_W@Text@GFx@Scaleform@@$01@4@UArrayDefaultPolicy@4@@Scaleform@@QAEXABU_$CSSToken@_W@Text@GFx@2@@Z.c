void __thiscall Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::GFx::Text::CSSToken<wchar_t> *val)
{
  unsigned int v3; // esi
  Scaleform::GFx::Text::CSSToken<wchar_t> *Data; // eax
  Scaleform::GFx::Text::CSSToken<wchar_t> *v5; // eax

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Text::CSSToken<wchar_t>,Scaleform::AllocatorGH<Scaleform::GFx::Text::CSSToken<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  v5 = &Data[v3 - 1];
  if ( v5 )
    *v5 = *val;
}
