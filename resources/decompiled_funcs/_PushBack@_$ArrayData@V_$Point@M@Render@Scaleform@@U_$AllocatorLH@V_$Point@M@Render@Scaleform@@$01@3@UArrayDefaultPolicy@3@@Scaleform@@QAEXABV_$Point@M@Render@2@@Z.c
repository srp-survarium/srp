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
