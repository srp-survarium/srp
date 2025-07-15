void __thiscall Scaleform::MsgFormat::~MsgFormat(Scaleform::MsgFormat *this)
{
  unsigned int Size; // eax
  unsigned int v3; // ebp
  int v4; // ebx
  char *v5; // eax
  void (__thiscall ***v6)(void *, _DWORD); // esi
  unsigned int v7; // [esp+8h] [ebp-4h]

  Size = this->Data.Size;
  v3 = 0;
  this->__vftable = (Scaleform::MsgFormat_vtbl *)&Scaleform::MsgFormat::`vftable';
  v7 = Size;
  if ( Size )
  {
    v4 = 0;
    do
    {
      if ( v3 >= 0x10 )
        v5 = (char *)&this->Data.DynamicArray.Data.Data[v4 - 16];
      else
        v5 = &this->Data.StaticArray[v4 * 12];
      if ( *(_DWORD *)v5 == 2 )
      {
        if ( v5[8] )
        {
          v6 = (void (__thiscall ***)(void *, _DWORD))*((_DWORD *)v5 + 1);
          if ( v6 )
          {
            (**v6)(v6, 0);
            if ( v6 < (void (__thiscall ***)(void *, _DWORD))this->MemPool.Buff
              || v6 >= (void (__thiscall ***)(void *, _DWORD))&this->MemPool.BuffPtr )
            {
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
            }
          }
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < v7 );
  }
  if ( this->Data.DynamicArray.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.DynamicArray.Data.Data);
  this->__vftable = (Scaleform::MsgFormat_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
}
