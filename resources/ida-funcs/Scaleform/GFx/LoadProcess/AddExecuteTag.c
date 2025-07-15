void __thiscall Scaleform::GFx::LoadProcess::AddExecuteTag(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *v2; // edi
  unsigned int v3; // esi
  Scaleform::GFx::ExecuteTag **Data; // eax
  Scaleform::GFx::ExecuteTag **v5; // eax

  v2 = &this->FrameTags[this->LoadState];
  v3 = this->FrameTags[this->LoadState].Data.Size + 1;
  if ( v3 >= this->FrameTags[this->LoadState].Data.Size )
  {
    if ( v3 >= this->FrameTags[this->LoadState].Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        &v2->Data,
        v2,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->FrameTags[this->LoadState].Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      &v2->Data,
      v2,
      v3);
  }
  Data = v2->Data.Data;
  v2->Data.Size = v3;
  v5 = &Data[v3 - 1];
  if ( v5 )
    *v5 = ptag;
}
