unsigned int __thiscall Scaleform::Render::StateBag::GetState(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateType type)
{
  unsigned int result; // eax
  Scaleform::Render::StateData::Interface *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  int v6; // ecx

  result = this->ArraySize;
  if ( this->ArraySize )
  {
    v3 = StateType_Interfaces[type];
    if ( (result & 1) != 0 )
    {
      return v3 == (Scaleform::Render::StateData::Interface *)(result & 0xFFFFFFFE) ? (unsigned int)this : 0;
    }
    else
    {
      v4 = result >> 1;
      v5 = this->DataValue + 4;
      v6 = 0;
      if ( v4 )
      {
        while ( *(Scaleform::Render::StateData::Interface **)(v5 + 8 * v6) != v3 )
        {
          if ( ++v6 >= v4 )
            return 0;
        }
        return v5 + 8 * v6;
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
