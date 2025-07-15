void __thiscall Scaleform::Render::D3D1x::HAL::DrawProcessedComplexMeshes(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::ComplexMesh *complexMesh,
        const Scaleform::Render::StrideArray<Scaleform::Render::MatrixPoolImpl::HMatrix> *matrices)
{
  Scaleform::Render::D3D1x::HAL *v3; // edi
  Scaleform::Render::RenderEvent *v4; // esi
  Scaleform::Render::RenderEvent_vtbl *v5; // ebx
  unsigned int v6; // ecx
  void *v7; // ebx
  bool v8; // zf
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // ebx
  unsigned int Size; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int MaxBatchInstances; // eax
  Scaleform::Render::Matrix2x4<float> *v14; // ecx
  ID3D11DeviceContext *pDeviceContext; // eax
  Scaleform::Render::MeshBase **pMeshes; // edx
  int p_ShaderData; // ebx
  unsigned int i; // esi
  int v19; // ecx
  Scaleform::Render::Cxform *v20; // eax
  Scaleform::Render::PrimitiveFillType Type; // eax
  Scaleform::Render::D3D1x::ShaderDesc::ShaderType v22; // eax
  Scaleform::Render::D3D1x::ShaderInterface *v23; // ecx
  unsigned int *v24; // esi
  int v25; // ecx
  unsigned int v26; // eax
  int *v27; // ecx
  int v28; // edx
  ID3D11DeviceContext *v29; // ecx
  int v30; // ecx
  unsigned __int8 v31; // dl
  unsigned int v32; // ecx
  const Scaleform::Render::MatrixPoolImpl::HMatrix *v33; // esi
  unsigned int v34; // edi
  Scaleform::Render::D3D1x::ShaderInterface *v35; // ecx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  Scaleform::Render::Cxform *v37; // eax
  __int64 v38; // xmm0_8
  unsigned int v39; // edi
  unsigned __int8 *v40; // esi
  void (__thiscall *v41)(unsigned __int8 *, int, unsigned __int8 *); // edx
  Scaleform::Render::ImageFormat v42; // eax
  unsigned int FormatPlaneCount; // eax
  Scaleform::Render::D3D1x::HAL *v44; // edi
  unsigned int v45; // esi
  unsigned int v46; // edx
  __int64 v47; // rax
  Scaleform::Render::MeshCacheListSet *pCacheList; // ecx
  unsigned int *p_Size; // eax
  Scaleform::Render::MeshCacheListSet *v50; // ecx
  Scaleform::Render::MeshCacheItem *pNext; // edx
  Scaleform::String v52[4]; // [esp+A60h] [ebp-C4h] BYREF
  unsigned __int8 Fill; // [esp+A72h] [ebp-B2h] BYREF
  char v54; // [esp+A73h] [ebp-B1h]
  Scaleform::Render::ComplexMesh::FillRecord *v55; // [esp+A74h] [ebp-B0h]
  unsigned int v56; // [esp+A78h] [ebp-ACh]
  int Raw; // [esp+A7Ch] [ebp-A8h]
  unsigned int fillflags; // [esp+A80h] [ebp-A4h] BYREF
  unsigned int Data; // [esp+A84h] [ebp-A0h]
  int v60; // [esp+A88h] [ebp-9Ch]
  Scaleform::Render::D3D1x::HAL *v61; // [esp+A8Ch] [ebp-98h]
  unsigned int v62; // [esp+A90h] [ebp-94h]
  unsigned int batch; // [esp+A94h] [ebp-90h]
  unsigned int v64; // [esp+A98h] [ebp-8Ch]
  unsigned int v65; // [esp+A9Ch] [ebp-88h]
  int v66; // [esp+AA0h] [ebp-84h] BYREF
  Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *v67; // [esp+AA4h] [ebp-80h]
  int v68; // [esp+AA8h] [ebp-7Ch]
  int v69; // [esp+AACh] [ebp-78h]
  Scaleform::String src[2]; // [esp+AB0h] [ebp-74h] BYREF
  int v71; // [esp+AB8h] [ebp-6Ch]
  Scaleform::Render::MeshCacheItem *v72; // [esp+ABCh] [ebp-68h]
  unsigned int v73; // [esp+AC0h] [ebp-64h]
  Scaleform::Render::RenderEvent *v74; // [esp+AC4h] [ebp-60h]
  int v75; // [esp+AC8h] [ebp-5Ch] BYREF
  Scaleform::Render::MeshBase **v76; // [esp+ACCh] [ebp-58h] BYREF
  Scaleform::Render::Matrix2x4<float> *v77; // [esp+AD0h] [ebp-54h]
  float v78[4]; // [esp+AD4h] [ebp-50h] BYREF
  _QWORD v[2]; // [esp+AE4h] [ebp-40h] BYREF
  _QWORD v80[2]; // [esp+AF4h] [ebp-30h] BYREF
  Scaleform::Render::Cxform v81; // [esp+B04h] [ebp-20h] BYREF

  v3 = this;
  v61 = this;
  Scaleform::String::String(&src[1], (char *)&stru_973EB4);
  v4 = v3->GetEvent(v3, Event_DrawComplex);
  v5 = v4->__vftable;
  v52[0].HeapTypeBits = v6;
  v74 = v4;
  Scaleform::String::String(v52, &src[1]);
  ((void (__thiscall *)(Scaleform::Render::RenderEvent *, unsigned int))v5->Begin)(v4, v52[0].HeapTypeBits);
  v7 = (void *)(src[1].HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((src[1].HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  v8 = (v3->HALState & 8) == 0;
  pCacheMeshItem = complexMesh->pCacheMeshItem;
  v72 = pCacheMeshItem;
  if ( v8 )
  {
    Scaleform::GFx::AS2::Object::SetValue((Scaleform::GFx::AS3::Instances::fl_geom::Transform *)v3, 8u, &stru_973EB4);
    v74->End(v74);
    return;
  }
  if ( pCacheMeshItem )
  {
    Size = complexMesh->FillRecords.Data.Size;
    Data = (unsigned int)complexMesh->FillRecords.Data.Data;
    v11 = matrices->Size;
    v64 = Size;
    v12 = (unsigned int)pCacheMeshItem[1].Type >> 1;
    v56 = v11;
    v73 = v12;
    v62 = 1;
    v60 = 0;
    v66 = 0;
    if ( v11 > 1 && v3->SManager.ShaderModel == ShaderVersion_D3D1xFL1x )
    {
      MaxBatchInstances = v3->Cache.GetParams(&v3->Cache.Scaleform::Render::MeshCacheConfig)->MaxBatchInstances;
      v62 = v56;
      if ( v56 >= MaxBatchInstances )
        v62 = MaxBatchInstances;
      v67 = (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2;
      v69 = 1;
    }
    else
    {
      v67 = 0;
      v69 = 0;
    }
    v14 = complexMesh->FillMatrixCache.Data.Data;
    pDeviceContext = v3->pDeviceContext;
    v52[0].HeapTypeBits = 0;
    pMeshes = pCacheMeshItem[1].pNext->pMeshes;
    v77 = v14;
    pDeviceContext->IASetIndexBuffer(pDeviceContext, (ID3D11Buffer *)pMeshes, DXGI_FORMAT_R16_UINT, 0);
    if ( v64 )
    {
      p_ShaderData = (int)&v3->ShaderData;
      v55 = (Scaleform::Render::ComplexMesh::FillRecord *)Data;
      while ( 1 )
      {
        fillflags = v3->FillFlags;
        if ( v56 )
        {
          fillflags |= (matrices->pData->pHandle->pHeader->Format >> 1) & 8;
          for ( i = 0; i < v56; ++i )
          {
            v19 = **(_DWORD **)((char *)&matrices->pData->pHandle + i * matrices->StrideSize);
            if ( (*(_BYTE *)(v19 + 11) & 1) != 0 )
              v20 = (Scaleform::Render::Cxform *)(v19
                                                + 16
                                                * (Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[*(_BYTE *)(v19 + 11) & 0xF].Offsets[0]
                                                 + 1));
            else
              v20 = &Scaleform::Render::Cxform::Identity;
            v81 = *v20;
            if ( !Scaleform::Render::Cxform::operator==(&v81, &Scaleform::Render::Cxform::Identity) )
              fillflags |= 4u;
          }
        }
        Type = v55->pFill.pObject->Data.Type;
        v52[0] = (Scaleform::String)v55->pFormats[v69];
        Data = Type;
        v22 = Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture>::StaticShaderForFill(
                Type,
                &fillflags,
                v67,
                v52[0].HeapTypeBits);
        Scaleform::Render::D3D1x::ShaderInterface::SetStaticShader(
          v23,
          p_ShaderData,
          v22,
          (const Scaleform::Render::VertexFormat *)v52[0].pData);
        v24 = (unsigned int *)v55;
        v25 = v69;
        v26 = 0;
        *(_QWORD *)(p_ShaderData + 4352) = 0;
        *(_DWORD *)(p_ShaderData + 4360) = 0;
        *(_WORD *)(p_ShaderData + 4364) = 0;
        *(_BYTE *)(p_ShaderData + 4366) = 0;
        *(_QWORD *)(p_ShaderData + 4368) = 0;
        *(_QWORD *)(p_ShaderData + 4376) = 0;
        v27 = (int *)v24[v25 + 1];
        if ( *v27 != v66 )
        {
          v66 = *v27;
          v60 = 0;
          v28 = (int)v72[1].pCacheList + v24[5];
          v76 = v72[1].pPrev->pMeshes;
          v29 = v3->pDeviceContext;
          v75 = v28;
          v29->IASetVertexBuffers(
            v29,
            0,
            1u,
            (ID3D11Buffer *const *)&v76,
            (const unsigned int *)&v66,
            (const unsigned int *)&v75);
          v26 = 0;
        }
        v30 = *(_DWORD *)(*v24 + 8);
        if ( v30 < 5 || v30 > 10 )
          v31 = 0;
        else
          v31 = (v30 >= 9) + 1;
        if ( Data < 2 || (v54 = 0, Data == 2) )
          v54 = 1;
        v32 = v56;
        v65 = 0;
        if ( v56 )
          break;
LABEL_60:
        v47 = 2863311531LL * v24[4];
        v3->AccumulatedStats.Meshes += v32;
        v3->AccumulatedStats.Primitives += v32;
        v3->AccumulatedStats.Triangles += v32 * (HIDWORD(v47) >> 1);
        v60 += v24[6];
        v8 = v64-- == 1;
        v55 = (Scaleform::Render::ComplexMesh::FillRecord *)(v24 + 10);
        if ( v8 )
        {
          pCacheMeshItem = v72;
          goto LABEL_62;
        }
      }
      Data = v31;
      while ( 1 )
      {
        v33 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)matrices->pData + v26 * matrices->StrideSize);
        v52[0] = (Scaleform::String)v3->Matrices.pObject;
        batch = v26 % v62;
        v34 = v26 % v62;
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetMatrix(
          &complexMesh->VertexMatrix,
          v33,
          v26 % v62,
          (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)p_ShaderData,
          (const Scaleform::Render::D3D1x::ShaderPair *)(p_ShaderData + 4388),
          (const Scaleform::Render::MatrixState *)v52[0].pData,
          (const Scaleform::Render::MatrixState *)v52[1].pData,
          v52[2].HeapTypeBits);
        if ( v54 )
        {
          Raw = v55->pFill.pObject->Data.SolidColor.Raw;
          v78[0] = (float)BYTE2(Raw) * 0.0039215689;
          v78[1] = (float)BYTE1(Raw) * 0.0039215689;
          v78[2] = (float)(unsigned __int8)Raw * 0.0039215689;
          v78[3] = (float)HIBYTE(Raw) * 0.0039215689;
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (const Scaleform::Render::D3D1x::ShaderPair *)(p_ShaderData + 4388),
            1u,
            0,
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)p_ShaderData,
            v78,
            4u,
            v34);
        }
        else if ( (fillflags & 4) != 0 )
        {
          pHeader = v33->pHandle->pHeader;
          if ( (pHeader->Format & 1) != 0 )
            v37 = (Scaleform::Render::Cxform *)(&pHeader[1].RefCount
                                              + 4
                                              * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]);
          else
            v37 = &Scaleform::Render::Cxform::Identity;
          v[0] = *(_QWORD *)&v37->M[0][0];
          v[1] = *(_QWORD *)&v37->M[0][2];
          v38 = *(_QWORD *)&v37->M[1][0];
          v52[0].HeapTypeBits = batch;
          v80[0] = v38;
          v80[1] = *(_QWORD *)&v37->M[1][2];
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (const Scaleform::Render::D3D1x::ShaderPair *)(p_ShaderData + 4388),
            1u,
            0,
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)p_ShaderData,
            (const float *)v,
            4u,
            batch);
          Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
            (const Scaleform::Render::D3D1x::ShaderPair *)(p_ShaderData + 4388),
            0,
            0,
            (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)p_ShaderData,
            (const float *)v80,
            4u,
            batch);
        }
        v39 = 0;
        v68 = 0;
        if ( Data )
        {
          Raw = 20;
          src[0].HeapTypeBits = (unsigned int)v55->FillMatrixIndex;
          do
          {
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              (const Scaleform::Render::D3D1x::ShaderPair *)(p_ShaderData + 4388),
              0xBu,
              2 * v39,
              (Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *)p_ShaderData,
              (const float *)&v77[src[0].pData->Size],
              8u,
              batch);
            v40 = *(unsigned __int8 **)((char *)&v55->pFill.pObject->__vftable + Raw);
            v41 = *(void (__thiscall **)(unsigned __int8 *, int, unsigned __int8 *))(*(_DWORD *)v40 + 48);
            Fill = v55->pFill.pObject->Data.FillModes[v39].Fill;
            v41(v40, v68 + v61->ShaderData.CurShaders.pFDesc->Uniforms[10].Location, &Fill);
            if ( (v40[38] & 2) != 0 )
              v71 = 1;
            else
              v71 = v40[36];
            v42 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v40 + 16))(v40);
            FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(v42);
            v68 += v71 * FormatPlaneCount;
            src[0].HeapTypeBits += 4;
            Raw += 4;
            ++v39;
          }
          while ( v39 < Data );
        }
        LOBYTE(v35) = v65 == v56 - 1;
        Fill = (unsigned __int8)v35;
        if ( v67 != (Scaleform::Render::StaticShaderManager<Scaleform::Render::D3D1x::ShaderDesc,Scaleform::Render::D3D1x::VertexShaderDesc,Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderInterface,Scaleform::Render::D3D1x::Texture> *)2 )
          break;
        v45 = v62;
        v46 = (v65 + 1) % v62;
        if ( !v46 && v65 || v65 == v56 - 1 )
        {
          if ( v65 == v56 - 1 && v46 )
            v45 = (v65 + 1) % v62;
          Scaleform::Render::D3D1x::ShaderInterface::Finish(v35, p_ShaderData);
          v44 = v61;
          v61->pDeviceContext->DrawIndexedInstanced(
            v61->pDeviceContext,
            v55->IndexCount,
            v45,
            v73 + v55->IndexOffset,
            v60,
            0);
          goto LABEL_56;
        }
