void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::Render::Point<long> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Point<long> *Data; // edx
  Scaleform::Render::Point<long> *v5; // eax
  int y; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  v5 = &Data[v3 - 1];
  if ( &Data[v3] != (Scaleform::Render::Point<long> *)8 )
  {
    y = val->y;
    v5->x = val->x;
    v5->y = y;
  }
}
