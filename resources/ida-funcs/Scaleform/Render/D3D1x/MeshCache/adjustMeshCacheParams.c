void __userpurge Scaleform::Render::D3D1x::MeshCache::adjustMeshCacheParams(
        Scaleform::Render::MeshCacheParams *p@<eax>,
        Scaleform::Render::D3D1x::MeshCache *this)
{
  unsigned int MaxBatchInstances; // ecx
  unsigned int MaxVerticesSizeInBatch; // edx
  unsigned int v4; // ecx

  MaxBatchInstances = p->MaxBatchInstances;
  if ( MaxBatchInstances >= 0x18 )
    MaxBatchInstances = 24;
  if ( !MaxBatchInstances )
    MaxBatchInstances = 1;
  MaxVerticesSizeInBatch = p->MaxVerticesSizeInBatch;
  p->MaxBatchInstances = MaxBatchInstances;
  v4 = 2 * (MaxVerticesSizeInBatch + 2 * p->MaxIndicesInBatch);
  p->VBLockEvictSizeLimit = (unsigned int)&loc_3FFFF + 1;
  if ( v4 > p->StagingBufferSize )
    p->StagingBufferSize = v4;
  if ( this->pShaderManager->ShaderModel != ShaderVersion_D3D1xFL1x )
    p->InstancingThreshold = 0;
}
