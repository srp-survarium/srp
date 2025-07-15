void __usercall btStackAlloc::create(btStackAlloc *this@<esi>, unsigned int size@<edi>)
{
  unsigned __int8 *data; // eax

  if ( !this->usedsize )
  {
    if ( !this->ischild )
    {
      data = this->data;
      if ( this->data )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(data);
      }
    }
    this->data = 0;
    this->usedsize = 0;
  }
  ++gNumAlignedAllocs;
  this->data = (unsigned __int8 *)sAlignedAllocFunc(size, 16);
  this->totalsize = size;
}
