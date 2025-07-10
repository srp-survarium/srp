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
