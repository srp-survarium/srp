char __thiscall Scaleform::Render::StateBag::RemoveState(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateType type)
{
  unsigned int ArraySize; // eax
  Scaleform::Render::StateData::Interface *v5; // ecx
  char *pData; // ebx
  unsigned int v7; // eax
  unsigned int v8; // ebp
  unsigned int i; // esi
  unsigned int v10; // ecx
  Scaleform::Render::StateData::ArrayData *v11; // eax

  ArraySize = this->ArraySize;
  if ( !this->ArraySize )
    return 0;
  v5 = StateType_Interfaces[type];
  if ( (ArraySize & 1) == 0 )
  {
    pData = (char *)this->pData;
    v7 = ArraySize >> 1;
    v8 = v7;
    for ( i = 0; i < v7; ++i )
    {
      if ( *(Scaleform::Render::StateData::Interface **)&pData[8 * i + 4] == v5 )
        break;
    }
    if ( i != v7 )
    {
      if ( v7 == 2 )
      {
        v10 = *(_DWORD *)&pData[8 * (i ^ 1) + 8];
        this->ArraySize = *(_DWORD *)&pData[8 * (i ^ 1) + 4] | 1;
        this->DataValue = v10;
        (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)&pData[8 * (i ^ 1) + 4] + 4))(
          *(_DWORD *)&pData[8 * (i ^ 1) + 4],
          *(_DWORD *)&pData[8 * (i ^ 1) + 8],
          1);
LABEL_15:
        (*(void (__thiscall **)(_DWORD, _DWORD, int))(**(_DWORD **)&pData[8 * i + 4] + 8))(
          *(_DWORD *)&pData[8 * i + 4],
          *(_DWORD *)&pData[8 * i + 8],
          2);
        Scaleform::Render::StateData::ArrayData::Release((Scaleform::Render::StateData::ArrayData *)pData, v8);
        return 1;
      }
      v11 = Scaleform::Render::StateBag::allocData2(
              this,
              (Scaleform::Render::State *)(pData + 4),
              i,
              (Scaleform::Render::State *)&pData[8 * i + 12],
              v7 - i - 1);
      if ( v11 )
      {
        this->ArraySize = 2 * v8 - 2;
        this->DataValue = (unsigned int)v11;
        goto LABEL_15;
      }
    }
    return 0;
  }
  if ( (Scaleform::Render::StateData::Interface *)(ArraySize & 0xFFFFFFFE) != v5 )
    return 0;
  v5->Release(v5, this->pData, Ref_All);
  this->ArraySize = 0;
  this->DataValue = 0;
  return 1;
}
