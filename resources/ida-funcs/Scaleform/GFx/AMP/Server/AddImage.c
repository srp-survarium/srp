void __thiscall Scaleform::GFx::AMP::Server::AddImage(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *image)
{
  unsigned int *p_Size; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_LockSemaphore; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v6; // eax

  if ( (Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, image)->Info.Desc.Flags & 0x1000) == 0 )
  {
    p_Size = &this->Images.Data.Size;
    EnterCriticalSection((LPCRITICAL_SECTION)&this->Images.Data.Size);
    p_LockSemaphore = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->MovieLock.cs.LockSemaphore;
    v5 = this->MovieLock.cs.SpinCount + 1;
    if ( v5 >= p_LockSemaphore->Size )
    {
      if ( v5 >= p_LockSemaphore->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_LockSemaphore,
          p_LockSemaphore,
          v5 + (v5 >> 2));
    }
    else if ( v5 < p_LockSemaphore->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_LockSemaphore,
        p_LockSemaphore,
        v5);
    }
    v6 = &p_LockSemaphore->Data[v5 - 1];
    p_LockSemaphore->Size = v5;
    if ( v6 )
      v6->pObject = image;
    LeaveCriticalSection((LPCRITICAL_SECTION)p_Size);
  }
}
