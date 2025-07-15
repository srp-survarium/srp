void __thiscall Scaleform::HeapMH::AllocEngineMH::GetPageInfoWithSize(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::NodeMH *node,
        _BYTE *ptr,
        Scaleform::HeapMH::PageInfoMH *info)
{
  info->Page = 0;
  info->Node = node;
  info->UsableSize = (char *)node - ptr;
}


void __thiscall Scaleform::HeapMH::AllocEngineMH::GetPageInfoWithSize(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        const void *ptr,
        Scaleform::HeapMH::PageInfoMH *info)
{
  unsigned int UsableSize; // eax

  info->Page = 0;
  info->Node = 0;
  info->UsableSize = 0;
  UsableSize = Scaleform::HeapMH::AllocBitSet2MH::GetUsableSize(&this->Allocator, page, ptr);
  info->Page = page;
  info->UsableSize = UsableSize;
}
