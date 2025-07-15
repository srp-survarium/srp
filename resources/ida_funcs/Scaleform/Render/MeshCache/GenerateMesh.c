Scaleform::Render::MeshCache::MeshResult *__thiscall Scaleform::Render::MeshCache::GenerateMesh(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCache::MeshResult *result,
        Scaleform::Render::Mesh *mesh,
        const Scaleform::Render::VertexFormat *sourceFormat,
        const Scaleform::Render::VertexFormat *singleFormat,
        const Scaleform::Render::VertexFormat *batchFormat,
        bool waitForCache)
{
  unsigned int MGFlags; // esi
  Scaleform::Render::MeshProvider *pObject; // ecx
  Scaleform::Render::MeshCache::MeshResult *v9; // eax
  Scaleform::Render::MeshVertexOutput out; // [esp+4h] [ebp-2Ch] BYREF

  out.pCache = this;
  out.pSourceFormat = sourceFormat;
  out.WaitForCache = waitForCache;
  MGFlags = mesh->MGFlags;
  out.pBatchFormat = batchFormat;
  out.pVertexDataStart = 0;
  out.pIndexDataStart = 0;
  pObject = mesh->pProvider.pObject;
  out.pMesh = mesh;
  out.__vftable = (Scaleform::Render::MeshVertexOutput_vtbl *)&Scaleform::Render::MeshVertexOutput::`vftable';
  out.pSingleFormat = singleFormat;
  out.Result.Value = Fail_General;
  pObject->GetData(pObject, mesh, &out, MGFlags);
  v9 = result;
  result->Value = (Scaleform::Render::MeshCache::MeshResult::ResultType)out.Result;
  return v9;
}
