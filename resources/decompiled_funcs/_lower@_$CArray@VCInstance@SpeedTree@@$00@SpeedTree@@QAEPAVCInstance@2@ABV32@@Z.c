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
