char __thiscall Scaleform::GFx::LoadBinaryTask::GetData(
        Scaleform::GFx::LoadBinaryTask *this,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *data,
        int *fileLen,
        bool *succeeded)
{
  unsigned int Size; // ebx
  unsigned __int8 *v7; // ecx

  if ( this->Done != 1 )
    return 0;
  Size = this->Data.Data.Size;
  if ( Size >= data->Data.Size )
  {
    if ( Size >= data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)data,
        data,
        Size + (Size >> 2));
  }
  else if ( Size < data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)data,
      data,
      Size);
  }
  v7 = data->Data.Data;
  data->Data.Size = Size;
  memcpy(v7, this->Data.Data.Data, this->Data.Data.Size);
  *fileLen = this->FileLen;
  *succeeded = this->Succeeded;
  return 1;
}
