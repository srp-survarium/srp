void __thiscall Scaleform::GFx::Button::RemoveDisplayObject(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::DisplayObjectBase *chToRemove)
{
  unsigned int *p_Size; // edi
  unsigned int i; // ebp
  int v4; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // ecx
  int v6; // esi
  Scaleform::RefCountNTSImpl *v7; // ecx
  _DWORD *v8; // esi
  int v9; // [esp+10h] [ebp-4h]

  p_Size = &this->States[0].Characters.Data.Size;
  v9 = 4;
  do
  {
    for ( i = 0; i < *p_Size; ++i )
    {
      v4 = *(_DWORD *)(8 * i + *(p_Size - 1));
      if ( v4 )
      {
        v5 = *(_BYTE *)(v4 + 62) >> 7 != 0 ? (Scaleform::GFx::DisplayObjectBase *)v4 : 0;
        if ( v5 == chToRemove )
        {
          v5->OnEventUnload(v5);
          v6 = *(p_Size - 1);
          v7 = *(Scaleform::RefCountNTSImpl **)(v6 + 8 * i);
          v8 = (_DWORD *)(8 * i + v6);
          if ( v7 )
            Scaleform::RefCountNTSImpl::Release(v7);
          *v8 = 0;
        }
      }
    }
    p_Size += 4;
    --v9;
  }
  while ( v9 );
}
