void __thiscall Scaleform::GFx::AMP::Server::CollectMeshCacheStats(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::Render::Renderer2D *CurrentRenderer; // ecx
  Scaleform::Render::HAL *HAL; // eax
  int v4; // eax
  int i; // edx
  int v6; // esi
  int v7; // ecx
  _DWORD v8[7]; // [esp+4h] [ebp-38h] BYREF
  _DWORD v9[7]; // [esp+20h] [ebp-1Ch] BYREF

  CurrentRenderer = this->CurrentRenderer;
  memset(v9, 0, sizeof(v9));
  memset(v8, 0, sizeof(v8));
  HAL = Scaleform::Render::Renderer2D::GetHAL(CurrentRenderer);
  v4 = (int)HAL->GetMeshCache(HAL);
  (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v4 + 56))(v4, v8);
  for ( i = 0; i < 7; ++i )
  {
    v6 = v9[i];
    v7 = v8[i] - v6;
    if ( (i & 4) != 0 )
    {
      frameProfile->MeshCacheGraphicsMemory += v6;
      frameProfile->MeshCacheGraphicsUnusedMemory += v7;
    }
    else
    {
      frameProfile->MeshCacheMemory += v6;
      frameProfile->MeshCacheUnusedMemory += v7;
    }
  }
}
