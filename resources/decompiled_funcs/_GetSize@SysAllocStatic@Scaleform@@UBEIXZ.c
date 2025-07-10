unsigned int __thiscall Scaleform::SysAllocStatic::GetSize(Scaleform::SysAllocStatic *this)
{
  signed int NumSegments; // ebp
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // edi
  unsigned int v5; // edx
  unsigned int *v6; // eax
  unsigned int s; // [esp+10h] [ebp-4h]

  NumSegments = this->NumSegments;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  s = 0;
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
    s = this->Segments[v2][5];
  return s + v4 + v3;
}
