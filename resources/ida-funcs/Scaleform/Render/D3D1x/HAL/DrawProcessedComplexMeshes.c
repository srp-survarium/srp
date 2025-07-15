void __thiscall Scaleform::Render::D3D1x::HAL::DrawProcessedComplexMeshes(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::ComplexMesh *complexMesh,
        const Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *matrices)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer_vtbl *v5; // edx
  Scaleform::AmpStats *v6; // eax
  Scaleform::String::DataDesc *v7; // ecx
  Scaleform::Render::D3D1x::HAL_vtbl *v8; // eax
  Scaleform::Render::RenderEvent *v9; // eax
  Scaleform::Render::D3D1x::ProfileViewScopedOMChange *v10; // ecx
  unsigned int v11; // esi
  unsigned int MaxBatchInstances; // eax
  int v13; // esi
  Scaleform::Render::ComplexMesh::FillRecord *v14; // edi
  Scaleform::Render::Color *ColorForBatch; // eax
  bool v16; // zf
  const Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *v17; // edx
  unsigned int Format; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v19; // ecx
  Scaleform::Render::Cxform *Cxform; // eax
  Scaleform::Render::ProfileViews *v21; // ecx
  Scaleform::Render::Cxform *v22; // eax
  Scaleform::Render::PrimitiveFillType Type; // eax
  int *v24; // eax
  int v25; // ecx
  Scaleform::Render::MeshBase **pMeshes; // ecx
  ID3D11DeviceContext *pDeviceContext; // eax
  unsigned __int8 TextureCount; // al
  unsigned int v29; // ecx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v30; // esi
  Scaleform::Render::MatrixState *pObject; // ecx
  Scaleform::Render::Color v32; // ecx
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v33; // ecx
  Scaleform::Render::Cxform *v34; // eax
  Scaleform::Render::ProfileViews *v35; // ecx
  Scaleform::Render::Cxform *v36; // eax
  unsigned int v37; // esi
  Scaleform::Render::PrimitiveFill *v38; // edi
  Scaleform::Render::Texture *v39; // eax
  unsigned int PlaneCount; // eax
  unsigned int v41; // esi
  Scaleform::Render::D3D1x::HAL *v42; // ecx
  unsigned int v43; // esi
  unsigned __int32 v44; // edx
  unsigned int v45; // eax
  Scaleform::Render::D3D1x::ShaderPair v46; // [esp+6h] [ebp-CCh] BYREF
  Scaleform::Render::Color v47; // [esp+1Ah] [ebp-B8h] BYREF
  Scaleform::String v48; // [esp+1Eh] [ebp-B4h] BYREF
  Scaleform::AmpNativeFunctionId v49; // [esp+22h] [ebp-B0h]
  unsigned int v50; // [esp+26h] [ebp-ACh]
  int v51; // [esp+32h] [ebp-A0h]
  Scaleform::Render::PrimitiveFillType fillType; // [esp+36h] [ebp-9Ch]
  char v53; // [esp+3Dh] [ebp-95h]
  const Scaleform::Render::D3D1x::ShaderPair *sd; // [esp+3Eh] [ebp-94h]
  unsigned int meshCount; // [esp+42h] [ebp-90h]
  unsigned int fillFlags; // [esp+46h] [ebp-8Ch] BYREF
  unsigned int vertexBaseIndex; // [esp+4Ah] [ebp-88h]
  Scaleform::Render::ComplexMesh::FillRecord *v58; // [esp+4Eh] [ebp-84h]
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // [esp+52h] [ebp-80h]
  unsigned int v60; // [esp+56h] [ebp-7Ch]
  unsigned int index; // [esp+5Ah] [ebp-78h]
  unsigned int v62; // [esp+5Eh] [ebp-74h]
  Scaleform::Render::ComplexMesh::FillRecord *Data; // [esp+62h] [ebp-70h]
  unsigned int v64; // [esp+66h] [ebp-6Ch]
  int v65; // [esp+6Ah] [ebp-68h]
  int v66; // [esp+6Eh] [ebp-64h] BYREF
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v67; // [esp+72h] [ebp-60h]
  unsigned int *FillMatrixIndex; // [esp+76h] [ebp-5Ch]
  unsigned int batch; // [esp+7Ah] [ebp-58h]
  unsigned int Size; // [esp+7Eh] [ebp-54h]
  int v71; // [esp+82h] [ebp-50h]
  unsigned int v72; // [esp+86h] [ebp-4Ch]
  Scaleform::Render::ScopedRenderEvent v73; // [esp+8Ah] [ebp-48h] BYREF
  Scaleform::Render::MeshBase **v74; // [esp+8Eh] [ebp-44h] BYREF
  Scaleform::Render::Texture *v75; // [esp+92h] [ebp-40h]
  Scaleform::Render::Matrix2x4<float> *v76; // [esp+96h] [ebp-3Ch]
  char *v77; // [esp+9Ah] [ebp-38h] BYREF
  Scaleform::Render::Color result; // [esp+9Eh] [ebp-34h] BYREF
  Scaleform::AmpFunctionTimer v79; // [esp+A2h] [ebp-30h] BYREF
  Scaleform::Render::Cxform v80; // [esp+B2h] [ebp-20h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v5 = Instance->__vftable;
  v48.pData = (Scaleform::String::DataDesc *)-1;
  v47 = (Scaleform::Render::Color)2;
  v6 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::AmpServer *, const char *))v5->GetDisplayStats)(
                                Instance,
                                "Scaleform::Render::D3D1x::HAL::DrawProcessedComplexMeshes");
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    (Scaleform::AmpFunctionTimer *)((char *)&v79.StartTicks + 4),
    v6,
    (const char *)2,
    -1,
    v49);
  v49 = Amp_Native_Function_Id_AdvanceFrame;
  v48.pData = v7;
  Scaleform::String::String(&v48, "Scaleform::Render::D3D1x::HAL::DrawProcessedComplexMeshes");
  v8 = this->__vftable;
  v47 = (Scaleform::Render::Color)10;
  v9 = (Scaleform::Render::RenderEvent *)((int (__thiscall *)(Scaleform::Render::D3D1x::HAL *))v8->GetEvent)(this);
  Scaleform::Render::ScopedRenderEvent::ScopedRenderEvent(&v73, v9, (Scaleform::String)10, (bool)v48.pData);
  pCacheMeshItem = complexMesh->pCacheMeshItem;
  if ( Scaleform::Render::HAL::checkState(
         this,
         8u,
         (Scaleform::GFx::AS3::Value *)"Scaleform::Render::D3D1x::HAL::DrawProcessedComplexMeshes")
    && pCacheMeshItem )
  {
    if ( this->Profiler.OverrideMasks && !drawingMask_0 && (this->HALState & 0x40) != 0 )
    {
      Scaleform::Render::D3D1x::ProfileViewScopedOMChange::ProfileViewScopedOMChange(
        (Scaleform::Render::D3D1x::ProfileViewScopedOMChange *)&v80,
        &drawingMask_0,
        this->pDeviceContext,
        this->BlendStates[36],
        this->DepthStencilStates[0]);
      this->DrawProcessedComplexMeshes(this, complexMesh, matrices);
      Scaleform::Render::D3D1x::ProfileViewScopedOMChange::~ProfileViewScopedOMChange(v10, (int)&v80);
    }
    Data = complexMesh->FillRecords.Data.Data;
    Size = complexMesh->FillRecords.Data.Size;
    v11 = matrices->Size;
    v72 = (unsigned int)pCacheMeshItem[1].Type >> 1;
    meshCount = v11;
    v62 = 1;
    vertexBaseIndex = 0;
    v66 = 0;
    if ( v11 > 1 && this->SManager.ShaderModel == ShaderVersion_D3D1xFL1x )
    {
      MaxBatchInstances = this->Cache.GetParams(&this->Cache.Scaleform::Render::MeshCacheConfig)->MaxBatchInstances;
      v62 = v11;
      if ( v11 >= MaxBatchInstances )
        v62 = MaxBatchInstances;
      v67 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2;
      v13 = 1;
    }
    else
    {
      v67 = 0;
      v13 = 0;
    }
    v76 = complexMesh->FillMatrixCache.Data.Data;
    this->pDeviceContext->IASetIndexBuffer(
      this->pDeviceContext,
      (ID3D11Buffer *)pCacheMeshItem[1].pNext->pMeshes,
      DXGI_FORMAT_R16_UINT,
      0);
    index = 0;
    if ( Size )
    {
      v14 = Data;
      v71 = 4 * v13 + 4;
      v58 = Data;
      do
      {
        ColorForBatch = Scaleform::Render::ProfileViews::GetColorForBatch(
                          &this->Profiler,
                          &result,
                          (__int16)complexMesh,
                          index);
        v16 = meshCount == 0;
        this->Profiler.BatchColor = *ColorForBatch;
        fillFlags = this->FillFlags;
        if ( !v16 )
        {
          v17 = matrices;
          Format = matrices->pData->pHandle->pHeader->Format;
          sd = 0;
          fillFlags |= (Format >> 1) & 8;
          if ( meshCount )
          {
            while ( 1 )
            {
              v19 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)v17->pData + (_DWORD)sd * v17->StrideSize);
              v48.pData = (Scaleform::String::DataDesc *)&Scaleform::Render::Cxform::Identity;
              v47 = (Scaleform::Render::Color)v19;
              Cxform = (Scaleform::Render::Cxform *)Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(v19);
              v22 = Scaleform::Render::ProfileViews::GetCxform(
                      v21,
                      (Scaleform::Render::Cxform *)&this->Profiler,
                      &v80,
                      (float *)Cxform);
              if ( !Scaleform::Render::Cxform::operator==(v22, (const Scaleform::Render::Cxform *)v48.pData) )
                fillFlags |= 4u;
              sd = (const Scaleform::Render::D3D1x::ShaderPair *)((char *)sd + 1);
              if ( (unsigned int)sd >= meshCount )
                break;
              v17 = matrices;
            }
          }
        }
        Type = v14->pFill.pObject->Data.Type;
        if ( !this->Profiler.OverrideMasks || (fillType = PrimFill_SolidColor, Type != PrimFill_Mask) )
          fillType = Type;
        sd = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::SetFill(
               v67,
               fillType,
               &fillFlags,
               *(unsigned int *)((char *)&v14->pFill.pObject + v71),
               (const Scaleform::Render::VertexFormat *)v49,
               &this->ShaderData);
        v24 = *(int **)((char *)&v14->pFill.pObject + v71);
        v25 = *v24;
        if ( *v24 != v66 )
        {
          vertexBaseIndex = 0;
          v66 = v25;
          pMeshes = pCacheMeshItem[1].pPrev->pMeshes;
          v48.pData = (Scaleform::String::DataDesc *)&v77;
          v47 = (Scaleform::Render::Color)&v66;
          v74 = pMeshes;
          pDeviceContext = this->pDeviceContext;
          v77 = (char *)pCacheMeshItem[1].pCacheList + v14->VertexByteOffset;
          pDeviceContext->IASetVertexBuffers(
            pDeviceContext,
            0,
            1u,
            (ID3D11Buffer *const *)&v74,
            (const unsigned int *)&v66,
            (const unsigned int *)&v77);
        }
        TextureCount = Scaleform::Render::PrimitiveFillData::GetTextureCount(&v14->pFill.pObject->Data);
        if ( (unsigned int)fillType < PrimFill_SolidColor || (v53 = 0, fillType == PrimFill_SolidColor) )
          v53 = 1;
        v29 = meshCount;
        fillType = PrimFill_None;
        if ( meshCount )
        {
          Data = (Scaleform::Render::ComplexMesh::FillRecord *)TextureCount;
          do
          {
            v30 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)matrices->pData
                                                               + fillType * matrices->StrideSize);
            pObject = this->Matrices.pObject;
            batch = fillType % v62;
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
              v30,
              pObject,
              &this->ShaderData,
              sd,
              &complexMesh->VertexMatrix,
              (const Scaleform::Render::Matrix2x4<float> *)(fillType % v62),
              v49,
              v50);
            if ( v53 )
            {
              v48.pData = (Scaleform::String::DataDesc *)batch;
              Scaleform::Render::ProfileViews::GetColor(
                (Scaleform::Render::ProfileViews *)&v46.pVFormat,
                (int)&this->Profiler,
                &v47,
                (Scaleform::Render::Color *)v14->pFill.pObject->Data.SolidColor.Raw,
                v32);
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetColor(
                v33,
                &this->ShaderData,
                sd,
                v47,
                v48.HeapTypeBits,
                v49);
            }
            else if ( (fillFlags & 4) != 0 )
            {
              v48.pData = (Scaleform::String::DataDesc *)batch;
              v47 = v32;
              v34 = (Scaleform::Render::Cxform *)Scaleform::Render::MatrixPoolImpl::HMatrix::GetCxform(v30);
              v36 = Scaleform::Render::ProfileViews::GetCxform(
                      v35,
                      (Scaleform::Render::Cxform *)&this->Profiler,
                      &v80,
                      (float *)v34);
              Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetCxform(
                v36,
                &this->ShaderData,
                sd,
                v48.HeapTypeBits,
                v49);
            }
            v37 = 0;
            v60 = 0;
            v64 = 0;
            if ( Data )
            {
              v65 = 20;
              FillMatrixIndex = v14->FillMatrixIndex;
              while ( 1 )
              {
                Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
                  sd,
                  &this->ShaderData,
                  0xBu,
                  (float *)&v76[*FillMatrixIndex],
                  8u,
                  2 * v37,
                  batch);
                v48.pData = (Scaleform::String::DataDesc *)v64;
                v38 = v14->pFill.pObject;
                v39 = (Scaleform::Render::Texture *)(&v38->__vftable)[v65 / 4u];
                v47.Channels.Blue = v38->Data.FillModes[v37].Fill;
                qmemcpy((void *)&v46, sd, sizeof(v46));
                v75 = v39;
                Scaleform::Render::D3D1x::ShaderInterface::SetTexture(
                  0xAu,
                  v39,
                  &this->ShaderData,
                  v46,
                  (Scaleform::Render::ImageFillMode)v47.Channels.Blue,
                  v64);
                PlaneCount = Scaleform::Render::Texture::GetPlaneCount(v75);
                v64 += PlaneCount;
                ++v60;
                ++FillMatrixIndex;
                v65 += 4;
                v14 = v58;
                if ( v60 >= (unsigned int)Data )
                  break;
                v37 = v60;
              }
            }
            v41 = meshCount;
            HIBYTE(v51) = fillType == meshCount - 1;
            if ( v67 == (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2 )
            {
              v43 = v62;
              v44 = (fillType + 1) % v62;
              if ( !v44 && fillType || HIBYTE(v51) )
              {
                if ( HIBYTE(v51) && v44 )
                  v43 = (fillType + 1) % v62;
                Scaleform::Render::D3D1x::ShaderInterface::Finish(
                  (Scaleform::Render::D3D1x::ShaderInterface *)fillType,
                  (unsigned int)&this->ShaderData);
                Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(
                  this,
                  v43,
                  v14->IndexCount,
                  v72 + v14->IndexOffset,
                  vertexBaseIndex);
                ++this->AccumulatedStats.Primitives;
                if ( !HIBYTE(v51) )
                  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
                v14 = v58;
              }
            }
            else
            {
              Scaleform::Render::D3D1x::ShaderInterface::Finish(
                (Scaleform::Render::D3D1x::ShaderInterface *)fillType,
                (unsigned int)&this->ShaderData);
              Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(
                v42,
                (int)this,
                v14->IndexCount,
                v41,
                v72 + v14->IndexOffset,
                vertexBaseIndex);
              ++this->AccumulatedStats.Primitives;
              if ( !HIBYTE(v51) )
                Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::BeginPrimitive(&this->ShaderData);
            }
            ++fillType;
          }
          while ( fillType < meshCount );
          v29 = meshCount;
        }
        v45 = v14->IndexCount / 3;
        this->AccumulatedStats.Meshes += v29;
        this->AccumulatedStats.Primitives += v29;
        v58 = ++v14;
        this->AccumulatedStats.Triangles += v29 * v45;
        vertexBaseIndex += v14[-1].VertexCount;
        ++index;
      }
      while ( index < Size );
    }
    Scaleform::Render::MeshCacheItem::MoveToCacheListFront(pCacheMeshItem, MCL_ThisFrame);
  }
  v73.EventObj->End(v73.EventObj);
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v79);
}