LABEL_58:
        v3 = v61;
        if ( ++v65 >= v56 )
        {
          v24 = (unsigned int *)v55;
          v32 = v56;
          goto LABEL_60;
        }
        v26 = v65;
      }
      Scaleform::Render::D3D1x::ShaderInterface::Finish(v35, p_ShaderData);
      v44 = v61;
      v61->pDeviceContext->DrawIndexed(v61->pDeviceContext, v55->IndexCount, v73 + v55->IndexOffset, v60);
LABEL_56:
      ++v44->AccumulatedStats.Primitives;
      if ( !Fill )
      {
        *(_QWORD *)(p_ShaderData + 4352) = 0;
        *(_DWORD *)(p_ShaderData + 4360) = 0;
        *(_WORD *)(p_ShaderData + 4364) = 0;
        *(_BYTE *)(p_ShaderData + 4366) = 0;
        *(_QWORD *)(p_ShaderData + 4368) = 0;
        *(_QWORD *)(p_ShaderData + 4376) = 0;
      }
      goto LABEL_58;
    }
LABEL_62:
    pCacheList = pCacheMeshItem->pCacheList;
    pCacheMeshItem->pPrev->pNext = pCacheMeshItem->pNext;
    pCacheMeshItem->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$181941B0ECCE92AAF0AD80025FE0C204::pPrev = pCacheMeshItem->pPrev;
    p_Size = &pCacheList->Slots[pCacheMeshItem->ListType].Size;
    *p_Size -= pCacheMeshItem->AllocSize;
    v50 = pCacheMeshItem->pCacheList;
    pCacheMeshItem->ListType = MCL_ThisFrame;
    pNext = v50->Slots[2].Root.pNext;
    pCacheMeshItem->pPrev = (Scaleform::Render::MeshCacheItem *)&v50->Slots[2];
    pCacheMeshItem->pNext = pNext;
    v50->Slots[2].Root.pNext->pPrev = pCacheMeshItem;
    v50->Slots[2].Root.pNext = pCacheMeshItem;
    v50->Slots[2].Size += pCacheMeshItem->AllocSize;
  }
  v74->End(v74);
}
