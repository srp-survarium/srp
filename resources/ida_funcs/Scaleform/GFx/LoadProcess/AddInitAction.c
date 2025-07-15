void __thiscall Scaleform::GFx::LoadProcess::AddInitAction(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceId spriteId,
        Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // edi
  unsigned int v4; // esi
  Scaleform::GFx::ExecuteTag **Data; // edx

  p_InitActionTags = &this->InitActionTags;
  v4 = this->InitActionTags.Data.Size + 1;
  if ( v4 >= this->InitActionTags.Data.Size )
  {
    if ( v4 >= this->InitActionTags.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        &p_InitActionTags->Data,
        p_InitActionTags,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->InitActionTags.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      &p_InitActionTags->Data,
      p_InitActionTags,
      this->InitActionTags.Data.Size + 1);
  }
  Data = p_InitActionTags->Data.Data;
  p_InitActionTags->Data.Size = v4;
  if ( &Data[v4] != (Scaleform::GFx::ExecuteTag **)4 )
    Data[v4 - 1] = ptag;
}
