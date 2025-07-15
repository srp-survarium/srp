void __thiscall Scaleform::GFx::LoadProcess::CleanupFrameTags(Scaleform::GFx::LoadProcess *this)
{
  unsigned int i; // edi
  Scaleform::GFx::ExecuteTag *v3; // ecx
  unsigned int j; // edi
  Scaleform::GFx::ExecuteTag *v5; // ecx
  unsigned int k; // edi
  Scaleform::GFx::ExecuteTag *v7; // ecx
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *v8; // edi
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *FrameTags; // edi
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // esi
  Scaleform::GFx::ExecuteTag **v11; // eax
  int v12; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < this->FrameTags[1].Data.Size; ++i )
  {
    v3 = this->FrameTags[1].Data.Data[i];
    ((void (__thiscall *)(Scaleform::GFx::ExecuteTag *, _DWORD))v3->~Scaleform::GFx::ExecuteTag)(v3, 0);
  }
  for ( j = 0; j < this->FrameTags[0].Data.Size; ++j )
  {
    v5 = this->FrameTags[0].Data.Data[j];
    ((void (__thiscall *)(Scaleform::GFx::ExecuteTag *, _DWORD))v5->~Scaleform::GFx::ExecuteTag)(v5, 0);
  }
  for ( k = 0; k < this->InitActionTags.Data.Size; ++k )
  {
    v7 = this->InitActionTags.Data.Data[k];
    ((void (__thiscall *)(Scaleform::GFx::ExecuteTag *, _DWORD))v7->~Scaleform::GFx::ExecuteTag)(v7, 0);
  }
  v8 = &this->FrameTags[1];
  if ( this->FrameTags[1].Data.Size )
  {
    if ( (this->FrameTags[1].Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( v8->Data.Data )
      {
        v8->Data.Data = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         v8->Data.Data,
                                                         128);
      }
      else
      {
        v12 = 2;
        v8->Data.Data = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         128,
                                                         &v12);
      }
      this->FrameTags[1].Data.Policy.Capacity = 32;
    }
  }
  else if ( !this->FrameTags[1].Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      &this->FrameTags[1].Data,
      &this->FrameTags[1],
      0);
  }
  this->FrameTags[1].Data.Size = 0;
  FrameTags = this->FrameTags;
  if ( this->FrameTags[0].Data.Size )
  {
    if ( (this->FrameTags[0].Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( FrameTags->Data.Data )
      {
        FrameTags->Data.Data = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                FrameTags->Data.Data,
                                                                128);
      }
      else
      {
        v12 = 2;
        FrameTags->Data.Data = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                128,
                                                                &v12);
      }
      this->FrameTags[0].Data.Policy.Capacity = 32;
    }
  }
  else if ( !this->FrameTags[0].Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      &this->FrameTags[0].Data,
      this->FrameTags,
      0);
  }
  p_InitActionTags = &this->InitActionTags;
  FrameTags->Data.Size = 0;
  if ( !p_InitActionTags->Data.Size )
  {
    if ( !p_InitActionTags->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        &p_InitActionTags->Data,
        p_InitActionTags,
        0);
    goto LABEL_31;
  }
  if ( (p_InitActionTags->Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_31:
    p_InitActionTags->Data.Size = 0;
    return;
  }
  if ( p_InitActionTags->Data.Data )
  {
    v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           p_InitActionTags->Data.Data,
                                           128);
  }
  else
  {
    v12 = 2;
    v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           128,
                                           &v12);
  }
  p_InitActionTags->Data.Size = 0;
  p_InitActionTags->Data.Data = v11;
  p_InitActionTags->Data.Policy.Capacity = 32;
}
