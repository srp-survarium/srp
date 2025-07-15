void __usercall Scaleform::Render::D3D1x::HAL::~HAL(Scaleform::Render::D3D1x::HAL *this@<ecx>, int a2@<edi>)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::D3D1x::ShaderManager *v4; // ecx
  ID3D11DepthStencilView *v5; // eax
  ID3D11RenderTargetView *v6; // eax

  this->__vftable = (Scaleform::Render::D3D1x::HAL_vtbl *)&Scaleform::Render::D3D1x::HAL::`vftable';
  Scaleform::Render::D3D1x::HAL::ShutdownHAL(this, a2, (int)this);
  pObject = (Scaleform::RefCountVImpl *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::D3D1x::MeshCache::~MeshCache((Scaleform::Render::D3D1x::MeshCache *)pObject, (int)&this->Cache);
  v5 = this->pDepthStencilView.pObject;
  if ( v5 )
    v5->Release(this->pDepthStencilView.pObject);
  v6 = this->pRenderTargetView.pObject;
  if ( v6 )
    v6->Release(this->pRenderTargetView.pObject);
  Scaleform::Render::D3D1x::ShaderManager::~ShaderManager(v4, (int)&this->SManager);
  Scaleform::Render::HAL::~HAL(this);
}
