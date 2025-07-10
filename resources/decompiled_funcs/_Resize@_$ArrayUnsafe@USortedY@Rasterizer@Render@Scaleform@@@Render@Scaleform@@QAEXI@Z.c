void __thiscall Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY>::Resize(
        Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *this,
        unsigned int size)
{
  unsigned __int8 *v3; // ebx
  unsigned __int8 *Array; // eax
  unsigned int v5; // ecx

  if ( size > this->Size )
  {
    v3 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 8 * size);
    memset((int)v3, 0, 8 * size);
    Array = (unsigned __int8 *)this->Array;
    if ( Array )
    {
      v5 = this->Size;
      if ( v5 )
        memcpy(v3, Array, 8 * v5);
    }
    this->Array = (Scaleform::Render::Rasterizer::SortedY *)v3;
  }
  this->Size = size;
}
