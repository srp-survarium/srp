void __thiscall Scaleform::GFx::AS2::Environment::DropLocalRegisters(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int RegisterCount)
{
  unsigned int Size; // ebx
  Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *p_LocalRegister; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  unsigned int v5; // esi

  Size = this->LocalRegister.Data.Size;
  p_LocalRegister = &this->LocalRegister;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->LocalRegister.Data,
    &this->LocalRegister,
    Size - RegisterCount);
  if ( Size - RegisterCount > Size )
  {
    v4 = &p_LocalRegister->Data.Data[Size];
    v5 = -RegisterCount;
    if ( RegisterCount )
    {
      do
      {
        if ( v4 )
          v4->T.Type = 0;
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}
