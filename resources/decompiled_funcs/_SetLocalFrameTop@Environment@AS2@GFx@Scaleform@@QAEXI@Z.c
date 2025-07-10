void __thiscall Scaleform::GFx::AS2::Environment::SetLocalFrameTop(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int t)
{
  unsigned int Size; // ebx
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2,Scaleform::ArrayDefaultPolicy> *p_LocalFrames; // edi
  int v4; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v5; // eax

  Size = this->LocalFrames.Data.Size;
  p_LocalFrames = &this->LocalFrames;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames,
    &this->LocalFrames,
    t);
  if ( t > Size )
  {
    v4 = t - Size;
    v5 = &p_LocalFrames->Data.Data[Size];
    if ( t != Size )
    {
      do
      {
        if ( v5 )
          v5->pObject = 0;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
