void __thiscall Scaleform::GFx::Button::SetStateChangeFlags(Scaleform::GFx::Button *this, int flags)
{
  unsigned int *p_Size; // edi
  int v3; // ebp
  unsigned int i; // esi
  int v5; // ecx

  this->Scaleform::GFx::InteractiveObject::Flags ^= (this->Scaleform::GFx::InteractiveObject::Flags
                                                   ^ ((unsigned __int8)flags << 16))
                                                  & 0xF0000;
  p_Size = &this->States[0].Characters.Data.Size;
  v3 = 4;
  do
  {
    for ( i = 0; i < *p_Size; ++i )
    {
      v5 = *(_DWORD *)(*(p_Size - 1) + 8 * i);
      if ( v5 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 308))(v5, flags);
    }
    p_Size += 4;
    --v3;
  }
  while ( v3 );
}
