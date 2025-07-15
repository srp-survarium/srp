unsigned int __thiscall Scaleform::Render::Text::TextFormat::HashFunctor::operator()(
        Scaleform::Render::Text::TextFormat::HashFunctor *this,
        const Scaleform::Render::Text::TextFormat *data)
{
  int LetterSpacing; // ecx
  unsigned int ColorV; // esi
  bool v4; // zf
  unsigned __int16 PresentMask; // ax
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // ecx
  int v7; // eax
  int v8; // ebp
  int v9; // ecx
  unsigned int v10; // esi
  char v12; // [esp+7h] [ebp-11h]
  int v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int Hash; // [esp+14h] [ebp-4h]

  LetterSpacing = 0;
  ColorV = 0;
  v4 = (data->PresentMask & 1) == 0;
  v15 = 0;
  Hash = 0;
  if ( !v4 || (data->PresentMask & 0x400) != 0 )
    ColorV = data->ColorV;
  PresentMask = data->PresentMask;
  if ( (PresentMask & 2) != 0 )
    LetterSpacing = data->LetterSpacing;
  if ( (PresentMask & 8) != 0 )
    LetterSpacing |= data->FontSize << 16;
  v4 = data->pFontHandle.pObject == 0;
  v13 = (data->FormatFlags << 24) | ColorV;
  v14 = (PresentMask << 24) | LetterSpacing;
  if ( !v4 )
    v15 = 1;
  if ( (PresentMask & 0x200) != 0 )
  {
    pObject = data->pImageDesc.pObject;
    if ( pObject )
      Hash = Scaleform::Render::Text::HTMLImageTagDesc::GetHash(pObject);
  }
  v7 = 16;
  v8 = 5381;
  do
  {
    v9 = (unsigned __int8)*(&v12 + v7--);
    v8 = v9 + 65599 * v8;
  }
  while ( v7 );
  v10 = v8;
  if ( (data->PresentMask & 4) != 0 )
    v10 = v8
        ^ Scaleform::String::BernsteinHashFunctionCIS(
            (char *)((data->FontList.HeapTypeBits & 0xFFFFFFFC) + 8),
            *(_DWORD *)(data->FontList.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
            0x1505u);
  if ( (data->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&data->Url) )
    v10 ^= Scaleform::String::BernsteinHashFunctionCIS(
             (char *)((data->Url.HeapTypeBits & 0xFFFFFFFC) + 8),
             *(_DWORD *)(data->Url.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
             0x1505u);
  return v10;
}
