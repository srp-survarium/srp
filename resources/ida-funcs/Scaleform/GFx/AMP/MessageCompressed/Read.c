void __thiscall Scaleform::GFx::AMP::MessageCompressed::Read(
        Scaleform::GFx::AMP::MessageCompressed *this,
        unsigned int str)
{
  unsigned int v2; // ebp
  void (__thiscall *v4)(unsigned int, unsigned int *, int); // edx
  unsigned int v5; // esi
  unsigned int Size; // eax
  unsigned int v7; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_CompressedData; // edi
  void (__thiscall *v9)(unsigned int, unsigned int *, int); // edx

  v2 = str;
  Scaleform::GFx::AMP::Message::Read(this, (Scaleform::String)str);
  v4 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v2 + 40);
  v5 = 0;
  str = 0;
  v4(v2, &str, 4);
  Size = this->CompressedData.Data.Size;
  v7 = str;
  p_CompressedData = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->CompressedData;
  if ( str >= Size )
  {
    if ( str >= p_CompressedData->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_CompressedData,
        p_CompressedData,
        str + (str >> 2));
  }
  else if ( str < p_CompressedData->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_CompressedData,
      p_CompressedData,
      str);
  }
  p_CompressedData->Size = v7;
  if ( v7 )
  {
    do
    {
      v9 = *(void (__thiscall **)(unsigned int, unsigned int *, int))(*(_DWORD *)v2 + 40);
      LOBYTE(str) = 0;
      v9(v2, &str, 1);
      p_CompressedData->Data[v5++] = str;
    }
    while ( v5 < v7 );
  }
}
