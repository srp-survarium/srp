void __thiscall Scaleform::GFx::Button::Restart(Scaleform::GFx::Button *this)
{
  unsigned int *p_Size; // edi
  int v2; // ebp
  unsigned int i; // esi
  int v4; // ecx

  this->LastMouseFlags = 0;
  this->mMouseFlags = 0;
  this->MouseState = Unknown;
  this->RollOverCnt = 0;
  p_Size = &this->States[0].Characters.Data.Size;
  v2 = 4;
  do
  {
    for ( i = 0; i < *p_Size; ++i )
    {
      v4 = *(_DWORD *)(*(p_Size - 1) + 8 * i);
      if ( v4 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 272))(v4);
    }
    p_Size += 4;
    --v2;
  }
  while ( v2 );
}
