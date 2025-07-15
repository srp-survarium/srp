unsigned __int8 *__thiscall Scaleform::HeapMH::AllocEngineMH::allocFromPage(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned int size,
        unsigned int alignSize,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  Scaleform::HeapMH::AllocBitSet2MH *p_Allocator; // ebp
  unsigned __int8 *result; // eax
  Scaleform::HeapMH::PageMH *Page; // ebx
  bool limHandlerOK; // [esp+13h] [ebp-1Dh] BYREF
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+14h] [ebp-1Ch] BYREF

  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapMH::AllocBitSet2MH::Alloc(p_Allocator, size, alignSize, &headers);
    if ( result )
      break;
    if ( globalLocked )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(this, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(this, &limHandlerOK);
    if ( !limHandlerOK )
      return 0;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  Page = headers.Page;
  info->UsableSize = size;
  info->Page = Page;
  info->Node = 0;
  ++this->UseCount;
  this->UsedSpace += size;
  return result;
}


Scaleform::HeapMH::BinNodeMH *__thiscall Scaleform::HeapMH::AllocEngineMH::allocFromPage(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned int size,
        Scaleform::HeapMH::PageInfoMH *info,
        bool globalLocked)
{
  Scaleform::HeapMH::AllocBitSet2MH *p_Allocator; // ebp
  Scaleform::HeapMH::BinNodeMH *result; // eax
  Scaleform::HeapMH::PageMH *Page; // ebp
  bool limHandlerOK; // [esp+Fh] [ebp-1Dh] BYREF
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+10h] [ebp-1Ch] BYREF

  limHandlerOK = 0;
  p_Allocator = &this->Allocator;
  while ( 1 )
  {
    result = Scaleform::HeapMH::AllocBitSet2MH::Alloc(p_Allocator, size, &headers);
    if ( result )
      break;
    if ( globalLocked )
      Scaleform::HeapMH::AllocEngineMH::allocPageLocked(this, &limHandlerOK);
    else
      Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(this, &limHandlerOK);
    if ( !limHandlerOK )
      return 0;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  Page = headers.Page;
  info->UsableSize = size;
  info->Page = Page;
  info->Node = 0;
  ++this->UseCount;
  this->UsedSpace += size;
  return result;
}
