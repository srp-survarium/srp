void __thiscall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *Data; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *Static; // ebp
  unsigned int Size; // ebx
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int RefCount; // eax

  Data = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Data;
  Static = this->Static;
  if ( Data != (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Static )
  {
    if ( this->Size )
    {
      Size = this->Size;
      do
      {
        pHeap = Data->pHeap;
        if ( Data->pHeap )
        {
          if ( ((unsigned __int8)pHeap & 1) != 0 )
          {
            Data->pHeap = (Scaleform::MemoryHeap *)((char *)pHeap - 1);
          }
          else
          {
            RefCount = pHeap->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              pHeap->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pHeap);
            }
          }
        }
        Data = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)((char *)Data + 4);
        --Size;
      }
      while ( Size );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
  }
  this->Data = Static;
  this->Size = 0;
}
