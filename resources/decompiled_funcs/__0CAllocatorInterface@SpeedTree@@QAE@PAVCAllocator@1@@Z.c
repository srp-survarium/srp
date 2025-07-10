SpeedTree::CAllocatorInterface *__thiscall SpeedTree::CAllocatorInterface::CAllocatorInterface(
        SpeedTree::CAllocatorInterface *this,
        struct SpeedTree::CAllocator *a2)
{
  SpeedTree::g_pAllocator = a2;
  return this;
}
