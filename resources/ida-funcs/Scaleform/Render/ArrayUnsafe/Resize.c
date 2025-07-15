void __thiscall Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
        Scaleform::Render::ArrayUnsafe<int> *this,
        unsigned int size)
{
  unsigned __int8 *v3; // ebx
  int *Array; // eax
  unsigned int v5; // ecx

  if ( size > this->Size )
  {
    v3 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 4 * size);
    memset((int)v3, 0, 4 * size);
    Array = this->Array;
    if ( Array )
    {
      v5 = this->Size;
      if ( v5 )
        memcpy(v3, (unsigned __int8 *)Array, 4 * v5);
    }
    this->Array = (int *)v3;
  }
  this->Size = size;
}


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
