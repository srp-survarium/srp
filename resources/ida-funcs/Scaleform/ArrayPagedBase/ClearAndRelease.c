void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this)
{
  unsigned int NumPages; // eax
  void **v3; // ebp
  unsigned int Size; // eax
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // eax
  Scaleform::GFx::AS3::CallFrame *v8; // edi
  unsigned int v9; // ebx
  unsigned int numDataPages; // [esp+4h] [ebp-4h]

  NumPages = this->NumPages;
  if ( NumPages )
  {
    v3 = (void **)&this->Pages[NumPages - 1];
    Size = this->Size;
    if ( Size )
    {
      v5 = Size >> 6;
      numDataPages = Size >> 6;
    }
    else
    {
      numDataPages = 0;
      v5 = 0;
    }
    do
    {
      v6 = --this->NumPages;
      if ( v6 >= v5 )
      {
        if ( v6 == v5 )
          v7 = this->Size & 0x3F;
        else
          v7 = 0;
      }
      else
      {
        v7 = 64;
      }
      v8 = (Scaleform::GFx::AS3::CallFrame *)((char *)*v3 + 96 * v7 - 96);
      if ( v7 )
      {
        v9 = v7;
        do
        {
          Scaleform::GFx::AS3::CallFrame::~CallFrame(v8--);
          --v9;
        }
        while ( v9 );
        v5 = numDataPages;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v3--);
    }
    while ( this->NumPages );
    --this->NumPages;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Pages);
  }
  this->MaxPages = 0;
  this->NumPages = 0;
  this->Size = 0;
  this->Pages = 0;
}
