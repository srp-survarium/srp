void __userpurge survarium::flash_renderer::on_reset_device(
        unsigned int width@<eax>,
        unsigned int height@<ecx>,
        survarium::flash_renderer *this,
        ID3D11Device *pd3d_device,
        ID3D11DeviceContext *pd3d_device_context)
{
  Scaleform::Render::D3D1x::HAL *m_HALRenderer; // ecx
  Scaleform::Render::D3D1x::HAL *v6; // ecx
  Scaleform::Render::D3D1x::HAL *v7; // ecx
  Scaleform::RefCountVImpl *v8[3]; // [esp+8h] [ebp-20h] BYREF
  Scaleform::RefCountVImpl *v9; // [esp+14h] [ebp-14h]
  Scaleform::RefCountVImpl *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+1Ch] [ebp-Ch]
  ID3D11Device *v12; // [esp+20h] [ebp-8h]
  ID3D11DeviceContext *v13; // [esp+24h] [ebp-4h]

  this->m_output_height = height;
  m_HALRenderer = this->m_HALRenderer;
  this->m_output_width = width;
  if ( m_HALRenderer->IsInitialized(m_HALRenderer) )
  {
    Scaleform::Render::D3D1x::HAL::RestoreAfterReset(v6, this->m_HALRenderer);
  }
  else
  {
    v12 = pd3d_device;
    v7 = this->m_HALRenderer;
    v13 = pd3d_device_context;
    memset(v8, 0, sizeof(v8));
    v9 = 0;
    v10 = 0;
    v11 = 256;
    v7->InitHAL(v7, (const Scaleform::Render::D3D1x::HALInitParams *)v8);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
  }
}
