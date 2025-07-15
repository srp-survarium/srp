bool __userpurge Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer@<al>(
        ID3D11Device *pdevice@<esi>,
        Scaleform::Render::D3D1x::MeshCache *this)
{
  float v2; // xmm1_4
  unsigned int v3; // ecx
  char *v4; // eax
  ID3D11Device_vtbl *v5; // eax
  char v7; // [esp+0h] [ebp-6E4h] BYREF
  char v8; // [esp+4h] [ebp-6E0h] BYREF
  _DWORD v9[6]; // [esp+6C0h] [ebp-24h] BYREF
  _DWORD v10[3]; // [esp+6D8h] [ebp-Ch] BYREF

  v2 = s_bm_current_air_resistance;
  v9[1] = 1;
  v9[2] = 1;
  v9[0] = 1728;
  memset(&v9[3], 0, 12);
  v3 = 0;
  v4 = &v8;
  do
  {
    v4[4] = v3;
    v4[16] = v3;
    v4[28] = v3;
    v4[40] = v3;
    v4[52] = v3;
    v4[64] = v3;
    *((_DWORD *)v4 - 1) = 0;
    *(float *)v4 = v2;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((float *)v4 + 5) = v2;
    *((_DWORD *)v4 + 6) = 0;
    *((_DWORD *)v4 + 8) = 0;
    *((float *)v4 + 9) = v2;
    *((float *)v4 + 11) = v2;
    *((_DWORD *)v4 + 12) = 0;
    *((float *)v4 + 14) = v2;
    *((float *)v4 + 15) = v2;
    ++v3;
    v4 += 72;
  }
  while ( v3 < 0x18 );
  v10[0] = &v7;
  v5 = pdevice->lpVtbl;
  v10[1] = 0;
  v10[2] = 0;
  return v5->CreateBuffer(
           pdevice,
           (const D3D11_BUFFER_DESC *)v9,
           (const D3D11_SUBRESOURCE_DATA *)v10,
           &this->pMaskEraseBatchVertexBuffer.pObject) >= 0;
}
