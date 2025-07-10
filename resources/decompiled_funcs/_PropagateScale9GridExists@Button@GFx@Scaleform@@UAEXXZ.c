void __thiscall Scaleform::GFx::Button::PropagateScale9GridExists(Scaleform::GFx::Button *this)
{
  bool HasScale9Grid; // al
  bool v3; // dl
  unsigned int *p_Size; // edi
  unsigned int i; // esi
  int v6; // eax
  _WORD *v7; // ecx
  bool actualGrid; // [esp+Bh] [ebp-5h]
  int v9; // [esp+Ch] [ebp-4h]

  HasScale9Grid = Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this);
  v3 = HasScale9Grid;
  actualGrid = HasScale9Grid;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 1) != 0
    || !HasScale9Grid )
  {
    p_Size = &this->States[0].Characters.Data.Size;
    v9 = 4;
    do
    {
      for ( i = 0; i < *p_Size; ++i )
      {
        v6 = *(_DWORD *)(*(p_Size - 1) + 8 * i);
        if ( v6 )
        {
          v7 = *(_BYTE *)(v6 + 62) >> 7 != 0 ? (_WORD *)v6 : 0;
          if ( v7 )
          {
            if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
                & 1) != 0
              || v3 )
            {
              v7[31] |= 1u;
            }
            else
            {
              v7[31] &= ~1u;
            }
            (*(void (__thiscall **)(_WORD *))(*(_DWORD *)v7 + 72))(v7);
            v3 = actualGrid;
          }
        }
      }
      p_Size += 4;
      --v9;
    }
    while ( v9 );
  }
}
