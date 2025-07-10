double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetKerningAdjustment(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  signed int v3; // eax
  int v4; // edx
  unsigned __int8 **Pages; // ebp
  int v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // ecx
  bool v10; // cf
  int beg; // [esp+10h] [ebp-10h]
  int end; // [esp+14h] [ebp-Ch]
  Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *v14; // [esp+18h] [ebp-8h]
  unsigned int KerningTablePos; // [esp+1Ch] [ebp-4h]

  v3 = this->KerningTableSize - 1;
  v4 = 0;
  v14 = this;
  end = v3;
  beg = 0;
  if ( v3 < 0 )
    return 0.0;
  KerningTablePos = this->KerningTablePos;
  Pages = this->Decoder.Data->Pages;
  while ( 1 )
  {
    v6 = (v4 + v3) / 2;
    v7 = KerningTablePos + 6 * v6;
    v8 = this->Decoder.Data->Pages[v7 >> 12][((_WORD)KerningTablePos + 6 * (_WORD)v6) & 0xFFF]
       | (this->Decoder.Data->Pages[(v7 + 1) >> 12][(v7 + 1) & 0xFFF] << 8);
    v9 = Pages[(v7 + 2) >> 12][(v7 + 2) & 0xFFF] | (Pages[(v7 + 3) >> 12][(v7 + 3) & 0xFFF] << 8);
    v10 = lastCode < v8;
    if ( lastCode == v8 )
    {
      v10 = thisCode < v9;
      if ( thisCode == v9 )
        break;
    }
    if ( v10 )
    {
      v4 = beg;
      v3 = v6 - 1;
      end = v3;
    }
    else
    {
      v4 = v6 + 1;
      v3 = end;
      beg = v4;
    }
    if ( v4 > v3 )
      return 0.0;
    this = v14;
  }
  return (double)(__int16)(v14->Decoder.Data->Pages[(v7 + 4) >> 12][(v7 + 4) & 0xFFF]
                         | (v14->Decoder.Data->Pages[(v7 + 5) >> 12][(v7 + 5) & 0xFFF] << 8));
}
