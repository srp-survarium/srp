unsigned int __thiscall Scaleform::Render::Text::HTMLImageTagDesc::GetHash(
        Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  int VSpace; // eax
  int HSpace; // ecx
  unsigned int ParaId; // edx
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  unsigned int v8; // esi
  char v10; // [esp+Bh] [ebp-11h]
  unsigned int v[4]; // [esp+Ch] [ebp-10h]

  VSpace = this->VSpace;
  HSpace = this->HSpace;
  ParaId = this->ParaId;
  v[0] = VSpace;
  v[3] = this->Alignment;
  v[1] = HSpace;
  v[2] = ParaId;
  v5 = 16;
  v6 = 5381;
  do
  {
    v7 = (unsigned __int8)*(&v10 + v5--);
    v6 = v7 + 65599 * v6;
  }
  while ( v5 );
  v8 = v6
     ^ Scaleform::String::BernsteinHashFunctionCIS(
         (char *)((this->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
         *(_DWORD *)(this->Url.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
         0x1505u);
  return v8
       ^ Scaleform::String::BernsteinHashFunctionCIS(
           (char *)((this->Id.HeapTypeBits & 0xFFFFFFFC) + 8),
           *(_DWORD *)(this->Id.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
           0x1505u);
}
