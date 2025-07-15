void __usercall Scaleform::Render::D3D1x::ShaderInterface::Finish(
        Scaleform::Render::D3D1x::ShaderInterface *this@<ecx>,
        int a2@<edi>)
{
  int v2; // ebx
  _BYTE *v3; // eax
  int v4; // ebp
  signed int v5; // eax
  int v6; // ecx
  Scaleform::Render::D3D1x::ShaderConstantRange *p_shaderConstantRangeVS; // esi
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // ebx
  int v12; // eax
  int v13; // [esp+Ch] [ebp-38h]
  Scaleform::Render::D3D1x::ShaderConstantRange shaderConstantRangeVS; // [esp+10h] [ebp-34h] BYREF
  Scaleform::Render::D3D1x::ShaderConstantRange shaderConstantRangeFS; // [esp+28h] [ebp-1Ch] BYREF

  v2 = 0;
  shaderConstantRangeFS.pHal = *(Scaleform::Render::D3D1x::HAL **)(a2 + 4384);
  shaderConstantRangeVS.pHal = shaderConstantRangeFS.pHal;
  v3 = (_BYTE *)(a2 + 4352);
  shaderConstantRangeFS.UniformData = (float *)a2;
  shaderConstantRangeFS.pConstantBuffer = 0;
  shaderConstantRangeVS.UniformData = (float *)a2;
  shaderConstantRangeVS.pConstantBuffer = 0;
  v13 = a2 + 4352;
  v4 = 8;
  do
  {
    if ( !*v3 )
      goto LABEL_8;
    v5 = *(_DWORD *)(*(_DWORD *)(a2 + 4396) + v4 + 4);
    if ( v5 < 0 )
    {
      v5 = *(_DWORD *)(*(_DWORD *)(a2 + 4388) + v4);
      if ( v5 < 0 )
        goto LABEL_8;
      v6 = *(_DWORD *)(a2 + 4392);
      p_shaderConstantRangeVS = &shaderConstantRangeVS;
    }
    else
    {
      v6 = *(_DWORD *)(a2 + 4400);
      p_shaderConstantRangeVS = &shaderConstantRangeFS;
    }
    Scaleform::Render::D3D1x::ShaderConstantRange::Update(
      p_shaderConstantRangeVS,
      v5,
      *(__int16 *)(*(_DWORD *)(v6 + 20) + v2 + 6),
      *(__int16 *)(*(_DWORD *)(v6 + 20) + v2 + 2));
LABEL_8:
    v4 += 4;
    v3 = (_BYTE *)(v13 + 1);
    v2 += 10;
    ++v13;
  }
  while ( v4 < 68 );
  if ( shaderConstantRangeVS.pConstantBuffer )
  {
    shaderConstantRangeVS.pHal->pDeviceContext->Unmap(
      shaderConstantRangeVS.pHal->pDeviceContext,
      shaderConstantRangeVS.pConstantBuffer,
      0);
    shaderConstantRangeVS.pHal->pDeviceContext->VSSetConstantBuffers(
      shaderConstantRangeVS.pHal->pDeviceContext,
      0,
      1u,
      &shaderConstantRangeVS.pConstantBuffer);
  }
  if ( shaderConstantRangeFS.pConstantBuffer )
  {
    shaderConstantRangeFS.pHal->pDeviceContext->Unmap(
      shaderConstantRangeFS.pHal->pDeviceContext,
      shaderConstantRangeFS.pConstantBuffer,
      0);
    shaderConstantRangeFS.pHal->pDeviceContext->PSSetConstantBuffers(
      shaderConstantRangeFS.pHal->pDeviceContext,
      0,
      1u,
      &shaderConstantRangeFS.pConstantBuffer);
  }
  *(_QWORD *)(a2 + 4352) = 0;
  *(_DWORD *)(a2 + 4360) = 0;
  *(_WORD *)(a2 + 4364) = 0;
  *(_BYTE *)(a2 + 4366) = 0;
  v8 = *(_DWORD *)(*(_DWORD *)(a2 + 4384) + 63796);
  v9 = *(_DWORD *)(*(_DWORD *)(a2 + 4388) + 4);
  if ( *(_DWORD *)(a2 + 4408) != v9 )
  {
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 44))(v8, v9, 0, 0);
    *(_DWORD *)(a2 + 4408) = *(_DWORD *)(*(_DWORD *)(a2 + 4388) + 4);
  }
  v10 = *(_DWORD *)(*(_DWORD *)(a2 + 4404) + 8);
  v11 = *(_DWORD *)(v10 + 8);
  if ( *(_DWORD *)(a2 + 4416) != v11 )
  {
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v8 + 68))(v8, *(_DWORD *)(v10 + 8));
    *(_DWORD *)(a2 + 4416) = v11;
  }
  v12 = *(_DWORD *)(*(_DWORD *)(a2 + 4396) + 4);
  if ( *(_DWORD *)(a2 + 4412) != v12 )
  {
    (*(void (__stdcall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 36))(v8, v12, 0, 0);
    *(_DWORD *)(a2 + 4412) = *(_DWORD *)(*(_DWORD *)(a2 + 4396) + 4);
  }
}
