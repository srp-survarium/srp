void __thiscall Scaleform::Render::D3D1x::TextureManager::processTextureKillList(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  unsigned int i; // edi
  unsigned int j; // edi
  Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *p_D3DTexViewKillList; // edi
  Scaleform::MemoryHeap_vtbl *v5; // edx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::ArrayLH<ID3D11Resource *,75,Scaleform::ArrayConstPolicy<8,8,0> > *p_D3DTextureKillList; // edi
  Scaleform::MemoryHeap_vtbl *v8; // edx
  int v9; // eax
  void *(__thiscall *v10)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v11; // [esp+8h] [ebp-8h] BYREF
  int v12; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < this->D3DTexViewKillList.Data.Size; ++i )
    this->D3DTexViewKillList.Data.Data[i]->Release(this->D3DTexViewKillList.Data.Data[i]);
  for ( j = 0; j < this->D3DTextureKillList.Data.Size; ++j )
    this->D3DTextureKillList.Data.Data[j]->Release(this->D3DTextureKillList.Data.Data[j]);
  p_D3DTexViewKillList = (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&this->D3DTexViewKillList;
  if ( this->D3DTexViewKillList.Data.Size )
  {
    if ( (this->D3DTexViewKillList.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      v5 = Scaleform::Memory::pGlobalHeap->__vftable;
      if ( p_D3DTexViewKillList->Data )
      {
        p_D3DTexViewKillList->Data = (ID3D11Resource **)((int (__stdcall *)(ID3D11Resource **, int))v5->Realloc)(
                                                          p_D3DTexViewKillList->Data,
                                                          32);
      }
      else
      {
        AllocAutoHeap = v5->AllocAutoHeap;
        v11 = 75;
        p_D3DTexViewKillList->Data = (ID3D11Resource **)((int (__stdcall *)(Scaleform::ArrayLH<ID3D11View *,75,Scaleform::ArrayConstPolicy<8,8,0> > *, int, int *))AllocAutoHeap)(
                                                          &this->D3DTexViewKillList,
                                                          32,
                                                          &v11);
      }
      this->D3DTexViewKillList.Data.Policy.Capacity = 8;
    }
  }
  else if ( !this->D3DTexViewKillList.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      p_D3DTexViewKillList,
      0,
      (int)this,
      &this->D3DTexViewKillList);
  }
  this->D3DTexViewKillList.Data.Size = 0;
  p_D3DTextureKillList = &this->D3DTextureKillList;
  if ( !this->D3DTextureKillList.Data.Size )
  {
    if ( !this->D3DTextureKillList.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
        &p_D3DTextureKillList->Data,
        0,
        0,
        &this->D3DTextureKillList);
      this->D3DTextureKillList.Data.Size = 0;
      return;
    }
    goto LABEL_21;
  }
  if ( (this->D3DTextureKillList.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_21:
    this->D3DTextureKillList.Data.Size = 0;
    return;
  }
  v8 = Scaleform::Memory::pGlobalHeap->__vftable;
  if ( p_D3DTextureKillList->Data.Data )
  {
    v9 = ((int (__stdcall *)(ID3D11Resource **, int))v8->Realloc)(p_D3DTextureKillList->Data.Data, 32);
  }
  else
  {
    v10 = v8->AllocAutoHeap;
    v12 = 75;
    v9 = ((int (__stdcall *)(Scaleform::ArrayLH<ID3D11Resource *,75,Scaleform::ArrayConstPolicy<8,8,0> > *, int, int *))v10)(
           &this->D3DTextureKillList,
           32,
           &v12);
  }
  p_D3DTextureKillList->Data.Data = (ID3D11Resource **)v9;
  this->D3DTextureKillList.Data.Policy.Capacity = 8;
  this->D3DTextureKillList.Data.Size = 0;
}
