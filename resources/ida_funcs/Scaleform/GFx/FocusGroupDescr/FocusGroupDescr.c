void __thiscall Scaleform::GFx::FocusGroupDescr::FocusGroupDescr(
        Scaleform::GFx::FocusGroupDescr *this,
        Scaleform::MemoryHeap *heap)
{
  const Scaleform::MemoryHeap *v2; // eax

  v2 = heap;
  this->FocusRectNode.pObject = 0;
  if ( !heap )
    v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->TabableArray.Data.Data = 0;
  this->TabableArray.Data.Size = 0;
  this->TabableArray.Data.Policy.Capacity = 0;
  this->TabableArray.Data.pHeap = v2;
  this->LastFocused.pProxy.pObject = 0;
  this->ModalClip.pObject = 0;
  this->LastFocusKeyCode = 0;
  this->LastFocusedRect.x1 = 0.0;
  this->LastFocusedRect.y1 = 0.0;
  this->LastFocusedRect.x2 = 0.0;
  this->LastFocusedRect.y2 = 0.0;
  this->FocusRectShown = 0;
  this->TabableArrayStatus = 0;
}
