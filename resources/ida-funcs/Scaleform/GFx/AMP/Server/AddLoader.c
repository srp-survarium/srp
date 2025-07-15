void __thiscall Scaleform::GFx::AMP::Server::AddLoader(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *loader)
{
  Scaleform::Render::Renderer2D **p_CurrentRenderer; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Size; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v6; // eax

  p_CurrentRenderer = &this->CurrentRenderer;
  EnterCriticalSection((LPCRITICAL_SECTION)&this->CurrentRenderer);
  p_Size = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TaskStats.Data.Size;
  v5 = this->TaskStats.Data.Policy.Capacity + 1;
  if ( v5 >= p_Size->Size )
  {
    if ( v5 >= p_Size->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Size,
        p_Size,
        v5 + (v5 >> 2));
  }
  else if ( v5 < p_Size->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Size,
      p_Size,
      v5);
  }
  v6 = &p_Size->Data[v5 - 1];
  p_Size->Size = v5;
  if ( v6 )
    v6->pObject = loader;
  LeaveCriticalSection((LPCRITICAL_SECTION)p_CurrentRenderer);
}
