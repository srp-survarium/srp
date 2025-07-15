unsigned __int8 *__thiscall Scaleform::Render::LinearHeap::Alloc(
        Scaleform::Render::LinearHeap *this,
        unsigned int size)
{
  unsigned __int8 *result; // eax
  Scaleform::Render::LinearHeap::PageType *v4; // eax
  signed int MaxPages; // eax
  int v6; // ebx
  Scaleform::Render::LinearHeap::PageType *v7; // edi
  unsigned int v8; // eax

  if ( this->pLastPage )
  {
    result = Scaleform::Render::LinearHeap::allocFromLastPage(this, (size + 3) & 0xFFFFFFFC);
    if ( result )
      return result;
    ++this->pLastPage;
  }
  else
  {
    v4 = (Scaleform::Render::LinearHeap::PageType *)((int (__stdcall *)(int, _DWORD))this->pHeap->Alloc)(768, 0);
    this->pPagePool = v4;
    this->pLastPage = v4;
    memset((int)v4, 0, 768);
    this->MaxPages = 64;
  }
  MaxPages = this->MaxPages;
  v6 = this->pLastPage - this->pPagePool;
  if ( v6 >= MaxPages )
  {
    v7 = (Scaleform::Render::LinearHeap::PageType *)this->pHeap->Alloc(this->pHeap, 24 * MaxPages, 0);
    memcpy((int)v7, (const __m128i *)this->pPagePool, 12 * this->MaxPages);
    memset((int)&v7[this->MaxPages], 0, 12 * this->MaxPages);
    this->pHeap->Free(this->pHeap, this->pPagePool);
    v8 = this->MaxPages;
    this->pPagePool = v7;
    this->MaxPages = 2 * v8;
    this->pLastPage = &v7[v6];
  }
  return Scaleform::Render::LinearHeap::allocFromLastPage(this, (size + 3) & 0xFFFFFFFC);
}
