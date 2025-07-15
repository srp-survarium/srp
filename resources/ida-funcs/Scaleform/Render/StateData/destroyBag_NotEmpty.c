void __thiscall Scaleform::Render::StateData::destroyBag_NotEmpty(Scaleform::Render::StateData *this)
{
  unsigned int ArraySize; // ecx

  ArraySize = this->ArraySize;
  if ( (ArraySize & 1) != 0 )
    (*(void (__thiscall **)(unsigned int, unsigned int, int))(*(_DWORD *)(ArraySize & 0xFFFFFFFE) + 8))(
      ArraySize & 0xFFFFFFFE,
      this->DataValue,
      1);
  else
    Scaleform::Render::StateData::ArrayData::Release(this->pArray, ArraySize >> 1);
  this->DataValue = 0;
  this->ArraySize = 0;
}
