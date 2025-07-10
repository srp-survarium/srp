void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newSize)
{
  unsigned int Size; // eax
  int v5; // eax
  Scaleform::GFx::AS3::Multiname *v6; // ebx
  int v7; // ebp

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize + (newSize >> 2));
  }
  else
  {
    v5 = Size - newSize;
    v6 = &this->Data[v5 - 1 + newSize];
    if ( v5 )
    {
      v7 = v5;
      do
      {
        Scaleform::GFx::AS3::Multiname::~Multiname(v6--);
        --v7;
      }
      while ( v7 );
    }
    if ( newSize < this->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize);
      this->Size = newSize;
      return;
    }
  }
  this->Size = newSize;
}
