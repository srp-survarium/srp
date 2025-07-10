Scaleform::Render::MeshUseStatus __thiscall Scaleform::Render::Mesh::GetUseStatus(Scaleform::Render::Mesh *this)
{
  unsigned int Size; // ebp
  Scaleform::Render::MeshUseStatus v2; // edi
  Scaleform::Render::MeshCacheItem **pData; // ebx
  unsigned int i; // esi
  Scaleform::Render::MeshUseStatus UseStatus; // eax

  Size = this->CacheItems.Size;
  v2 = MUS_Uncached;
  if ( Size <= 2 )
    pData = (Scaleform::Render::MeshCacheItem **)&this->CacheItems.4;
  else
    pData = this->CacheItems.AD.pData;
  for ( i = 0; i < Size; ++i )
  {
    UseStatus = Scaleform::Render::MeshCacheItem::GetUseStatus(pData[i]);
    if ( UseStatus > v2 )
      v2 = UseStatus;
  }
  return v2;
}
