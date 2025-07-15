void __thiscall Scaleform::Render::StateBag::StateBag(
        Scaleform::Render::StateBag *this,
        const Scaleform::Render::StateBag *src)
{
  unsigned int ArraySize; // eax
  char *pData; // ecx

  this->ArraySize = 0;
  this->DataValue = 0;
  ArraySize = src->ArraySize;
  if ( src->ArraySize )
  {
    pData = (char *)src->pData;
    if ( (ArraySize & 1) != 0 )
    {
      (*(void (__thiscall **)(unsigned int, char *, int))(*(_DWORD *)(ArraySize & 0xFFFFFFFE) + 4))(
        ArraySize & 0xFFFFFFFE,
        pData,
        1);
      *this = *src;
    }
    else
    {
      this->DataValue = (unsigned int)Scaleform::Render::StateBag::allocData(
                                        this,
                                        (Scaleform::Render::State *)(pData + 4),
                                        ArraySize >> 1,
                                        0);
      this->ArraySize = src->ArraySize;
    }
  }
}
