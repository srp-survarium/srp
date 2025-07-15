int __thiscall SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::lower(_DWORD *this, _DWORD *a2)
{
  int v3; // [esp+8h] [ebp-Ch]
  int v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  if ( !this[2] || *a2 < *(_DWORD *)this[1] )
    return this[1] + 4 * this[2];
  v4 = this[2] >> 1;
  v3 = this[1];
  v5 = v3 + 4 * this[2];
  while ( v4 )
  {
    if ( *a2 >= *(_DWORD *)(v3 + 4 * v4) )
      v3 += 4 * v4;
    else
      v5 = v3 + 4 * v4;
    v4 = ((v5 - v3) >> 2) / 2;
  }
  return v3;
}


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


int __thiscall SpeedTree::CArray<SpeedTree::CInstance,1>::lower(_DWORD *this, int a2)
{
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  if ( !this[2] || (unsigned __int8)SpeedTree::CInstance::operator<(this[1]) )
    return this[1] + 36 * this[2];
  v5 = this[2] >> 1;
  v4 = this[1];
  v6 = v4 + 36 * this[2];
  while ( v5 )
  {
    if ( (unsigned __int8)SpeedTree::CInstance::operator<(v4 + 36 * v5) )
      v6 = v4 + 36 * v5;
    else
      v4 += 36 * v5;
    v5 = (v6 - v4) / 36 / 2;
  }
  return v4;
}
