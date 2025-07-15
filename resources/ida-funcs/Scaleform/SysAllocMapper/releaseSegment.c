void __thiscall Scaleform::SysAllocMapper::releaseSegment(Scaleform::SysAllocMapper *this, unsigned int pos)
{
  char *v3; // edi
  unsigned int PageSize; // eax
  int v5; // edx
  int v6; // edi
  unsigned int NumSegments; // eax
  char *v8; // [esp+14h] [ebp-4h]

  v3 = (char *)this + 12 * pos;
  PageSize = this->PageSize;
  v5 = *((_DWORD *)v3 + 8);
  v8 = v3;
  v6 = (int)(v3 + 28);
  this->pMapper->UnmapPages(
    this->pMapper,
    (void *)(v5
           + *(_DWORD *)v6
           - (~(PageSize - 1) & (PageSize + ((v5 + 8 * PageSize - 1) >> (LOBYTE(this->PageShift) + 3)) - 1))),
    ~(PageSize - 1) & (PageSize + ((v5 + 8 * PageSize - 1) >> (LOBYTE(this->PageShift) + 3)) - 1));
  this->pMapper->ReleaseAddrSpace(this->pMapper, *(void **)v6, *(_DWORD *)(v6 + 4));
  NumSegments = this->NumSegments;
  if ( pos + 1 < NumSegments )
    memmove(v6, (const __m128i *)(v8 + 40), 12 * (NumSegments - pos - 1));
  --this->NumSegments;
  this->LastSegment = -1;
}
