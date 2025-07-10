void __usercall vostok::render::scene::test_action_portal_system(vostok::render::scene *this@<ecx>, int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 972);
  if ( v2 )
    *(_BYTE *)(v2 + 280) = 1;
}
