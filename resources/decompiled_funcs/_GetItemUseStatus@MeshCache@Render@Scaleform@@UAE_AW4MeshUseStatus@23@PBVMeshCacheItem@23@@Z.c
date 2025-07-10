Scaleform::Render::MeshUseStatus __thiscall Scaleform::Render::MeshCache::GetItemUseStatus(
        Scaleform::Render::MeshCache *this,
        const Scaleform::Render::MeshCacheItem *item)
{
  Scaleform::Render::MeshUseStatus result; // eax

  switch ( item->ListType )
  {
    case MCL_InFlight:
      result = MUS_InUse;
      break;
    case MCL_ThisFrame:
      result = MUS_ThisFrame;
      break;
    case MCL_PrevFrame:
      result = MUS_PrevFrame;
      break;
    case MCL_LRUTail:
      result = MUS_LRUTail;
      break;
    default:
      result = MUS_Uncached;
      break;
  }
  return result;
}
