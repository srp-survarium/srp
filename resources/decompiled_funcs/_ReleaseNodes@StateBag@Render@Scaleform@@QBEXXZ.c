void __thiscall Scaleform::Render::StateBag::ReleaseNodes(Scaleform::Render::StateBag *this)
{
  unsigned int ArraySize; // edi
  unsigned int v2; // edi
  _DWORD *i; // esi

  ArraySize = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( ((int)this->pInterface & 1) != 0 )
    {
      (*(void (__thiscall **)(unsigned int, unsigned int, int))(*(_DWORD *)(ArraySize & 0xFFFFFFFE) + 8))(
        ArraySize & 0xFFFFFFFE,
        this->DataValue,
        2);
    }
    else
    {
      v2 = ArraySize >> 1;
      for ( i = (_DWORD *)(this->DataValue + 4); v2; i += 2 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD, int))(*(_DWORD *)*i + 8))(*i, i[1], 2);
        --v2;
      }
    }
  }
}
