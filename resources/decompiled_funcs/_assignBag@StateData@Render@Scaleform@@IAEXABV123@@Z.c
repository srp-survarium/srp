void __thiscall Scaleform::Render::StateData::assignBag(
        Scaleform::Render::StateData *this,
        const Scaleform::Render::StateData *src)
{
  unsigned int ArraySize; // ecx
  unsigned int v4; // ecx

  ArraySize = src->ArraySize;
  if ( src->ArraySize )
  {
    if ( (ArraySize & 1) != 0 )
      (*(void (__thiscall **)(unsigned int, unsigned int, int))(*(_DWORD *)(ArraySize & 0xFFFFFFFE) + 4))(
        ArraySize & 0xFFFFFFFE,
        src->DataValue,
        1);
    else
      InterlockedExchangeAdd((volatile LONG *)src->pData, 1);
  }
  v4 = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( (v4 & 1) != 0 )
      (*(void (__thiscall **)(unsigned int, unsigned int, int))(*(_DWORD *)(v4 & 0xFFFFFFFE) + 8))(
        v4 & 0xFFFFFFFE,
        this->DataValue,
        1);
    else
      Scaleform::Render::StateData::ArrayData::Release(this->pArray, v4 >> 1);
    this->ArraySize = 0;
    this->DataValue = 0;
  }
  *this = *src;
}
