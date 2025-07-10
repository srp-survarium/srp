void __thiscall Scaleform::String::String(Scaleform::String *this, char *pdata, unsigned int size)
{
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       size,
                                       0,
                                       pdata,
                                       size);
}
