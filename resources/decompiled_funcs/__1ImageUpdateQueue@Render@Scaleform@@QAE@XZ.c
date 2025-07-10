void __thiscall Scaleform::Render::ImageUpdateQueue::~ImageUpdateQueue(Scaleform::Render::ImageUpdateQueue *this)
{
  unsigned int i; // esi
  Scaleform::RefCountVImpl **v3; // ecx

  for ( i = 0; i < this->Queue.Data.Size; ++i )
  {
    v3 = (Scaleform::RefCountVImpl **)&this->Queue.Data.Data[i];
    if ( ((unsigned __int8)*v3 & 1) != 0 )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)((unsigned int)*v3 & 0xFFFFFFFE) + 8))((unsigned int)*v3 & 0xFFFFFFFE);
    else
      Scaleform::RefCountImpl::Release(*v3);
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Queue.Data.Data);
}
