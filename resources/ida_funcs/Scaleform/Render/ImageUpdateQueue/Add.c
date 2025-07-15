void __thiscall Scaleform::Render::ImageUpdateQueue::Add(
        Scaleform::Render::ImageUpdateQueue *this,
        Scaleform::Render::Image *pimage)
{
  unsigned int v3; // esi
  unsigned int *v4; // eax

  v3 = this->Queue.Data.Size + 1;
  if ( v3 >= this->Queue.Data.Size )
  {
    if ( v3 >= this->Queue.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
        &this->Queue.Data,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Queue.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
      &this->Queue.Data,
      this,
      this->Queue.Data.Size + 1);
  }
  v4 = &this->Queue.Data.Data[v3 - 1];
  this->Queue.Data.Size = v3;
  if ( v4 )
    *v4 = (unsigned int)pimage | 1;
  pimage->AddRef(pimage);
}
