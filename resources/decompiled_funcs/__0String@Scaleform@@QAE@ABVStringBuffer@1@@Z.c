void __thiscall Scaleform::String::String(Scaleform::String *this, const Scaleform::StringBuffer *src)
{
  char *pData; // eax

  pData = src->pData;
  if ( !src->pData )
    pData = (char *)&buf;
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       src->Size,
                                       0,
                                       pData,
                                       src->Size);
}
