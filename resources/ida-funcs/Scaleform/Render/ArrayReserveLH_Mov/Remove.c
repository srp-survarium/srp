void __thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::Remove(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2> *this,
        Scaleform::Render::MeshCacheItem *const *val)
{
  unsigned int Size; // edx
  $D8AE60E3AA0BDAD0AF35438D9065EEAA *v4; // edi
  $D8AE60E3AA0BDAD0AF35438D9065EEAA *pData; // ecx
  int v6; // eax
  char *v7; // ecx
  Scaleform::Render::MeshCacheItem **v8; // eax

  Size = this->Size;
  v4 = &this->4;
  if ( this->Size <= 2 )
    pData = &this->4;
  else
    pData = ($D8AE60E3AA0BDAD0AF35438D9065EEAA *)v4->AD.pData;
  v6 = 0;
  if ( Size )
  {
    while ( (Scaleform::Render::MeshCacheItem *const)*((_DWORD *)&pData->AD.pData + v6) != *val )
    {
      if ( ++v6 >= Size )
        return;
    }
    if ( Size <= 2 )
      v7 = (char *)v4;
    else
      v7 = (char *)v4->AD.pData;
    memmove((int)&v7[4 * v6], (const __m128i *)&v7[4 * v6 + 4], 4 * (Size - v6) - 4);
    if ( --this->Size == 2 )
    {
      v8 = v4->AD.pData;
      v4->AD.pData = (Scaleform::Render::MeshCacheItem **)*v4->AD.pData;
      v4->AD.Reserve = (unsigned int)v8[1];
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
}
