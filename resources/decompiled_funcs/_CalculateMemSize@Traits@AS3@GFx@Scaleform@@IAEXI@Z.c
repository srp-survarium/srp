void __thiscall Scaleform::GFx::AS3::Traits::CalculateMemSize(
        Scaleform::GFx::AS3::Traits *this,
        unsigned int parent_size)
{
  unsigned int Index; // esi
  int v4; // edx
  int v5; // eax
  int v6; // ebp
  int v7; // ebx
  unsigned int FirstOwnSlotNum; // ecx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ebp
  unsigned int v15; // ebx
  unsigned int v16; // esi
  Scaleform::GFx::AS3::SlotInfo *v17; // ecx
  int v18; // eax
  int v19; // edx
  unsigned int v20; // [esp+10h] [ebp-18h]
  unsigned int size; // [esp+14h] [ebp-14h]
  int v22; // [esp+18h] [ebp-10h]
  int v23; // [esp+20h] [ebp-8h]
  unsigned int parent_sizea; // [esp+2Ch] [ebp+4h]

  Index = this->FirstOwnSlotInd.Index;
  this->MemSize = parent_size;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  size = this->FirstOwnSlotNum + this->VArray.Data.Size;
  v22 = 0;
  v23 = 0;
  if ( Index < size )
  {
    do
    {
      if ( (Index & 0x80000000) == 0 && (FirstOwnSlotNum = this->FirstOwnSlotNum, Index >= FirstOwnSlotNum) )
        p_Value = &this->VArray.Data.Data[Index - FirstOwnSlotNum].Value;
      else
        p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                     (Scaleform::GFx::AS3::Slots *)this->Parent,
                                                     (Scaleform::GFx::AS3::AbsoluteIndex)Index);
      v10 = *(_DWORD *)p_Value;
      if ( (v10 & 0x10) == 0 )
      {
        switch ( v10 << 22 >> 27 )
        {
          case 2:
            ++v7;
            break;
          case 3:
          case 6:
          case 7:
          case 9:
            ++v6;
            break;
          case 5:
            ++v22;
            break;
          case 8:
            ++v23;
            break;
          default:
            break;
        }
      }
      ++Index;
    }
    while ( Index < size );
    v5 = v23;
    v4 = v22;
  }
  if ( v7 + v6 + v5 + v4 )
  {
    v11 = parent_size + v4;
    if ( v6 )
      v11 = (v11 + 3) & 0xFFFFFFFC;
    v12 = v11 + 4 * v6;
    if ( v5 )
      v12 = (v12 + 7) & 0xFFFFFFF8;
    v13 = v12 + 8 * v5;
    if ( v7 )
      v13 = (v13 + 15) & 0xFFFFFFF0;
    v14 = this->FirstOwnSlotInd.Index;
    this->MemSize = v13 + 16 * v7;
    if ( v14 < size )
    {
      parent_sizea = parent_size << 10;
      v15 = v13 << 10;
      v16 = v11 << 10;
      v20 = v12 << 10;
      do
      {
        v17 = &this->VArray.Data.Data[v14 - this->FirstOwnSlotNum].Value;
        v18 = *(_DWORD *)v17;
        if ( (*(_DWORD *)v17 & 0x10) == 0 )
        {
          switch ( v18 << 22 >> 27 )
          {
            case 2:
              v19 = v18 ^ (v18 ^ v15) & 0x7FFFC00;
              v15 += 0x4000;
              goto LABEL_29;
            case 3:
            case 6:
            case 7:
            case 9:
              v19 = v18 ^ (v18 ^ v16) & 0x7FFFC00;
              v16 += 4096;
              goto LABEL_29;
            case 5:
              v19 = v18 ^ (v18 ^ parent_sizea) & 0x7FFFC00;
              parent_sizea += 1024;
              goto LABEL_29;
            case 8:
              v19 = v18 ^ (v18 ^ v20) & 0x7FFFC00;
              v20 += 0x2000;
LABEL_29:
              *(_DWORD *)v17 = v19;
              break;
            default:
              break;
          }
        }
        ++v14;
      }
      while ( v14 < size );
    }
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, 0);
}
