char __userpurge Scaleform::Render::D3D1x::MeshCache::Initialize@<al>(
        Scaleform::Render::D3D1x::MeshCache *this@<edi>,
        ID3D11DeviceContext *pcontext@<eax>,
        ID3D11Device *pdevice,
        Scaleform::Render::D3D1x::ShaderManager *psm)
{
  ID3D11Device *pObject; // eax
  ID3D11DeviceContext *v6; // eax
  Scaleform::Render::MeshCacheParams *p_Params; // ebx
  Scaleform::Render::D3D1x::RenderSync *v8; // ecx
  Scaleform::Render::D3D1x::MeshCache *v10; // ecx
  Scaleform::Render::MeshBuffer::AllocType v11; // [esp+4h] [ebp-8h]
  unsigned int v12; // [esp+8h] [ebp-4h]

  if ( pdevice )
    pdevice->AddRef(pdevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    pObject->Release(this->pDevice.pObject);
  this->pDevice.pObject = pdevice;
  if ( pcontext )
    pcontext->AddRef(pcontext);
  v6 = this->pDeviceContext.pObject;
  if ( v6 )
    v6->Release(this->pDeviceContext.pObject);
  this->pDeviceContext.pObject = pcontext;
  this->pShaderManager = psm;
  p_Params = &this->Params;
  Scaleform::Render::D3D1x::MeshCache::adjustMeshCacheParams(&this->Params, this);
  Scaleform::Render::D3D1x::RenderSync::SetDevice(v8, &this->RSync, pdevice, (Scaleform::Render::FenceFrame *)pcontext);
  if ( !Scaleform::Render::MeshStagingBuffer::Initialize(
          &this->StagingBuffer,
          this->pHeap,
          this->Params.StagingBufferSize) )
    return 0;
  if ( !Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(pdevice, this)
    || p_Params->MemReserve
    && !Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(p_Params->MemReserve, this, v11, v12) )
  {
    Scaleform::Render::D3D1x::MeshCache::Reset(v10, (int)this);
    return 0;
  }
  return 1;
}
