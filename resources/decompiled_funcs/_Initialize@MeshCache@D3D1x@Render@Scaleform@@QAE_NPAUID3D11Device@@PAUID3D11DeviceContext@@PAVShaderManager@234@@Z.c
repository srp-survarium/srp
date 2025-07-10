char __userpurge Scaleform::Render::D3D1x::MeshCache::Initialize@<al>(
        ID3D11Device *pdevice@<ecx>,
        ID3D11DeviceContext *pcontext@<eax>,
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::D3D1x::ShaderManager *psm)
{
  ID3D11Device *pObject; // eax
  ID3D11DeviceContext *v7; // eax
  Scaleform::Render::D3D1x::MeshCache *v8; // ecx
  unsigned int MemReserve; // ebp
  Scaleform::Render::MeshBuffer::AllocType v11; // [esp+0h] [ebp-10h]
  unsigned int v12; // [esp+4h] [ebp-Ch]

  if ( pdevice )
    pdevice->AddRef(pdevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    pObject->Release(this->pDevice.pObject);
  this->pDevice.pObject = pdevice;
  if ( pcontext )
    pcontext->AddRef(pcontext);
  v7 = this->pDeviceContext.pObject;
  if ( v7 )
    v7->Release(this->pDeviceContext.pObject);
  this->pDeviceContext.pObject = pcontext;
  this->pShaderManager = psm;
  Scaleform::Render::D3D1x::MeshCache::adjustMeshCacheParams(&this->Params, this);
  Scaleform::Render::D3D1x::RenderSync::SetDevice(&this->RSync, pdevice, (ID3D11Query *)pcontext);
  if ( !Scaleform::Render::MeshStagingBuffer::Initialize(
          &this->StagingBuffer,
          this->pHeap,
          this->Params.StagingBufferSize) )
    return 0;
  if ( !Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(pdevice, this)
    || (MemReserve = this->Params.MemReserve) != 0
    && !Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(v8, (int)this, MemReserve, v11, v12) )
  {
    Scaleform::Render::D3D1x::MeshCache::Reset(v8, (int)this);
    return 0;
  }
  return 1;
}
