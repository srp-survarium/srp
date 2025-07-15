void __thiscall Scaleform::Render::D3D1x::TextureManager::processTextureKillList(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  unsigned int i; // esi
  unsigned int j; // esi

  for ( i = 0; i < this->D3DTexViewKillList.Data.Size; ++i )
    this->D3DTexViewKillList.Data.Data[i]->Release(this->D3DTexViewKillList.Data.Data[i]);
  for ( j = 0; j < this->D3DTextureKillList.Data.Size; ++j )
    this->D3DTextureKillList.Data.Data[j]->Release(this->D3DTextureKillList.Data.Data[j]);
  Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0> > *)&this->D3DTexViewKillList,
    0,
    &this->D3DTexViewKillList);
  Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,75>,Scaleform::ArrayConstPolicy<8,8,0>>::ResizeNoConstruct(
    &this->D3DTextureKillList.Data,
    0,
    &this->D3DTextureKillList);
}
