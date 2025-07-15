void __thiscall btSoftBody::initializeFaceTree(btSoftBody *this, int a2)
{
  btDbvt *v2; // ecx
  int v3; // esi
  const btSoftBody::Face *v4; // edi
  btDbvtAabbMm *v5; // eax
  btDbvt *v6; // [esp+4h] [ebp-38h]
  int v7; // [esp+18h] [ebp-24h]
  btDbvtAabbMm v8; // [esp+1Ch] [ebp-20h] BYREF

  btDbvt::clear((btDbvt *)this, (btDbvt *)(a2 + 988));
  v3 = 0;
  if ( *(int *)(a2 + 760) > 0 )
  {
    v7 = 0;
    do
    {
      v4 = (const btSoftBody::Face *)(v7 + *(_DWORD *)(a2 + 768));
      v6 = v2;
      v5 = VolumeOf(v4, &v8, 0.0);
      v7 += 64;
      ++v3;
      v4->m_leaf = btDbvt::insert(v6, (btDbvt *)(a2 + 988), v5, (int)v4);
    }
    while ( v3 < *(_DWORD *)(a2 + 760) );
  }
}
