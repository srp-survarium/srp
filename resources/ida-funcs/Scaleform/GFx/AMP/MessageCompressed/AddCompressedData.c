void __thiscall Scaleform::GFx::AMP::MessageCompressed::AddCompressedData(
        Scaleform::GFx::AMP::MessageCompressed *this,
        unsigned __int8 *data,
        unsigned int dataSize)
{
  unsigned int v3; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_CompressedData; // edi
  unsigned int v5; // esi
  bool *v6; // eax

  v3 = 0;
  if ( dataSize )
  {
    p_CompressedData = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->CompressedData;
    do
    {
      v5 = p_CompressedData->Size + 1;
      if ( v5 >= p_CompressedData->Size )
      {
        if ( v5 >= p_CompressedData->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_CompressedData,
            p_CompressedData,
            v5 + (v5 >> 2));
      }
      else if ( v5 < p_CompressedData->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_CompressedData,
          p_CompressedData,
          p_CompressedData->Size + 1);
      }
      v6 = &p_CompressedData->Data[v5 - 1];
      p_CompressedData->Size = v5;
      if ( v6 )
        *v6 = data[v3];
      ++v3;
    }
    while ( v3 < dataSize );
  }
}
