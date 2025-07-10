void __thiscall Scaleform::Render::LinearHeap::Clear(Scaleform::Render::LinearHeap *this)
{
  unsigned int v1; // edx
  int v2; // esi

  v1 = 0;
  if ( this->MaxPages )
  {
    v2 = 0;
    do
    {
      ++v1;
      this->pPagePool[v2].pFree = this->pPagePool[v2].pStart;
      ++v2;
    }
    while ( v1 < this->MaxPages );
    this->pLastPage = this->pPagePool;
  }
  else
  {
    this->pLastPage = this->pPagePool;
  }
}
