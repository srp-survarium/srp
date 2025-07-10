int __thiscall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::lower(_DWORD *this, int a2)
{
  int v3; // [esp+10h] [ebp-Ch]
  int v4; // [esp+14h] [ebp-8h]
  int v5; // [esp+18h] [ebp-4h]

  if ( !this[2] || *(float *)(this[1] + 4) > (double)*(float *)(a2 + 4) )
    return this[1] + 32 * this[2];
  v4 = this[2] >> 1;
  v3 = this[1];
  v5 = v3 + 32 * this[2];
  while ( v4 )
  {
    if ( *(float *)(v3 + 32 * v4 + 4) <= (double)*(float *)(a2 + 4) )
      v3 += 32 * v4;
    else
      v5 = v3 + 32 * v4;
    v4 = ((v5 - v3) >> 5) / 2;
  }
  return v3;
}
