void __userpurge survarium::flash_renderer::on_reset_device(
        survarium::flash_renderer *this@<ecx>,
        unsigned int width@<eax>,
        unsigned int height,
        ID3D11Device *pd3d_device,
        ID3D11DeviceContext *pd3d_device_context)
{
  Scaleform::Render::D3D1x::HAL *m_HALRenderer; // ecx
  Scaleform::Render::D3D1x::HAL *v7; // ecx
  Scaleform::Render::D3D1x::HAL *v8; // ecx
  Scaleform::RefCountVImpl *v9[3]; // [esp+8h] [ebp-24h] BYREF
  Scaleform::RefCountVImpl *v10; // [esp+14h] [ebp-18h]
  Scaleform::RefCountVImpl *v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+1Ch] [ebp-10h]
  ID3D11Device *v13; // [esp+20h] [ebp-Ch]
  ID3D11DeviceContext *v14; // [esp+24h] [ebp-8h]

  m_HALRenderer = this->m_HALRenderer;
  this->m_output_width = width;
  this->m_output_height = height;
  if ( m_HALRenderer->IsInitialized(m_HALRenderer) )
  {
    Scaleform::Render::D3D1x::HAL::RestoreAfterReset(v7, this->m_HALRenderer);
  }
  else
  {
    v8 = this->m_HALRenderer;
    v13 = pd3d_device;
    memset(v9, 0, sizeof(v9));
    v10 = 0;
    v11 = 0;
    v12 = 256;
    v14 = pd3d_device_context;
    v8->InitHAL(v8, (const Scaleform::Render::D3D1x::HALInitParams *)v9);
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
  }
}
