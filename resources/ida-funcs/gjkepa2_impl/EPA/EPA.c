void __thiscall gjkepa2_impl::EPA::EPA(gjkepa2_impl::EPA *this, int a2)
{
  gjkepa2_impl::EPA::sFace *v2; // esi
  int v3; // edi

  *(_DWORD *)(a2 + 10324) = 0;
  *(_DWORD *)(a2 + 10328) = 0;
  *(_DWORD *)(a2 + 10332) = 0;
  *(_DWORD *)(a2 + 10336) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = 0;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)a2 = 9;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 10320) = 0;
  v2 = (gjkepa2_impl::EPA::sFace *)(a2 + 10256);
  v3 = 128;
  do
  {
    gjkepa2_impl::EPA::append((gjkepa2_impl::EPA::sList *)(a2 + 10332), v2--);
    --v3;
  }
  while ( v3 );
}
