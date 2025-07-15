void __thiscall Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::Render::Text::HighlightDesc *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Text::HighlightDesc *Data; // eax
  Scaleform::Render::Text::HighlightDesc *v5; // eax

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::HighlightDesc,Scaleform::AllocatorGH<Scaleform::Render::Text::HighlightDesc,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
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


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // ecx

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    this->Size + 1);
  Size = this->Size;
  if ( &this->Data[Size] != (Scaleform::GFx::AS3::Value *)16 )
  {
    this->Data[Size - 1] = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        ++val->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // ecx

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    this->Size + 1);
  Size = this->Size;
  if ( &this->Data[Size] != (Scaleform::GFx::AS3::Value *)16 )
  {
    this->Data[Size - 1] = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // ecx

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    this->Size + 1);
  Size = this->Size;
  if ( &this->Data[Size] != (Scaleform::GFx::AS3::Value *)16 )
  {
    this->Data[Size - 1] = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        ++val->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        Scaleform::Render::Matrix3x4<float> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Matrix3x4<float> *Data; // eax
  unsigned __int8 *v5; // eax

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  v5 = (unsigned __int8 *)&Data[v3 - 1];
  if ( v5 )
    memcpy(v5, (unsigned __int8 *)val, 0x30u);
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        Scaleform::Render::Matrix4x4<float> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Matrix4x4<float> *Data; // edx
  unsigned int v5; // esi

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  v5 = v3 << 6;
  if ( (Scaleform::Render::Matrix4x4<float> *)((char *)Data + v5) != (Scaleform::Render::Matrix4x4<float> *)64 )
    memcpy((unsigned __int8 *)&Data[-1] + v5, (unsigned __int8 *)val, sizeof(Scaleform::Render::Matrix4x4<float>));
}


void __thiscall Scaleform::ArrayData<Scaleform::Render::Point<float>,Scaleform::AllocatorLH<Scaleform::Render::Point<float>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Point<float>,Scaleform::AllocatorLH<Scaleform::Render::Point<float>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::Render::Point<float> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Point<float> *Data; // edx
  float *p_x; // eax
  float vala; // [esp+Ch] [ebp+4h]

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  p_x = &Data[v3 - 1].x;
  if ( &Data[v3] != (Scaleform::Render::Point<float> *)8 )
  {
    vala = val->y;
    *p_x = val->x;
    p_x[1] = vala;
  }
}
