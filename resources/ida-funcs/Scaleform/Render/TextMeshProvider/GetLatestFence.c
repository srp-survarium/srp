Scaleform::Render::Fence *__thiscall Scaleform::Render::TextMeshProvider::GetLatestFence(
        Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::Fence *v1; // ebp
  Scaleform::Render::Mesh *pObject; // edi
  unsigned int v3; // ebx
  _DWORD *p_pData; // eax
  _DWORD *v5; // eax
  Scaleform::Render::FenceImpl *v6; // ecx
  _DWORD *pData; // eax
  int v8; // esi
  int v9; // eax
  Scaleform::Render::Fence **v10; // esi
  int v12; // [esp+4h] [ebp-Ch]
  unsigned int v13; // [esp+8h] [ebp-8h]
  Scaleform::Render::TextMeshProvider *v14; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v14 = this;
  v13 = 0;
  if ( this->Layers.Data.Size )
  {
    v12 = 0;
    do
    {
      pObject = this->Layers.Data.Data[v12].pMesh.pObject;
      if ( pObject )
      {
        v3 = 0;
        if ( pObject->CacheItems.Size )
        {
          do
          {
            if ( pObject->CacheItems.Size <= 2 )
              p_pData = &pObject->CacheItems.AD.pData;
            else
              p_pData = pObject->CacheItems.AD.pData;
            if ( *(_DWORD *)(p_pData[v3] + 52) )
            {
              if ( !v1
                || (pObject->CacheItems.Size <= 2
                  ? (v5 = &pObject->CacheItems.AD.pData)
                  : (v5 = pObject->CacheItems.AD.pData),
                    (v6 = **(Scaleform::Render::FenceImpl ***)(v5[v3] + 52)) != 0
                 && (!v1->Data || Scaleform::Render::FenceImpl::operator>(v6, v1->Data))) )
              {
                if ( pObject->CacheItems.Size <= 2 )
                  pData = &pObject->CacheItems.AD.pData;
                else
                  pData = pObject->CacheItems.AD.pData;
                v8 = pData[v3];
                v9 = *(_DWORD *)(v8 + 52);
                v10 = (Scaleform::Render::Fence **)(v8 + 52);
                if ( v9 )
                  ++*(_WORD *)(v9 + 4);
                if ( v1 )
                  Scaleform::Render::Fence::Release(v1);
                v1 = *v10;
              }
            }
            ++v3;
          }
          while ( v3 < pObject->CacheItems.Size );
          this = v14;
        }
      }
      ++v12;
      ++v13;
    }
    while ( v13 < this->Layers.Data.Size );
    if ( v1 )
      Scaleform::Render::Fence::Release(v1);
  }
  return v1;
}
