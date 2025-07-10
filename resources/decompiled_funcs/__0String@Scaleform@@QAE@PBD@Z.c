void __thiscall Scaleform::String::String(Scaleform::String *this, char *pdata)
{
  unsigned int v3; // eax

  if ( pdata )
    v3 = strlen(pdata);
  else
    v3 = 0;
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       v3,
                                       0,
                                       pdata,
                                       v3);
}
