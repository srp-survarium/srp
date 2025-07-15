void __thiscall Scaleform::GFx::AS3::VM::UnregisterGlobalObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *go)
{
  unsigned int Size; // edx
  int v4; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **i; // ecx

  Size = this->GlobalObjects.Data.Size;
  v4 = 0;
  if ( Size )
  {
    for ( i = this->GlobalObjects.Data.Data; *i != go; ++i )
    {
      if ( ++v4 >= Size )
        return;
    }
    if ( Size == 1 )
    {
      if ( (this->GlobalObjects.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( this->GlobalObjects.Data.Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->GlobalObjects.Data.Data);
          this->GlobalObjects.Data.Data = 0;
        }
        this->GlobalObjects.Data.Policy.Capacity = 0;
      }
      this->GlobalObjects.Data.Size = 0;
    }
    else
    {
      memmove(
        (int)&this->GlobalObjects.Data.Data[v4],
        (const __m128i *)&this->GlobalObjects.Data.Data[v4 + 1],
        4 * (Size - v4) - 4);
      --this->GlobalObjects.Data.Size;
    }
  }
}
