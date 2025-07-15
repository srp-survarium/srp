void __thiscall Scaleform::Render::TextLayout::Builder::AddRefCntData(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::RefCountImpl *p)
{
  unsigned __int8 *v3; // edi
  int v4; // esi
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // ebx
  unsigned int Size; // edx
  unsigned int v7; // eax
  Scaleform::RefCountImpl **Data; // ecx
  char v9[4]; // [esp+10h] [ebp-8h] BYREF
  Scaleform::RefCountImpl *v10; // [esp+14h] [ebp-4h]

  strcpy(v9, "\t");
  v10 = p;
  v3 = (unsigned __int8 *)v9;
  v4 = 8;
  p_Data = &this->Data;
  do
  {
    --v4;
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v3++);
  }
  while ( v4 );
  Size = this->RefCntData.Size;
  v7 = 0;
  if ( Size )
  {
    Data = this->RefCntData.Data;
    while ( p != *Data )
    {
      ++v7;
      ++Data;
      if ( v7 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(&this->RefCntData, &p);
  }
}
