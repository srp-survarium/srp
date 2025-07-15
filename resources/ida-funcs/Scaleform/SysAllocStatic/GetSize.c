unsigned int __thiscall Scaleform::SysAllocStatic::GetSize(Scaleform::SysAllocStatic *this)
{
  signed int NumSegments; // ebp
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // edx
  unsigned int *v6; // eax
  unsigned int v8; // [esp+10h] [ebp-4h]

  NumSegments = this->NumSegments;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v8 = 0;
  if ( NumSegments >= 2 )
  {
    v5 = ((unsigned int)(NumSegments - 2) >> 1) + 1;
    v6 = &this->Segments[1][5];
    v2 = 2 * v5;
    do
    {
      v3 += *(v6 - 8);
      v4 += *v6;
      v6 += 16;
      --v5;
    }
    while ( v5 );
  }
  if ( v2 < NumSegments )
    v8 = this->Segments[v2][5];
  return v8 + v4 + v3;
}
