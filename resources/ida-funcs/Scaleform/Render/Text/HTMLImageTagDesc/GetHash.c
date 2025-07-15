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
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  unsigned int v13; // [esp+14h] [ebp-8h]
  int Alignment; // [esp+18h] [ebp-4h]

  VSpace = this->VSpace;
  HSpace = this->HSpace;
  ParaId = this->ParaId;
  v11 = VSpace;
  Alignment = this->Alignment;
  v12 = HSpace;
  v13 = ParaId;
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
