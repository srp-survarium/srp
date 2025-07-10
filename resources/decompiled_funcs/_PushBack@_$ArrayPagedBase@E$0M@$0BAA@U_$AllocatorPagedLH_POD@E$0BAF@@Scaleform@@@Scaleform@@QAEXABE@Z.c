void __thiscall Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *this,
        const unsigned __int8 *val)
{
  unsigned int v3; // edi

  v3 = this->Size >> 12;
  if ( v3 >= this->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      this,
      this->Size >> 12);
  this->Pages[v3][this->Size++ & 0xFFF] = *val;
}
