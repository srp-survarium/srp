char __thiscall Scaleform::GFx::LoadBinaryTask::GetData(
        Scaleform::GFx::LoadBinaryTask *this,
        Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *data,
        int *fileLen,
        bool *succeeded)
{
  unsigned int Size; // ebx
  char *v7; // ecx

  if ( this->Done != 1 )
    return 0;
  Size = this->Data.Data.Size;
  if ( Size >= data->Size )
  {
    if ( Size >= data->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        data,
        data,
        Size + (Size >> 2));
  }
  else if ( Size < data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      data,
      data,
      Size);
  }
  v7 = data->Data;
  data->Size = Size;
  memcpy((int)v7, (const __m128i *)this->Data.Data.Data, this->Data.Data.Size);
  *fileLen = this->FileLen;
  *succeeded = this->Succeeded;
  return 1;
}
