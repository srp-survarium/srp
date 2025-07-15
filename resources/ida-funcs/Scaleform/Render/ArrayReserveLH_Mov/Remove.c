void __thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::Remove(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2> *this,
        Scaleform::Render::MeshCacheItem *const *val)
{
  unsigned int Size; // edx
  $88FBCE611414C8C40FA76BF4D413C42A *v4; // edi
  $88FBCE611414C8C40FA76BF4D413C42A *pData; // ecx
  int v6; // eax
  unsigned __int8 *v7; // ecx
  Scaleform::Render::MeshCacheItem **v8; // eax

  Size = this->Size;
  v4 = &this->4;
  if ( this->Size <= 2 )
    pData = &this->4;
  else
    pData = ($88FBCE611414C8C40FA76BF4D413C42A *)v4->AD.pData;
  v6 = 0;
  if ( Size )
  {
    while ( (Scaleform::Render::MeshCacheItem *const)*((_DWORD *)&pData->AD.pData + v6) != *val )
    {
      if ( ++v6 >= Size )
        return;
    }
    if ( Size <= 2 )
      v7 = (unsigned __int8 *)v4;
    else
      v7 = (unsigned __int8 *)v4->AD.pData;
    memmove(&v7[4 * v6], &v7[4 * v6 + 4], 4 * (Size - v6) - 4);
    if ( --this->Size == 2 )
    {
      v8 = v4->AD.pData;
      v4->AD.pData = (Scaleform::Render::MeshCacheItem **)*v4->AD.pData;
      v4->AD.Reserve = (unsigned int)v8[1];
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
}
