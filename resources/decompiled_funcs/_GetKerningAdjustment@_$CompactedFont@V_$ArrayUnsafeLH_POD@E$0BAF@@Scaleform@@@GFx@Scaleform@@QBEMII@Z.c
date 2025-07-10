double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetKerningAdjustment(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int lastCode,
        unsigned int thisCode)
{
  signed int v3; // ebp
  signed int v4; // eax
  unsigned __int8 *Data; // ebx
  int v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // esi
  bool v10; // cf
  int beg; // [esp+8h] [ebp-Ch]
  Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *v13; // [esp+Ch] [ebp-8h]
  unsigned int KerningTablePos; // [esp+10h] [ebp-4h]

  v3 = this->KerningTableSize - 1;
  v4 = 0;
  v13 = this;
  beg = 0;
  if ( v3 < 0 )
    return 0.0;
  KerningTablePos = this->KerningTablePos;
  Data = this->Decoder.Data->Data;
  while ( 1 )
  {
    v6 = (v3 + v4) / 2;
    v7 = KerningTablePos + 6 * v6;
    v8 = *(unsigned __int16 *)&this->Decoder.Data->Data[v7];
    v9 = *(unsigned __int16 *)&Data[v7 + 2];
    v10 = lastCode < v8;
    if ( lastCode == v8 )
    {
      v10 = thisCode < v9;
      if ( thisCode == v9 )
        break;
    }
    if ( v10 )
    {
      v3 = v6 - 1;
      v4 = beg;
    }
    else
    {
      v4 = v6 + 1;
      beg = v4;
    }
    if ( v4 > v3 )
      return 0.0;
    this = v13;
  }
  return (double)*(__int16 *)&v13->Decoder.Data->Data[v7 + 4];
}
