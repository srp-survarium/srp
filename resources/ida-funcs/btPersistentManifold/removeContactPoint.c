void __thiscall btPersistentManifold::removeContactPoint(btPersistentManifold *this, int index, int a3)
{
  int v3; // eax
  int v4; // eax

  if ( *(_DWORD *)(288 * a3 + index + 124) )
    btPersistentManifold::clearUserCache((btManifoldPoint *)(288 * a3 + index + 16));
  v3 = *(_DWORD *)(index + 1176) - 1;
  if ( a3 != v3 )
  {
    v4 = index + 288 * v3;
    qmemcpy((void *)(288 * a3 + index + 16), (const void *)(v4 + 16), 0x120u);
    *(_DWORD *)(v4 + 124) = 0;
    *(_DWORD *)(v4 + 160) = 0;
    *(_DWORD *)(v4 + 236) = 0;
    *(_DWORD *)(v4 + 268) = 0;
    *(_DWORD *)(v4 + 300) = 0;
    *(_DWORD *)(v4 + 128) = 0;
    *(_BYTE *)(v4 + 132) = 0;
    *(_DWORD *)(v4 + 136) = 0;
    *(_DWORD *)(v4 + 140) = 0;
  }
  --*(_DWORD *)(index + 1176);
}
