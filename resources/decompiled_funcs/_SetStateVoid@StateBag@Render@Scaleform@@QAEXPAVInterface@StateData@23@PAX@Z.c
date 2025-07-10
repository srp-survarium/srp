void __thiscall Scaleform::Render::StateBag::SetStateVoid(
        Scaleform::Render::StateBag *this,
        Scaleform::Render::StateData::Interface *pi,
        void *data)
{
  unsigned int ArraySize; // ebx
  Scaleform::Render::StateData::ArrayData *v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // ebx
  int v9; // edi
  char *v10; // eax
  unsigned int v11; // edi
  Scaleform::Render::State *states; // [esp+Ch] [ebp-4h]

  ArraySize = this->ArraySize;
  if ( this->ArraySize )
  {
    if ( (ArraySize & 1) != 0 )
    {
      if ( (Scaleform::Render::StateData::Interface *)(ArraySize & 0xFFFFFFFE) == pi )
      {
        pi->AddRef(pi, data, Ref_All);
        pi->Release(pi, (void *)this->DataValue, Ref_All);
        this->DataValue = (unsigned int)data;
      }
      else
      {
        v5 = Scaleform::Render::StateBag::allocData(this, 0, 0, 2u);
        v6 = (unsigned int)v5;
        if ( v5 )
        {
          v7 = this->ArraySize;
          v5[2].RefCount = (volatile int)this->pData;
          v5[1].RefCount = v7 & 0xFFFFFFFE;
          v5[4].RefCount = (volatile int)data;
          v5[3].RefCount = (volatile int)pi;
          pi->AddRef(pi, data, Ref_All);
          this->DataValue = v6;
          this->ArraySize = 4;
        }
      }
    }
    else
    {
      v8 = ArraySize >> 1;
      v9 = 0;
      states = (Scaleform::Render::State *)(this->DataValue + 4);
      if ( v8 )
      {
        while ( *(Scaleform::Render::StateData::Interface **)(this->DataValue + 4 + 8 * v9) != pi )
        {
          if ( ++v9 >= v8 )
            goto LABEL_11;
        }
        pi->AddRef(pi, data, Ref_All);
        pi->Release(pi, (void *)states[v9].DataValue, Ref_All);
        states[v9].DataValue = (unsigned int)data;
      }
      else
      {
LABEL_11:
        v10 = (char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        this,
                        8 * v8 + 12,
                        0);
        v11 = (unsigned int)v10;
        if ( v10 )
        {
          *(_DWORD *)v10 = 1;
          Scaleform::Render::StateBag::copyArrayAddRef((Scaleform::Render::State *)(v10 + 4), states, v8);
          *(_DWORD *)(v11 + 8 * v8 + 8) = data;
          *(_DWORD *)(v11 + 8 * v8 + 4) = pi;
          pi->AddRef(pi, data, Ref_All);
          Scaleform::Render::StateData::ArrayData::Release(this->pArray, v8);
          this->ArraySize = 2 * v8 + 2;
          this->DataValue = v11;
        }
      }
    }
  }
  else
  {
    this->ArraySize = (unsigned int)pi | 1;
    this->DataValue = (unsigned int)data;
    pi->AddRef(pi, data, Ref_All);
  }
}
