void __thiscall Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(
        Scaleform::Render::D3D1x::MeshCache *this,
        int a2)
{
  int v2; // ecx
  int *v3; // esi
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  int v7; // eax
  Scaleform::Render::FenceImpl *v8; // eax
  int *v10; // eax
  int *v11; // ecx
  int v12; // [esp+8h] [ebp-14h] BYREF
  int *v13; // [esp+Ch] [ebp-10h]
  int *v14; // [esp+10h] [ebp-Ch]
  int *v15; // [esp+14h] [ebp-8h]
  int *v16; // [esp+18h] [ebp-4h]

  v2 = a2;
  v3 = *(int **)(a2 + 392);
  v16 = &v12;
  v13 = &v12;
  v14 = &v12;
  while ( 1 )
  {
    v4 = a2 == -388 ? 0 : a2 + 384;
    if ( v3 == (int *)v4 )
      break;
    v5 = (_DWORD *)(v2 + 168);
    v6 = *(_DWORD **)(v2 + 172);
    v15 = (int *)v3[2];
    *(_DWORD *)(v3[1] + 8) = v15;
    *(_DWORD *)(v3[2] + 4) = v3[1];
    while ( 1 )
    {
      if ( v6 == v5 )
      {
        (*(void (__thiscall **)(int *, int))*v3)(v3, 1);
        goto LABEL_18;
      }
      if ( (int *)v6[14] == v3 || (int *)v6[15] == v3 )
      {
        v7 = v6[13];
        if ( v7 )
        {
          if ( *(_BYTE *)(v7 + 6)
            && (v8 = *(Scaleform::Render::FenceImpl **)v7) != 0
            && Scaleform::Render::FenceImpl::IsPending(v8, FenceType_Vertex) )
          {
            break;
          }
        }
      }
      v6 = (_DWORD *)v6[1];
      v5 = (_DWORD *)(a2 + 168);
    }
    v3[2] = (int)v14;
    v3[1] = (int)v16;
    v14[1] = (int)v3;
    v14 = v3;
LABEL_18:
    v3 = v15;
    v2 = a2;
  }
  v10 = v14;
  if ( v14 != v16 )
  {
    v11 = v13;
    v13[2] = *(_DWORD *)(a2 + 392);
    v10[1] = a2 + 384;
    *(_DWORD *)(*(_DWORD *)(a2 + 392) + 4) = v11;
    *(_DWORD *)(a2 + 392) = v10;
  }
}
