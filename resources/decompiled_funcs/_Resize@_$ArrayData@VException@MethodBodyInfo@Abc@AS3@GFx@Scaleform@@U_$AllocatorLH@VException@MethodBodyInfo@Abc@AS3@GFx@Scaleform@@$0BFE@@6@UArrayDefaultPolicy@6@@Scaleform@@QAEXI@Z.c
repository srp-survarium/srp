void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception,340>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int newSize)
{
  unsigned int Size; // esi
  int v4; // edi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v5; // eax

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,Scaleform::AllocatorLH<Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
  {
    v4 = newSize - Size;
    v5 = &this->Data[Size];
    if ( newSize != Size )
    {
      do
      {
        if ( v5 )
        {
          v5->info.Data.Data = 0;
          v5->info.Data.Size = 0;
          v5->info.Data.Policy.Capacity = 0;
        }
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}
