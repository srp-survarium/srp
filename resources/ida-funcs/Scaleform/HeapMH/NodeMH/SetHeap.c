void __thiscall Scaleform::HeapMH::NodeMH::SetHeap(
        Scaleform::HeapMH::NodeMH *this,
        unsigned int heap,
        unsigned int align)
{
  switch ( align )
  {
    case 1u:
    case 2u:
    case 4u:
      this->pHeap = heap;
      break;
    case 8u:
      this->pHeap = heap | 1;
      break;
    case 0x10u:
      this->pHeap = heap | 2;
      break;
    default:
      this->Align = align;
      this->pHeap = heap | 3;
      break;
  }
}
