void __thiscall Scaleform::Render::RawImage::freeData(Scaleform::Render::RawImage *this)
{
  unsigned int v2; // ebx
  int v3; // edi
  unsigned __int8 *pData; // eax

  v2 = 0;
  if ( this->Data.RawPlaneCount )
  {
    v3 = 0;
    do
    {
      pData = this->Data.pPlanes[v3].pData;
      if ( pData )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pData);
        this->Data.pPlanes[v3].pData = 0;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->Data.RawPlaneCount );
  }
}
