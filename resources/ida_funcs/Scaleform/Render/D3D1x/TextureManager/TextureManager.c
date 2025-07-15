void __userpurge Scaleform::Render::D3D1x::TextureManager::TextureManager(
        Scaleform::Render::D3D1x::TextureManager *this@<edi>,
        void *renderThreadId@<ecx>,
        Scaleform::Render::ThreadCommandQueue *commandQueue@<eax>,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pcontext,
        Scaleform::Render::TextureCache *texCache)
{
  Scaleform::Render::MappedTextureBase *v6; // ecx
  Scaleform::Render::D3D1x::TextureManager *v7; // ecx
  unsigned int i; // ebx
  ID3D11Device *v9; // eax
  D3D11_SAMPLER_DESC samplerDesc; // [esp+Ch] [ebp-34h] BYREF
  unsigned int wrap; // [esp+44h] [ebp+4h]

  Scaleform::Render::TextureManager::TextureManager(this, renderThreadId, commandQueue, 0);
  this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::D3D1x::TextureManager_vtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>'};
  this->Scaleform::Render::TextureManager::Scaleform::Render::ImageUpdateSync::__vftable = (Scaleform::Render::ImageUpdateSync_vtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable'{for `Scaleform::Render::ImageUpdateSync'};
  this->pDevice = pdevice;
  this->pDeviceContext = pcontext;
  Scaleform::Render::MappedTextureBase::MappedTextureBase(v6, (int)&this->MappedTexture0);
  this->MappedTexture0.__vftable = (Scaleform::Render::D3D1x::MappedTexture_vtbl *)&Scaleform::Render::D3D1x::MappedTexture::`vftable';
  this->D3DTextureKillList.Data.Data = 0;
  this->D3DTextureKillList.Data.Size = 0;
  this->D3DTextureKillList.Data.Policy.Capacity = 0;
  this->D3DTexViewKillList.Data.Data = 0;
  this->D3DTexViewKillList.Data.Size = 0;
  this->D3DTexViewKillList.Data.Policy.Capacity = 0;
  Scaleform::Render::D3D1x::TextureManager::initTextureFormats(v7, (unsigned int)this);
  *(_QWORD *)this->SamplerStates = 0;
  *(_QWORD *)&this->SamplerStates[2] = 0;
  for ( wrap = 0; wrap < 2; ++wrap )
  {
    for ( i = 0; i < 2; ++i )
    {
      memset((int)&samplerDesc, 0, sizeof(samplerDesc));
      samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
      if ( 2 * i == 2 )
        samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
      if ( wrap )
      {
        samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
        samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
      }
      else
      {
        samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
        samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
      }
      samplerDesc.MaxAnisotropy = 1;
      samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
      v9 = this->pDevice;
      samplerDesc.MaxLOD = 3.4028235e38;
      samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
      samplerDesc.MipLODBias = -0.75;
      v9->CreateSamplerState(v9, &samplerDesc, &this->SamplerStates[(unsigned __int8)wrap | (unsigned __int8)(2 * i)]);
    }
  }
}
