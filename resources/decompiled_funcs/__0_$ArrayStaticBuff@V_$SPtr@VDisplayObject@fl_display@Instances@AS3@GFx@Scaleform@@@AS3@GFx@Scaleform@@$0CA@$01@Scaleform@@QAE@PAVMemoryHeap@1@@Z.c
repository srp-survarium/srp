void __thiscall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *Static; // edx
  int v3; // esi

  this->pHeap = heap;
  this->Size = 0;
  this->Reserved = 32;
  Static = this->Static;
  v3 = 8;
  do
  {
    Static->pObject = 0;
    Static[1].pObject = 0;
    Static[2].pObject = 0;
    Static[3].pObject = 0;
    Static += 4;
    --v3;
  }
  while ( v3 );
  this->Data = this->Static;
}
