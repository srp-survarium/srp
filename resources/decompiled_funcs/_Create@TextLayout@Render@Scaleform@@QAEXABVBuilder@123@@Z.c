void __thiscall Scaleform::Render::TextLayout::Create(
        Scaleform::Render::TextLayout *this,
        const Scaleform::Render::TextLayout::Builder *builder)
{
  unsigned int Size; // edi
  unsigned int v5; // edi
  unsigned int v6; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Data; // esi
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned __int8 *pFonts; // eax
  unsigned __int8 *pImages; // eax
  unsigned __int8 *pRefCntData; // eax
  unsigned int i; // esi
  unsigned int j; // esi
  Scaleform::Render::Image *v15; // ecx
  unsigned int k; // esi
  float x2; // [esp+8h] [ebp-8h]
  float v18; // [esp+8h] [ebp-8h]
  float y2; // [esp+Ch] [ebp-4h]
  float v20; // [esp+Ch] [ebp-4h]
  float totala; // [esp+14h] [ebp+4h]
  float totalb; // [esp+14h] [ebp+4h]
  unsigned int total; // [esp+14h] [ebp+4h]

  this->pFonts = 0;
  this->FontCount = 0;
  this->pImages = 0;
  this->ImageCount = 0;
  this->pRefCntData = 0;
  this->RefCntCount = 0;
  totala = builder->Bounds.y1;
  x2 = builder->Bounds.x2;
  y2 = builder->Bounds.y2;
  this->Bounds.x1 = builder->Bounds.x1;
  this->Bounds.y1 = totala;
  this->Bounds.x2 = x2;
  this->Bounds.y2 = y2;
  totalb = builder->ClipBox.y1;
  v20 = builder->ClipBox.x2;
  v18 = builder->ClipBox.y2;
  this->ClipBox.x1 = builder->ClipBox.x1;
  this->ClipBox.y1 = totalb;
  this->ClipBox.x2 = v20;
  this->ClipBox.y2 = v18;
  qmemcpy(&this->Param, builder, sizeof(this->Param));
  Size = builder->Data.Size;
  this->DataSize = Size;
  v5 = (Size + 3) & 0xFFFFFFFC;
  v6 = v5 + 4 * (builder->RefCntData.Size + builder->Fonts.Size + builder->Images.Size);
  p_Data = &this->Data;
  total = v6;
  if ( v6 >= this->Data.Data.Size )
  {
    if ( v6 < this->Data.Data.Policy.Capacity )
      goto LABEL_7;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      &this->Data,
      v6 + (v6 >> 2));
  }
  else
  {
    if ( v6 >= this->Data.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      &this->Data,
      v6);
  }
  v6 = total;
LABEL_7:
  this->Data.Data.Size = v6;
  if ( builder->Fonts.Size )
  {
    this->pFonts = (Scaleform::Render::Font **)&p_Data->Data.Data[v5];
    v8 = builder->Fonts.Size;
    this->FontCount = v8;
    v5 += 4 * v8;
  }
  if ( builder->Images.Size )
  {
    this->pImages = (Scaleform::Render::Image **)&p_Data->Data.Data[v5];
    v9 = builder->Images.Size;
    this->ImageCount = v9;
    v5 += 4 * v9;
  }
  if ( builder->RefCntData.Size )
  {
    this->pRefCntData = (Scaleform::RefCountImpl **)&p_Data->Data.Data[v5];
    this->RefCntCount = builder->RefCntData.Size;
  }
  if ( builder->Data.Size )
    memcpy(p_Data->Data.Data, builder->Data.Data, this->DataSize);
  pFonts = (unsigned __int8 *)this->pFonts;
  if ( pFonts )
    memcpy(pFonts, (unsigned __int8 *)builder->Fonts.Data, 4 * this->FontCount);
  pImages = (unsigned __int8 *)this->pImages;
  if ( pImages )
    memcpy(pImages, (unsigned __int8 *)builder->Images.Data, 4 * this->ImageCount);
  pRefCntData = (unsigned __int8 *)this->pRefCntData;
  if ( pRefCntData )
    memcpy(pRefCntData, (unsigned __int8 *)builder->RefCntData.Data, 4 * this->RefCntCount);
  for ( i = 0; i < this->FontCount; ++i )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->pFonts[i]);
  for ( j = 0; j < this->ImageCount; ++j )
  {
    v15 = this->pImages[j];
    v15->AddRef(v15);
  }
  for ( k = 0; k < this->RefCntCount; ++k )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this->pRefCntData[k]);
}
